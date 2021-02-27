#include <ESP8266WiFi.h>
#include <espnow.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "CircularQueue.h"

#define NODE_NAME 1
#define GREEN_PIN 5

const byte numChars = 64;
const  char startMarker = '{';
const  char endMarker = '}';
const char LED_TYPE = 'L'; // 76  L
const long interval = 1500;

int id;
char type;
int pin;
boolean state;
bool sendData = false;
bool redState = true;
bool greenState = false;
String serialData = "";
unsigned long previousMillis = 0;
char receivedChars[numChars];

typedef struct Notification {
  int id;
  char type;
  int pin;
  boolean state;
} Notification;

Notification sendNotification1;
Notification sendNotification2;
Notification recieveNotification;
Notification recieveNotificationProcess;

SoftwareSerial softwareSerial(3, 1); // (Rx, Tx)
CircularQueue<Notification> dataQueue = CircularQueue<Notification>(20);
CircularQueue<String> dataResponseQueue = CircularQueue<String>(20);

// REPLACE WITH THE MAC Address of your receiver
uint8_t broadcastAddress[2][6] = {{0x84, 0xCC, 0xA8, 0xB1, 0x5B, 0xFB}, {0x84, 0xCC, 0xA8, 0xB1, 0x42, 0x6C}};

// Callback when data is sent
void onDataSend(uint8_t *mac_addr, uint8_t sendStatus) {
  /*
    char macStr[18];
    Serial.print(" Packet to:");
    snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.print(macStr);
    Serial.print(" Last Packet Send Status: ");
  */
  if (sendStatus == 0) {
    // Serial.println(" Delivery success");
  } else {
    // Serial.println(" Delivery fail");
  }

}

// Callback when data is received
void onDataRecieve(uint8_t * mac_addr, uint8_t *incomingData, uint8_t len) {
  /*
    char macStr[18];
    Serial.print(" Packet received from: ");
    snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
    mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.println(macStr);
  */
  memcpy(&recieveNotification, incomingData, sizeof(recieveNotification));
  // Serial.print(" Bytes received: ");
  // Serial.println(len);

  if (recieveNotification.type == LED_TYPE) {
    if (recieveNotification.id == 2 || recieveNotification.id == 3) {
      dataQueue.push(recieveNotification);
    } else {
      // Serial.print(" INVALID SENDER FOR NODE1 => ");
      // Serial.println(recieveNotification.id);
    }
  } else {
    // Serial.print(" INVALID TYPE FOR NODE1 => ");
    // Serial.println(recieveNotification.type);
  }
}


void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
  softwareSerial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);


  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() == 0) {
    //Serial.println("ESPNow Init Success");
  } else {
    // Serial.println("ESPNow Init Failed");
    ESP.restart();
  }

  // Set ESP-NOW Role
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(onDataSend);

  // Register peer
  esp_now_add_peer(broadcastAddress[0], ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  esp_now_add_peer(broadcastAddress[1], ESP_NOW_ROLE_COMBO, 1, NULL, 0);

  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(onDataRecieve);
}

void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    sendData = true;
    previousMillis = currentMillis;
  } else {
    sendData = false;
  }

  if (sendData) {
    if (greenState) {
      digitalWrite(GREEN_PIN, HIGH);
      greenState = false;
    } else {
      digitalWrite(GREEN_PIN, LOW);
      greenState = true;
    }

    // sending data
    if (redState) {

      sendNotification1.id = NODE_NAME;
      sendNotification1.type = LED_TYPE;
      sendNotification1.pin = 5;
      sendNotification1.state = true;

      sendNotification2.id = NODE_NAME;
      sendNotification2.type = LED_TYPE;
      sendNotification2.pin = 4;
      sendNotification2.state = true;

      redState = false;
    } else {
      sendNotification1.id = NODE_NAME;
      sendNotification1.type = LED_TYPE;
      sendNotification1.pin = 5;
      sendNotification1.state = false;

      sendNotification2.id = NODE_NAME;
      sendNotification2.type = LED_TYPE;
      sendNotification2.pin = 4;
      sendNotification2.state = false;
      
      redState = true;
    }

    esp_now_send(broadcastAddress[0], (uint8_t *) &sendNotification1, sizeof(sendNotification1)); // node 2 0xFB
    esp_now_send(broadcastAddress[1], (uint8_t *) &sendNotification2, sizeof(sendNotification2)); // node 3 0x6C

  } else {

    if (!dataQueue.isEmpty()) {
      recieveNotificationProcess = dataQueue.pop();
      // id = recieveNotificationProcess.id;
      type = recieveNotificationProcess.type;
      pin = recieveNotificationProcess.pin;
      state = recieveNotificationProcess.state;
      // displayData(id, type, pin, state);
      DynamicJsonDocument jsonDocument(128);
      jsonDocument["type"] = type;
      jsonDocument["pin"] = pin;
      jsonDocument["state"] = state;
      serializeJson(jsonDocument, softwareSerial);
      softwareSerial.println();
    }

    // recieving data
    while (softwareSerial.available()) {
      recivedSerialJsonData();
    }

    if (!dataResponseQueue.isEmpty()) {
      serialData = dataResponseQueue.pop();
      DynamicJsonDocument jsonDocument(128);
      DeserializationError error = deserializeJson(jsonDocument, serialData);
      if (error) {
        //Serial.print(F("ESP deserializeJson() failed: "));
        //Serial.println(error.c_str());
        return;
      }
      String type = jsonDocument["type"];
      String pin = jsonDocument["pin"];
      String state = jsonDocument["state"];
      String opStatus = jsonDocument["opStatus"];
      String output = "Uno Response = { 'type': '" + type + "','pin':'" + pin + "','state':'" + state + "','status':'" + opStatus + "'}";
      //Serial.println(output);
    }
  }
}

void recivedSerialJsonData() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;
  String data;
  while (softwareSerial.available() > 0) {
    rc = softwareSerial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      } else {
        receivedChars[ndx] = '}';
        ndx++;
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        dataResponseQueue.push(receivedChars);
        for (int i = 0; i < numChars; i++) {
          receivedChars[i] = ' ';
        }
      }
    } else if (rc == startMarker) {
      receivedChars[ndx] = '{';
      ndx++;
      recvInProgress = true;
    }
  }
}


/*
  void displayData(int id, char type, int pin, boolean state) {
  Serial.println();
  Serial.print("DATA RECIEVED  ::=>");
  Serial.print(id);
  Serial.print("  ");
  Serial.print(type);
  Serial.print(" ");
  Serial.print(pin);
  Serial.print(" ");
  Serial.print(state);
  Serial.println();
  }
*/
