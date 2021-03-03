#include "Parent.h"
#include "Child.h"

Parent parent;
Child child;

void setup() {
  Serial.begin(9600);
  parent = Parent("Dad ");
  child = Child("kid", "Dad");
}

void loop() {
  delay(3000);
  parent.setParentProperty("house");
  parent.displayParent();
  child.setParentProperty("house");
  child.setChildProperty("car");
  child.displayChild();
}
