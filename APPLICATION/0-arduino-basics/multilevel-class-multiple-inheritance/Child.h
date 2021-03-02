
#ifndef Child_h
#define Child_h

#include "Mother.h"
#include "Father.h"

class Child : public Father, public Mother {

  private:
    String _name;
    String _propertyOwned;

  public:
    Child() {
    }

    Child(String name, Father father, Mother mother, GrandParent parent);
    void displayChild();
    void setChildProperty(String property);

    ~Child() {
    }
};

#endif
