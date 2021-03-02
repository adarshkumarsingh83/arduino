#ifndef MoterCycle_h
#define MoterCycle_h

#include <Arduino.h>
#include "Vehicle.h"

class MoterCycle : public Vehicle {

  private:
    String _type;
    String _name;

  public:
    MoterCycle() {
      Vehicle::init();
    }

    MoterCycle(String name, String vechName, String vechType) : Vehicle(vechName, vechType) {
      _name = name;      
      Vehicle::init();
    }

    String getType();

    void setType(String type);

    void displayData();

    ~ MoterCycle() {}
};


#endif
