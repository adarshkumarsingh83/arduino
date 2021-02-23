#include <ArduinoJson.h>

String message = "";
bool messageReady = false;
#define LED_13 13
#define LED_12 12

void setup() {
  Serial.begin(9600);
  pinMode(LED_12, OUTPUT);
  pinMode(LED_13, OUTPUT);
}

void loop() {

  // Monitor serial communication
  while (Serial.available()) {
    message = Serial.readString();
    messageReady = true;
  }

  // Only process message if there's one
  if (messageReady) {
    // The only messages we'll parse will be formatted in JSON
    DynamicJsonDocument doc(1024); // ArduinoJson version 6+
    // Attempt to deserialize the message
    DeserializationError error = deserializeJson(doc, message);
    if (error) {
      Serial.print(F("Uno deserializeJson() failed: "));
      Serial.println(error.c_str());
      messageReady = false;
      return;
    }

    if (doc["type"] == "led") {
      int pin = doc["pin"];
      String state = doc["state"];
      // perform the led operation
      String response = ledOperation(pin, state);
      doc["opStatus"] = response;
      serializeJson(doc, Serial);
    }
    messageReady = false;
  }
}

String ledOperation(int pin, String state) {
  String response;
  if (state == "on") {
    digitalWrite(pin, HIGH);
    response = "ON";
  } else {
    digitalWrite(pin, LOW);
    response = "OFF";
  }
  return response;
}
