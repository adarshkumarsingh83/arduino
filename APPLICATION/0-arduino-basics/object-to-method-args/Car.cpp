#include <Arduino.h>
#include "Car.h"


void Car::init() {
  Serial.begin(9600);
}

void Car::displayCarData() {
  Serial.print("Car ,name ");
  Serial.print(_name);
  Serial.print(", type ");
  Serial.print(_type);
  Serial.print(", ");
  Serial.println();
}
