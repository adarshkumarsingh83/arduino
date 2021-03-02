#ifndef Car_h
#define Car_h

#include <Arduino.h>

class Car {

  private:
    String _type;
    String _name;
    void init();

  public:
    Car() {
      this->init();
    }

    Car(String name,String type) {
      _name = name;
      _type = type;
      this->init();
    }
    
    void displayCarData();

    ~ Car() {}
};


#endif
