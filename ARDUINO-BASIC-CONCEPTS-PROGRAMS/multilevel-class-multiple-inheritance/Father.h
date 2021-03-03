#ifndef Father_h
#define Father_h

#include "GrandParent.h"


class Father : public GrandParent {

  private:
    String _name;

  protected:
    String _property;
    String getFatherProperty();


  public:
    Father() {
    }

    Father(String name, GrandParent parent): _name(name), GrandParent(name) {}
    String setName(String name);
    String getName();
    void setFatherProperty(String property);
    void displayFather();

    ~Father() {

    }
};

#endif
