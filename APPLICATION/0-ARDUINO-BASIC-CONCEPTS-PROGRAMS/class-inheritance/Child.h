
#ifndef Child_h
#define Child_h


#include "Parent.h"

class Child : public Parent {

  private:
    String _name;
    String _propertyOwned;

  public:
    Child() {
    }

    Child(String name, String parentName) ;
    void displayChild();
    void setChildProperty(String property);

    ~Child() {
    }
};

#endif
