
#include "Vehicle.h"
#include "Car.h"
#include "MoterCycle.h"

Vehicle * vehicle;
Car car;
MoterCycle moterCycle;

void setup() {
  Serial.begin(9600);
  car = Car("xuv", "4wheel", "4stroke");
  car.setType("car");
  moterCycle = MoterCycle("r1", "2wheel", "2stoke");
  moterCycle.setType("byke");
}

void loop() {
  delay(2000);
  moterCycle.displayData();
  car.displayData();

  Serial.println("--------");
  vehicle = &moterCycle;
  vehicle->displayData();

  vehicle = &car;
  vehicle->displayData();
  Serial.println();
}
