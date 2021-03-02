
#include <Arduino.h>
#include "Mother.h"


void Mother::setMotherProperty(String property) {
  _property = property;
}

String Mother::setName(String name) {
  _name = name;
}

String Mother::getName() {
  return _name;
}

String Mother::getMotherProperty() {
  return _property;
}

void Mother::displayMother() {
  Serial.print("Mother Name=> ");
  Serial.print(_name);
  Serial.print(" Grand Parent :Name => ");
  Serial.print(GrandParent::getName());
  Serial.print(" Property=> ");
  Serial.print(this->getGrandParentProperty());
  Serial.print(", ");
  Serial.println(_property);
}
