#include <ArduinoJson.h>
#include <Wire.h>

// Max 8 board can be chain into this starting fromn 0x20 to 0x27 which will give 64 extra output pin
int boardAddress [] = {0x20, 0x21, 0x22};      // PCF8574 board1 - 0x20,   board2  - 0x21 ... board8 0x27
const int boardsCount = sizeof(boardAddress) / sizeof(int);    // calculating counts of the boards
bool ledState [boardsCount][8];

int i = 0;
int sum = 0;
String message = "";
bool requestReady = false;
String response = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
    // I2C init
  Wire.begin();
  
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
  while (Serial1.available()) {
    message = Serial1.readString();
    requestReady = true;
  }

  // Only process message if there's one
  if (requestReady) {
    // The only messages we'll parse will be formatted in JSON
    DynamicJsonDocument doc(256); // ArduinoJson version 6+
    // Attempt to deserialize the message
    DeserializationError error = deserializeJson(doc, message);
    if (error) {
      Serial.print(F("Mega deserializeJson() failed: "));
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
        Serial.println();
        Serial.print("LED-NO ");
        Serial.println(ledNo);
        Serial.print("BOARD ");
        Serial.println(board);
        Serial.print("PIN ");
        Serial.println(pin);
        sum = 0;
        // perform the led operation
        ledOperation(sum, board);
        doc["board"] = board;
        doc["pin"] = (pin == -1)  ? 7 : pin;
        doc["opStatus"] = response;
      } else {
        doc["opStatus"] = "invlaid request";;
      }
      serializeJson(doc, Serial1);
    }
    response = "not processed";
    requestReady = false;
  }
}

void ledOperation(int sum, int boardNo) {

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
