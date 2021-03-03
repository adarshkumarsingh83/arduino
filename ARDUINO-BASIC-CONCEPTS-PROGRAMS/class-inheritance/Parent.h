#ifndef Parent_h
#define Parent_h

class Parent {

  private:
    String _name;

  protected:
    String _property;
    String getName();

  public:
    Parent() {
    }

    Parent(String name);
    
    void setParentProperty(String property);
    void displayParent();

    ~Parent() {

    }
};

#endif
