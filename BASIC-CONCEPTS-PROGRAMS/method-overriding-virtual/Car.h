#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include "Vehicle.h"

class Car : public Vehicle {

  private:
    String _type;
    String _name;

  public:
    Car() {
      Vehicle::init();
    }

    Car(String name, String vechName, String vechType) : Vehicle(vechName, vechType) {
      _name = name;
      Vehicle::init();
    }

    String getType();

    void setType(String type);

    void displayData();

    ~ Car() {}
};


#endif
