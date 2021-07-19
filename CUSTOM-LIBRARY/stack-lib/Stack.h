#ifndef Stack_h
#define Stack_h

#include "Arduino.h"

template <class T>
class Stack {

  private:
    String _stackName;
    int _index = -1;
    int _stackSize;
    int _itemCount = 0;
    T *_data;

  public:
    Stack(int stackSize = 20, String stackName = "-") {
      _index = -1;
      _itemCount = 0;
      _stackName = stackName;
      _stackSize = stackSize;
      _data = new T[_stackSize];
    }
    ~Stack() {
      delete[] _data;
    }

    boolean push(const T &value);
    T pop();
    inline boolean isEmpty();
    inline boolean isFull();
    void resetStack();
    void displayStack();
};

#endif
