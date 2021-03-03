#ifndef Mother_h
#define Mother_h

#include "GrandParent.h"

class Mother : public GrandParent {

  private:
    String _name;

  protected:
    String _property;
    String getMotherProperty();

  public:
    Mother() {
    }

    Mother(String name, GrandParent parent) : _name(name) , GrandParent(name) {}
    String setName(String name) ;
    String getName();
    void setMotherProperty(String property);
    void displayMother();

    ~Mother() {

    }
};

#endif
