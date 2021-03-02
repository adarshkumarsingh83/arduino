
#include "Car.h"

Car car[3];
Car *carPointer;
Car **carPointerToPointer;

int carListSize = -1;

void setup() {
  car[0] = Car("xuv", "4wheel");
  car[1] = Car("explorer", "4wheel");
  car[2] = Car("gwagon", "4wheel");
  carListSize = sizeof(car) / sizeof(Car);
}

void loop() {
  delay(2000);
  Serial.print("Size of Car ");
  Serial.print(carListSize);
  Serial.println();

  displayCarInfoByObject(car);
  Serial.println();

  carPointer = car;
  displayCarInfoByPointer(carPointer);
  Serial.println();

  displayCarInfoByPointerToPointer(&carPointer);
  Serial.println();
  carPointerToPointer = &carPointer;
  displayCarInfoByPointerToPointerToPointer(&carPointerToPointer);
}

void displayCarInfoByObject(Car carArray[]) {
  Serial.println("Array copy ");
  for (int i = 0;  i < carListSize; i++) {
    carArray[i].displayCarData();
  }
}

void displayCarInfoByPointer(Car *carPointer) {
  Serial.println("Array to pointer ");
  for (int i = 0 ; i < carListSize; i++) {
    carPointer[i].displayCarData();
  }
}

void displayCarInfoByPointerToPointer(Car **carPointerToPointer) {
  Serial.println("Array to pointer to pointer ");
  for (int i = 0 ; i < carListSize; i++) {
    ((*carPointerToPointer)[i]).displayCarData();
  }
}

void displayCarInfoByPointerToPointerToPointer(Car *** carPointerToPointer) {
  Serial.println("Array to pointer to pointer to pointer ");
  for (int i = 0 ; i < carListSize; i++) {
    ((*(*carPointerToPointer))[i]).displayCarData();
  }
}
