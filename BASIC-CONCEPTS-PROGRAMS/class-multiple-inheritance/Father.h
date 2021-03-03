#ifndef Father_h
#define Father_h

class Father {

  private:
    String _name;

  protected:
    String _property;
    String getFatherProperty();


  public:
    Father() {
    }

    Father(String name): _name(name) {}
    String setName(String name);
    String getName();
    void setFatherProperty(String property);
    void displayFather();

    ~Father() {

    }
};

#endif
