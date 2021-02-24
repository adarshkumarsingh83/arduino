#include <ESP8266WiFi.h>
#include <espnow.h>

// REPLACE WITH THE MAC Address of your receiver
uint8_t broadcastAddress[] = {0x84,0x0D,0x8E,0x85,0xF8,0x1D};

const long interval = 1000;
unsigned long previousMillis = 0;
bool redState = false;
bool greenState = false;

//Structure example to send data
//Must match the receiver structure
typedef struct Notification {
  char* type;
  int pin;
  boolean state;
} Notification;

Notification sendNotification;
Notification recieveNotification;

char* type;
int pin;
boolean state;

// Callback when data is sent
void onDataSend(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  }
  else {
    Serial.println("Delivery fail");
  }
}

// Callback when data is received
void onDataRecieve(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&recieveNotification, incomingData, sizeof(recieveNotification));
  Serial.print("Bytes received: ");
  Serial.println(len);
  type = recieveNotification.type;
  pin = recieveNotification.pin;
  state = recieveNotification.state;
  if (type == "led") {
    if (state) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }
}


void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

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
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);

  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(onDataRecieve);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (redState) {
      sendNotification.type = "led";
      sendNotification.pin = 5;
      sendNotification.state = true;
      redState = false;
    } else {
      sendNotification.type = "led";
      sendNotification.pin = 5;
      sendNotification.state = false;
      redState = true;
    }

    if (greenState) {
      digitalWrite(4, HIGH);
      greenState = false;
    } else {
      digitalWrite(4, LOW);
      greenState = true;
    }

    // Send message via ESP-NOW
    esp_now_send(broadcastAddress, (uint8_t *) &sendNotification, sizeof(sendNotification));
  }
}
