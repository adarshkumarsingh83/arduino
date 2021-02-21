#include <Wire.h>

int address = 0x20;          // PCF8574 device 1
int LED_Pattern_ON = 0x00;  // LED Sequence Start pattern, one LED on .   =>  0b0000000000000000
int LED_Pattern_OFF = 0xFFFF;  // LED Sequence Start pattern, one LED off =>  0b1111111111111111
int sum = 0 ;
void setup() {
  Serial.begin(9600);

  // I2C init
  Wire.begin();

  // Turn off all GPIO pins on both I2C expanders by writing all "1"
  Wire.beginTransmission(address);
  Wire.write(0xFF);
  Wire.endTransmission();
}

void loop() {

  //red
  lightOperation( true, false, false, true, false, false);
  delay(2000);
  //green
  lightOperation( false, true, false, false, true, false);
  delay(2000);
  //blue
  lightOperation( false, false, true, false, false, true);
  delay(2000);
  //white
  lightOperation( true, true, true, true, true, true);
  delay(2000);
  //purpule
  lightOperation( true, false, true, true, false, true);
  delay(2000);
  //yellow
  lightOperation( false, true, true, false, true, true);
  delay(2000);
  //light crayn
  lightOperation( true, true, false, true, true, false);
  delay(2000);
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

void lightOperation( bool red1, bool green1, bool blue1,
                     bool red2, bool green2, bool blue2) {

  Serial.println(green1);
  Serial.println(blue1);
  Serial.println(red1);

  Serial.println(green2);
  Serial.println(blue2);
  Serial.println(red2);
  Serial.println();

  if (!blue2) {
    sum += 32;
  } else {
    Serial.println("blue2");
  }
  if (!green2) {
    sum += 16;
  } else {
    Serial.println("green2");
  }

  if (!red2) {
    sum += 8;
  } else {
    Serial.println("red2");
  }

  if (!blue1) {
    sum += 4;
  } else {
    Serial.println("blue1");
  }

  if (!green1) {
    sum += 2;
  } else {
    Serial.println("green1");
  }

  if (!red1) {
    sum += 1;
  } else {
    Serial.println("red1");
  }

  Wire.beginTransmission(address);
  Wire.write(sum);
  Wire.endTransmission();
  sum = 0 ;
}
