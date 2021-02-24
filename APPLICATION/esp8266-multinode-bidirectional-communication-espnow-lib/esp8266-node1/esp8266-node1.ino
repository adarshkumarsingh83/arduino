#include <ESP8266WiFi.h>
#include <espnow.h>

#define NODE_NAME 1
#define LED_TYPE 'L'

// REPLACE WITH THE MAC Address of your receiver
uint8_t broadcastAddress[2][6] = {{0x84, 0xCC, 0xA8, 0xB1, 0x5B, 0xFB}, {0x84, 0xCC, 0xA8, 0xB1, 0x42, 0x6C}};

const long interval = 1000;
unsigned long previousMillis = 0;
bool redState1 = true;
bool redState2 = true;
bool greenState = false;

typedef struct Notification {
  int id;
  char type;
  int pin;
  boolean state;
} Notification;

Notification sendNotification1;
Notification sendNotification2;
Notification recieveNotification;

int id;
char type;
int pin;
boolean state;

// Callback when data is sent
void onDataSend(uint8_t *mac_addr, uint8_t sendStatus) {
  char macStr[18];
  Serial.print(" Packet to:");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" Last Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println(" Delivery success");
  }
  else {
    Serial.println(" Delivery fail");
  }
}

// Callback when data is received
void onDataRecieve(uint8_t * mac_addr, uint8_t *incomingData, uint8_t len) {
  char macStr[18];
  Serial.print(" Packet received from: ");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.println(macStr);
  memcpy(&recieveNotification, incomingData, sizeof(recieveNotification));
  Serial.print(" Bytes received: ");
  Serial.println(len);
  id = recieveNotification.id;
  type = recieveNotification.type;
  pin = recieveNotification.pin;
  state = recieveNotification.state;
  displayData(id, type, pin, state);
  if (type == LED_TYPE) {
    if (id == 2) {
      if (state) {
        digitalWrite(pin, HIGH);
      } else {
        digitalWrite(pin, LOW);
      }
    } else if (id == 3) {
      if (state) {
        digitalWrite(pin, HIGH);
      } else {
        digitalWrite(pin, LOW);
      }
    } else {
      Serial.print(" INVALID SENDER FOR NODE1 => ");
      Serial.println(id);
    }
  }
}


void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() == 0) {
    Serial.println("ESPNow Init Success");
  } else {
    Serial.println("ESPNow Init Failed");
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
    previousMillis = currentMillis;

    if (redState1) {
      sendNotification1.id = NODE_NAME;
      sendNotification1.type = LED_TYPE;
      sendNotification1.pin = 4;
      sendNotification1.state = true;
      redState1 = false;
    } else {
      sendNotification1.id = NODE_NAME;
      sendNotification1.type = LED_TYPE;
      sendNotification1.pin = 4;
      sendNotification1.state = false;
      redState1 = true;
    }

    if (redState2) {
      sendNotification2.id = NODE_NAME;
      sendNotification2.type = LED_TYPE;
      sendNotification2.pin = 5;
      sendNotification2.state = true;
      redState2 = false;
    } else {
      sendNotification2.id = NODE_NAME;
      sendNotification2.type = LED_TYPE;
      sendNotification2.pin = 5;
      sendNotification2.state = false;
      redState2 = true;
    }

    if (greenState) {
      digitalWrite(3, HIGH);
      greenState = false;
    } else {
      digitalWrite(3, LOW);
      greenState = true;
    }

    // Send message via ESP-NOW
    esp_now_send(broadcastAddress[0], (uint8_t *) &sendNotification1, sizeof(sendNotification1));
    esp_now_send(broadcastAddress[1], (uint8_t *) &sendNotification2, sizeof(sendNotification2));
  }
}

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
