#include <Wire.h>

// Function interrupt
void infraRedActive();

int input = -1;
bool irActive = false;
const int address = 0x20;
const byte INTERRUPTED_PIN = 2;

void setup() {

  Serial.begin(9600);

  /// Set pinMode to OUTPUT
  Wire.begin();

  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(address);
  Wire.write(0xFF);
  Wire.endTransmission();

  pinMode(INTERRUPTED_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPTED_PIN), infraRedActive, CHANGE);
}

void loop() {

  if (irActive == true) {
    input = readInput(address, 6);
    if (input != -1) {
      Serial.print("READ VALUE FROM PCF 6 ");
      Serial.println(input);
    }
    input = -1;

    input = readInput(address, 7);
    if (input != -1) {
      Serial.print("READ VALUE FROM PCF 7 ");
      Serial.println(input);
    }
    
    Wire.beginTransmission(address);
    Wire.write(253);
    Wire.endTransmission();
    delay(1000);
    Wire.beginTransmission(address);
    Wire.write(254);
    Wire.endTransmission();
    irActive = false;
  }

}
// input pins are 6 and 7 on PCF8574
byte readInput(int address, int pin ) {
  Wire.beginTransmission(address);
  Wire.requestFrom(address, pin );
  int Data_In = Wire.read();
  Wire.endTransmission();
  return Data_In;
}

void infraRedActive() {
  // Serial.println("*");
  irActive = true;
}
