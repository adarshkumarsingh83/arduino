
#include "Car.h"

Car car;
Car *carPointer;
void setup() {
  car = Car("xuv", "4wheel");
}

void loop() {
  delay(2000);
  displayCarInfoByObject(car);
  carPointer = & car;
  displayCarInfoByPointer(carPointer);
  displayCarInfoByPointerToPointer(&carPointer);
  Serial.println();
}


void displayCarInfoByObject(Car carObject) {
  carObject.displayCarData();
}

void displayCarInfoByPointer(Car *carPointer) {
  carPointer->displayCarData();
}


void displayCarInfoByPointerToPointer(Car **carPointerToPointer) {
  (*(carPointerToPointer))->displayCarData();
}
