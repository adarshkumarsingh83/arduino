
#include <Arduino.h>
#include "MoterCycle.h"


String MoterCycle::getType() {
  return this->_type;
}

void MoterCycle::setType(String type) {
  _type = type;
}

void MoterCycle::displayData() {
  Serial.print("Car ,name ");
  Serial.print(_name);
  Serial.print(", type ");
  Serial.print(_type);
  Serial.print(", ");
  Vehicle::displayData();
  Serial.println();
}
