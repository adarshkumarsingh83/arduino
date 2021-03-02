

#include<Arduino.h>
#include "Message.h"
#include "MessageQueue.h"


void MessageQueue::initMessageQueue() {
  Serial.begin(9600);
}

void MessageQueue::addMessage(Message message) {
  int newInsertPoint = (_endPoint + 1) % _queueSize;
  if (_queue[newInsertPoint].getText() == "-") {
    _queue[newInsertPoint] = message;
    _endPoint = newInsertPoint;
  }
}
Message MessageQueue::removeMessage() {
  Message message ;
  int newRemovalPoint = (_startPoint + 1) % _queueSize;
  if (_queue[newRemovalPoint].getText() != "") {
    message = _queue[newRemovalPoint];
    _startPoint = newRemovalPoint;
  }
  return message;
}
void MessageQueue::displayQueueData() {
  int st = 0;
  int ed = 0;
  st =  (_startPoint + 1) % _queueSize;
  ed = st;
  while (true) {
    String data = _queue[st].getText();
    Serial.print(data + ", ");
    st = (st + 1) % _queueSize;
    if (st == ed) {
      break;
    }
  }
}
