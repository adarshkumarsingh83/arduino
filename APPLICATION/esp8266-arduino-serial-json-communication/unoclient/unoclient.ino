#include <ArduinoJson.h>

#define LED_5 5
#define LED_4 4

String message = "";
bool messageReady = false;
const char LED_TYPE = 'L';

void setup() {
  Serial.begin(9600);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
   delay(1000);
   Serial.println(" ");
  // Monitor serial communication
  while (Serial.available()) {
    message = Serial.readString();
    //Serial.println(message);
    messageReady = true;
  }

  // Only process message if there's one
  if (messageReady) {
    // The only messages we'll parse will be formatted in JSON
    DynamicJsonDocument jsonDocument(128); // ArduinoJson version 6+
    // Attempt to deserialize the message
    DeserializationError error = deserializeJson(jsonDocument, message);
    if (error) {
      //Serial.print(F("Uno deserializeJson() failed: "));
      //Serial.println(error.c_str());
      messageReady = false;
      message = "";
      return;
    }

    if ( jsonDocument["type"] == LED_TYPE) {
      int pin = jsonDocument["pin"];
      boolean state = jsonDocument["state"];
      // perform the led operation
      String response = ledOperation(pin, state);
      jsonDocument["opStatus"] = response;
      serializeJson(jsonDocument, Serial);
      Serial.flush();
      message = "";
    }
    messageReady = false;
  }
}

String ledOperation(int pin, boolean state) {
  String response;
  if (state) {
    digitalWrite(pin, HIGH);
    response = "ON";
  } else {
    digitalWrite(pin, LOW);
    response = "OFF";
  }
  return response;
}
