#include <Wire.h>

int address = 0x20;          // PCF8574 device 1
int LED_Pattern_ON = 0x00;  // LED Sequence Start pattern, one LED on .   =>  0b0000000000000000
int LED_Pattern_OFF = 0xFFFF;  // LED Sequence Start pattern, one LED off =>  0b1111111111111111
int sum = 0 ;
void setup() {
  // I2C init
  Wire.begin();

  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(address);
  Wire.write(0xFF);
  Wire.endTransmission();

  pinMode(2, INPUT_PULLUP);
}

void loop() {

  lightOperation( true, false, false, true, false, false);
   delay(1000);
   lightOperation( false, true, false, false, true, false);
   delay(1000);
   lightOperation( false, false, true, false, false, true);
   delay(1000);
}


/*
  postions 7 6 5 4 3 2 1 0
  value    1 1 1 1 1 1 1 1   off
  value    0 0 0 0 0 0 0 0   on

  led pin on the pcf8574

       p0 green_1
       p1 yellow_1
       p2 red_1
       p3 green_1
       p4 yellow_1
       p5 red_1
*/

void lightOperation( bool green1, bool yellow1, bool red1,  bool green2, bool yellow2, bool red2) {

  if (red2) {
    sum += 32;
  }
  if (yellow2 ) {
    sum += 16;
  }

  if (green2) {
    sum += 8;
  }

  if (red1) {
    sum += 4;
  }

  if (yellow1) {
    sum += 2;
  }

  if ( green1) {
    sum += 1;
  }

  Wire.beginTransmission(address);
  Wire.write(sum);
  Wire.endTransmission();
  sum = 0 ;
}
