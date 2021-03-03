#include <Arduino.h>
#include "Child.h"


Child::Child(String name, Father father, Mother mother) : Father(father.getName()), Mother(mother.getName()) {
  _name = name;
}

void Child::setChildProperty(String property) {
  _propertyOwned = property;
}

void Child::displayChild() {
  Serial.print("Child :Name => ");
  Serial.print(_name);
  Serial.print(" Child Father :Name => ");
  Serial.print(Father::getName());
  Serial.print(" Child Mother :Name => ");
  Serial.print(Mother::getName());
  Serial.print(" Property => ");
  Serial.print(this->getFatherProperty());
  Serial.print(", ");
  Serial.print(this->getMotherProperty());
  Serial.print(", ");
  Serial.println(this->_propertyOwned);
  Serial.println();
}
