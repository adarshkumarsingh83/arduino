#ifndef CircularQueue_h
#define CircularQueue_h

#include "Arduino.h"

template <class T>
class CircularQueue {

  private:
    String _queueName;
    int _startIndex = -1;
    int _endIndex = -1;
    int _queueSize;
    int _itemCount = 0;
    T *_data;

  public:
    CircularQueue(int queueSize = 20, String queueName = "-") {
      _startIndex = -1;
      _endIndex = -1;
      _itemCount = 0;
      _queueName = queueName;
      _queueSize = queueSize;
      _data = new T[_queueSize];
    }
    ~CircularQueue() {
      delete[] _data;
    }

    boolean push(const T &value);
    T pop();
    inline boolean isEmpty();
    void resetQueue();
    void displayQueue();
};

#endif
