#include <Wire.h>

int addr1 = 0x20;          // PCF8574 device 1
int addr2 = 0x21;          // PCF8574 device 2
int LED_Pattern_ON = 0x00;  // LED Sequence Start pattern, one LED on .   =>  0b0000000000000000 
int LED_Pattern_OFF = 0xFFFF;  // LED Sequence Start pattern, one LED off =>  0b1111111111111111

void setup() {
  // I2C init
  Wire.begin();

  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(addr1);
  Wire.write(0xFF);
  Wire.endTransmission();

  Wire.beginTransmission(addr2);
  Wire.write(0xFF);
  Wire.endTransmission();

  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  
    // Send the LSB 8 bits of LED_Pattern out to device 1
    Wire.beginTransmission(addr1);
    Wire.write(lowByte(LED_Pattern_OFF));
    Wire.endTransmission();

    // Send the MSB 8 bits of LED_Pattern out to device 2
    Wire.beginTransmission(addr2);
    Wire.write(lowByte(LED_Pattern_OFF));
    Wire.endTransmission();

    delay(1000);    
    
        // Send the LSB 8 bits of LED_Pattern out to device 1
    Wire.beginTransmission(addr1);
    Wire.write(highByte(LED_Pattern_ON));
    Wire.endTransmission();

    // Send the MSB 8 bits of LED_Pattern out to device 2
    Wire.beginTransmission(addr2);
    Wire.write(highByte(LED_Pattern_ON));
    Wire.endTransmission();

    delay(1000);    
    
  
}
