#include <Wire.h>

// Function interrupt
void infraRedActive();

int input = -1;
bool irActive = false;
const int address = 0x20;

void setup() {

  /// Set pinMode to OUTPUT
  Wire.begin();

  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(address);
  Wire.write(0xFF);
  Wire.endTransmission();
}

void loop() {

  Wire.beginTransmission(address);
  Wire.write(255);
  Wire.endTransmission();
  delay(10000);
  Wire.beginTransmission(address);
  Wire.write(0);
  Wire.endTransmission();
  delay(10000);
}
