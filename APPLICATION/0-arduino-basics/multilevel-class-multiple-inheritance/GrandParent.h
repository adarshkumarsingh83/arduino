

#ifndef GrandParent_h
#define GrandParent_h

class GrandParent {

  private:
    String _name;

  protected:
    String _property;

    String getGrandParentProperty();


  public:
    GrandParent() {
    }

    GrandParent(String name) : _name(name) {}
    String setName(String name) ;
    String getName();
    void setGrandParentProperty(String property);
    void displayGrandParent();
    
    ~GrandParent() {

    }
};

#endif
