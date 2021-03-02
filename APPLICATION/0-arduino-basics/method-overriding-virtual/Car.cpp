#include <Arduino.h>
#include "Car.h"


String Car::getType() {
   return this->_type;
}

void Car::setType(String type) {
   _type = type;
}

void Car::displayData() {
  Serial.print("Car ,name ");
  Serial.print(_name);
  Serial.print(", type ");
  Serial.print(_type);
  Serial.print(", ");
  Vehicle::displayData();
  Serial.println();
}
