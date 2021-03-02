

#ifndef MessageQueue_h
#define MessageQueue_h

#include <Arduino.h>
#include "Message.h"

class MessageQueue {

  private:
    const int _queueSize = 10;
    int _startPoint;
    int _endPoint;
    Message * _queue;

    void initMessageQueue();

  public:
    MessageQueue() {
      _queue = new Message[_queueSize];
      this->_startPoint = -1;
      this->_endPoint = -1;
      this->initMessageQueue();
    }

    void addMessage(Message message);
    Message removeMessage();
    void displayQueueData();

    ~ MessageQueue() {
      delete [] _queue;
    }
};


#endif
