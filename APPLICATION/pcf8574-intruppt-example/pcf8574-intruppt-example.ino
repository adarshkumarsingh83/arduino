#include <Wire.h>

int address = 0x20;   

#define INTERRUPTED_PIN 2

bool irActive = false;

// Function interrupt
void infraRedActive();


void setup() {
  Serial.begin(9600);
  // Set pinMode to OUTPUT
  Wire.begin();            
  
  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(address);
  Wire.write(0xFF);
  Wire.endTransmission();

  pinMode(INTERRUPTED_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPTED_PIN), infraRedActive, CHANGE);
}

void loop() {

  if (irActive) {
    int input = readInput(address);
    Serial.print("READ VALUE FROM PCF ");
    Serial.println(input);
    Wire.beginTransmission(address);
    Wire.write(253);
    Wire.endTransmission();
    delay(1000); 
    irActive = false;
  } else {  
    Serial.println();
    Wire.beginTransmission(address);
    Wire.write(255);
    Wire.endTransmission();
    delay(1000);
    Wire.beginTransmission(address);
    Wire.write(254);
    Wire.endTransmission();
    delay(1000);
  }
}

byte readInput(int address){
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 3);
  int Data_In = Wire.read();
  Wire.endTransmission();
  return Data_In;
}

void infraRedActive() {
  /*
    Interrupt called (No Serial no read no wire in this
    function, and DEBUG disabled on PCF library)
  */
  irActive = true;
}
