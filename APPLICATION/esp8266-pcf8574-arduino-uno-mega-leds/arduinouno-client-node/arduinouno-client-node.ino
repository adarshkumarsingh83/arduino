#include <ArduinoJson.h>
#include <Wire.h>

// Max 8 board can be chain into this starting fromn 0x20 to 0x27 which will give 64 extra output pin
int boardAddress [] = {0x20, 0x21};     // PCF8574 board1 - 0x20,   board2  - 0x21 ... board8 0x27
const int boardsCount = sizeof(boardAddress) / sizeof(int);    // calculating counts of the boards
bool ledState [boardsCount][8];

int i = 0;
int sum = 0;
String message = "";
bool requestReady = false;
String response = "";

void setup() {
  // I2C init
  Wire.begin();

  Serial.begin(9600);
  for (i = 0; i < boardsCount; i++) {
    // Turn off all GPIO pins on both I2C expanders by writing all "1"
    Wire.beginTransmission(boardAddress[i]);
    Wire.write(0xFF);
    Wire.endTransmission();
    for (int j = 0; j < 8; j++) {
      ledState[i][j] = false;
    }
  }
}

void loop() {

  // Monitor serial communication
  while (Serial.available()) {
    message = Serial.readString();
    requestReady = true;
  }

  // Only process message if there's one
  if (requestReady) {
    // The only messages we'll parse will be formatted in JSON
    DynamicJsonDocument doc(128); // ArduinoJson version 6+
    // Attempt to deserialize the message
    DeserializationError error = deserializeJson(doc, message);
    if (error) {
      Serial.print(F("Uno deserializeJson() failed: "));
      Serial.println(error.c_str());
      requestReady = false;
      return;
    }

    if (doc["type"] == "led") {
      int ledNo = doc["ledNo"];
      String state = doc["state"];
      int board = (ledNo / 8);
      if ( board <= boardsCount && ledNo <= (boardsCount * 8)) {
        int totalPins = (board * 8);
        int pin = (ledNo - totalPins) - 1;
        if (state == "on") {
          ledState[board][pin] = true;
          response = "on";
        } else {
          ledState[board][pin] = false;
          response = "off";
        }

        pin = (pin == -1)  ? 7 : pin;
        Serial.println();
        Serial.print("LED-NO ");
        Serial.println(ledNo);
        Serial.print("BOARD ");
        Serial.println(board);
        Serial.print("PIN ");
        Serial.println(pin);

        // perform the led operation
        ledOperation(board);

        doc["board"] = board;
        doc["pin"] = pin;
        doc["opStatus"] = response;
        serializeJson(doc, Serial);
      } else {
        doc["opStatus"] = "invlaid request";
        serializeJson(doc, Serial);
      }

    }
    response = "not processed";
    requestReady = false;
  }
}

void ledOperation(int boardNo) {

  if (!ledState[boardNo][7]) {
    sum += 128;
  }

  if (!ledState[boardNo][6]) {
    sum += 64;
  }

  if (!ledState[boardNo][5]) {
    sum += 32;
  }

  if (!ledState[boardNo][4]) {
    sum += 16;
  }

  if (!ledState[boardNo][3]) {
    sum += 8;
  }

  if (!ledState[boardNo][2]) {
    sum += 4;
  }

  if (!ledState[boardNo][1]) {
    sum += 2;
  }

  if (!ledState[boardNo][0]) {
    sum += 1;
  }

  // Send the LSB 8 bits of LED_Pattern out to device 1
  Wire.beginTransmission(boardAddress[boardNo]);
  Wire.write(sum);
  Wire.endTransmission();

  Serial.print("SUM IN BINARY ");
  Serial.println(sum , BIN);
  Serial.print("SUM ");
  Serial.println(sum);
  for (i = 0; i < boardsCount; i++) {
    Serial.println(" ");
    for (int j = 7; j >= 0; j--) {
      Serial.print(ledState[i][j]);
      Serial.print(" ");
    }
  }
  sum = 0 ;
}
