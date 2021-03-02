
#include <Arduino.h>
#include "Father.h"


void Father::setFatherProperty(String property) {
  _property = property;
}

String Father::setName(String name) {
  _name = name;
}

String Father::getName() {
  return _name;
}

String Father::getFatherProperty() {
  return _property;
}

void Father::displayFather() {
  Serial.print("Father Name=> ");
  Serial.print(_name);
  Serial.print(" Property=> ");
  Serial.println(_property);
}
