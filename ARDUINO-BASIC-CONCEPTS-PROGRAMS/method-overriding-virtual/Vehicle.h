
#ifndef Vehicle_h
#define Vehicle_h

#include <Arduino.h>

class Vehicle {

  private:
    String _type;
    String _name;

 protected:   
    void init();

  public:
    Vehicle() {
      init();
    }

    Vehicle(String name, String type) {
      _name = name;
      _type = type;
      init();
    }

    virtual String getType() = 0;

    virtual void setType(String type) = 0;

    void displayData();

    ~Vehicle() {
    }
};


#endif
