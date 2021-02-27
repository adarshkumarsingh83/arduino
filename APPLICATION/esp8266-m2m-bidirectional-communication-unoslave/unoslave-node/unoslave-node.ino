#include <ArduinoJson.h>
#include "CircularQueue.h"

#define LED_5 5
#define LED_4 4

const char LED_TYPE = 'L';
const byte numChars = 64;
const  char startMarker = '{';
const  char endMarker = '}';
const long interval = 1000;

String serialData = "";
bool readData = false;
char receivedChars[numChars];
unsigned long previousMillis = 0;
CircularQueue<String> circularQueue = CircularQueue<String>(15);


void setup() {
  Serial.begin(9600);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    readData = false;
  } else {
    readData = true;
  }

  if (readData) {
    // Monitor serial communication
    while (Serial.available()) {
      recivedSerialJsonData();
    }
  } else {
    // Only process serialData if there's one in circular queue
    if (!circularQueue.isEmpty()) {
      // ArduinoJson version 6+
      DynamicJsonDocument jsonDocument(128);
      serialData = circularQueue.pop();

      // Attempt to deserialize the serialData
      DeserializationError error = deserializeJson(jsonDocument, serialData);
      if (error) {
        //Serial.print(F("Uno deserializeJson() failed: "));
        //Serial.println(error.c_str());
        serialData = "";
        return;
      }
      if ( jsonDocument["type"] == LED_TYPE) {
        int pin = jsonDocument["pin"];
        boolean state = jsonDocument["state"];
        // perform the led operation
        String response = ledOperation(pin, state);
        jsonDocument["opStatus"] = response;
        serializeJson(jsonDocument, Serial);
        Serial.println();
        serialData = "";
      }
    }
  }
}

void recivedSerialJsonData() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;
  String data;
  while (Serial.available() > 0) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      } else {
        ndx += 1;
        receivedChars[ndx] = '}';
        ndx++;
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        data = receivedChars;
        circularQueue.push(data);
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
