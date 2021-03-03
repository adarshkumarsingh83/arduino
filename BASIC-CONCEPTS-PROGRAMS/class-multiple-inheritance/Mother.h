#ifndef Mother_h
#define Mother_h

class Mother {

  private:
    String _name;

  protected:
    String _property;

    String getMotherProperty();


  public:
    Mother() {
    }

    Mother(String name) : _name(name) {}
    String setName(String name) ;
    String getName();
    void setMotherProperty(String property);
    void displayMother();

    ~Mother() {

    }
};

#endif
