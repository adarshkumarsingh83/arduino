
#include "Message.h"
#include "MessageQueue.h"

int i = 0;
MessageQueue messageQueue = MessageQueue();

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (i < 5) {
    Message message("welcome");
    messageQueue.addMessage(message);
    i++;
  } else {
    messageQueue.displayQueueData();
    for (i = 0; i< 5; i ++) {
      messageQueue.removeMessage();
    }
    i=0;
  }

}
