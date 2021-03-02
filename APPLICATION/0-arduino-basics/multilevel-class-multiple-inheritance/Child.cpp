#include <Arduino.h>
#include "Child.h"


Child::Child(String name, Father father, Mother mother, GrandParent parent) : Father(father.getName(), parent), Mother(mother.getName(), parent) {
  _name = name;
}

void Child::setChildProperty(String property) {
  _propertyOwned = property;
}

void Child::displayChild() {
  Serial.print("Child :Name => ");
  Serial.print(_name);
  Serial.print(" Property => ");
  Serial.println(this->_propertyOwned);
  this->displayFather();
  this->displayMother();
  Serial.println();
}
