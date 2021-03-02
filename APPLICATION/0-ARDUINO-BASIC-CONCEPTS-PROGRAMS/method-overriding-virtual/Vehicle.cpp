
#include <Arduino.h>
#include "Vehicle.h"

void Vehicle::init(){
   Serial.begin(9600);
}

void Vehicle::displayData() {
  Serial.print("Vehicle ");
  Serial.print(_name);
  Serial.print(" type ");
  Serial.print(_type);
  Serial.println();
}
