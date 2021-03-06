#include "Pca9685Board.h"

Pca9685Board *pca9685Board;

#define NO_OF_BOARDS 5
int MAX_PINS = 0;
void setup() {
  Serial.begin(9600);
  pca9685Board = &Pca9685Board(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 16;
}

void loop() {
  delay(1000);
  
  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  pca9685Board->throwSwitch(pinNo);
  pca9685Board->displayPinState();
  delay(1000);
  pca9685Board->closeSwitch(pinNo);
  pca9685Board->displayPinState();
  delay(1000);
}
