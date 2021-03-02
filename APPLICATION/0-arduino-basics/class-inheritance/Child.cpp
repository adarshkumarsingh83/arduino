#include <Arduino.h>
#include "Child.h"

Child::Child(String name, String parentName) : Parent(parentName) {
  _name = name;
}

void Child::setChildProperty(String property) {
  _propertyOwned = property;
}

void Child::displayChild() {
  Serial.print("Child :Name=> ");
  Serial.print(this->_name);
  Serial.print(" Parent :Name=> ");
  Serial.print(Parent::getName());
  Serial.print(" Property=> ");
  Serial.print(this->_property);
  Serial.print(", ");
  Serial.println(this->_propertyOwned);
}
