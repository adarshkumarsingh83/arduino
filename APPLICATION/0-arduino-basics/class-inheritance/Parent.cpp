
#include <Arduino.h>
#include "Parent.h"

Parent::Parent(String name) {
  _name = name;
}

 String Parent::getName(){
   return this->_name; 
 }
  
void Parent::setParentProperty(String property) {
  _property = property;
}

void Parent::displayParent() {
  Serial.print("Parent Name=> ");
  Serial.print(this->_name);
  Serial.print(" Property=> ");
  Serial.println(this->_property);  
}
