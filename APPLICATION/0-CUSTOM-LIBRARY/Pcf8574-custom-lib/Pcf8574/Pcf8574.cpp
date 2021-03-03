/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#include "Pcf8574.h"
#include <Arduino.h>
#include <Wire.h>


void Pcf8574::initPcf8574Boards() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    _boardPinsState[i] = _OFF;
  }
  Pcf8574::boardRefresh(0);
}


bool Pcf8574::switchOn(int pinNo) {
  _boardPinsState[pinNo] = _ON;
  Pcf8574::boardRefresh(0);
}

bool Pcf8574::switchOff(int pinNo) {
  _boardPinsState[pinNo] = _OFF;
  Pcf8574::boardRefresh(0);
}

void Pcf8574::displayPinState() {
  Serial.println();
  for (int j = 7; j >= 0; j--) {
    Serial.print(_boardPinsState[j]);
    Serial.print(" ");
  }
  Serial.println();
}

void Pcf8574::boardRefresh(int sum) {

  if (!_boardPinsState[7]) {
    sum += 128;
  }

  if (!_boardPinsState[6]) {
    sum += 64;
  }

  if (!_boardPinsState[5]) {
    sum += 32;
  }

  if (!_boardPinsState[4]) {
    sum += 16;
  }

  if (!_boardPinsState[3]) {
    sum += 8;
  }

  if (!_boardPinsState[2]) {
    sum += 4;
  }

  if (!_boardPinsState[1]) {
    sum += 2;
  }

  if (!_boardPinsState[0]) {
    sum += 1;
  }

  // Send the LSB 8 bits of LED_Pattern out to device 1
  // Wire.beginTransmission(_boardsAddress);
  // Wire.write(sum);
  // Wire.endTransmission();
}
