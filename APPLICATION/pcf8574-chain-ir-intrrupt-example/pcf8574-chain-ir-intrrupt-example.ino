#include <Wire.h>

// Function interrupt
void infraRedActive();

int i = 0;
int input = -1;
int address  = -1;
bool irActive = false;
const byte INTERRUPTED_PIN = 2;
int boardAddress [] = {0x20, 0x21};    // PCF8574 board1 - 0x20,   board2  - 0x21 ... board8 0x27
int boardsCount = sizeof(boardAddress) / sizeof(int);    // calculating counts of the boards


void setup() {

  Serial.begin(9600);

  /// Set pinMode to OUTPUT
  Wire.begin();

  for (i = 0; i < boardsCount; i++) {
    // Turn off all GPIO pins on both I2C expanders by writing all "1"
    Wire.beginTransmission(boardAddress[i]);
    Wire.write(0xFF);
    Wire.endTransmission();
  }

  pinMode(INTERRUPTED_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPTED_PIN), infraRedActive, CHANGE);
}

void loop() {

  if (irActive == true) {
    for (i = 0; i < boardsCount; i++) {
      address = boardAddress[i];
      performIntrruptAction(address, 6, 7);
      Wire.beginTransmission(address);
      Wire.write(253);
      Wire.endTransmission();
      delay(1000);
      Wire.beginTransmission(address);
      Wire.write(254);
      Wire.endTransmission();
    }
    irActive = false;
  }

}

void performIntrruptAction(int address, int pin1, int pin2 ) {
  Serial.println(address);
  input = readInput(address, pin1);
  if (input != 254) {
    Serial.print("PIN 6 ");
    Serial.println(input);
  }
  input = -1;

  input = readInput(address, pin2);
  if (input != -254) {
    Serial.print("PIN 7 ");
    Serial.println(input);
  }
}

// input pins are p6 and p7 on PCF8574
byte readInput(int address, int pin ) {
  Wire.beginTransmission(address);
  Wire.requestFrom(address, pin );
  int Data_In = Wire.read();
  Wire.endTransmission();
  return Data_In;
}

void infraRedActive() {
  //Serial.println("*");
  irActive = true;
}
