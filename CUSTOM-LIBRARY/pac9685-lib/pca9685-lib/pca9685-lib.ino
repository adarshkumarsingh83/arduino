#include "Pca9685.h"
#include "Pca9685Board.h"

Pca9685Board *pca9685Board;

#define NO_OF_BOARDS 3
int MAX_PINS = 0;
void setup() {
  Serial.begin(9600);
  Pca9685Board object = Pca9685Board(NO_OF_BOARDS);
  pca9685Board = &object;
  //pca9685Board = &Pca9685Board(NO_OF_BOARDS,60);
  MAX_PINS = NO_OF_BOARDS * 16;
  for (int i = 0; i < MAX_PINS; i++) {
    pca9685Board->setSwitchRange(i, 100, 400);
  }
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
