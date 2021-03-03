/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#include "Pcf8574.h"
#include <Arduino.h>
#include <Wire.h>


void Pcf8574::initPcf8574() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    _boardPinsState[i] = _OFF;
  }
  boardRefresh(0);
}


bool Pcf8574::switchPinOn(int pinNo) {
  _boardPinsState[pinNo] = _ON;
  boardRefresh(0);
  return true;
}

bool Pcf8574::switchPinOff(int pinNo) {
  _boardPinsState[pinNo] = _OFF;
  boardRefresh(0);
  return true;
}

bool Pcf8574::resetPcf8574() {
  for (int i = 0; i < 8; i++) {
    _boardPinsState[i] = _OFF;
  }
  boardRefresh(0);
  return true;
}

bool Pcf8574::refreshPcf8574() {
  boardRefresh(0);
  return true;
}

void Pcf8574::displayPcf8574PinState() {
  Serial.print("Board address => ");
  Serial.println( _boardsAddress );
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
  sum = 0;
}
