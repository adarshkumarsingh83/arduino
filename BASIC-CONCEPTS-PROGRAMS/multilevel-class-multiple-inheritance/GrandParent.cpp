
#include <Arduino.h>
#include "GrandParent.h"


void GrandParent::setGrandParentProperty(String property) {
  _property = property;
}

String GrandParent::setName(String name) {
  _name = name;
}

String GrandParent::getName() {
  return _name;
}
String GrandParent::getGrandParentProperty() {
  return _property;
}

void GrandParent::displayGrandParent() {
  Serial.print("GrandParent Name => ");
  Serial.print(_name);
  Serial.print(" Property => ");
  Serial.println(_property);
}
