
#include "Message.h"

int Message::_instanceCount = 0;
void setup() {

  //message = Message();

  Message message1 = Message("welcome");

  Message message2 = Message("Hi", "adarsh kumar");

  Message message3 = Message("Hi", "adarsh kumar");
}

void loop() {

  delay(3000);
  Serial.print("Object instance of class ");
  Serial.println(Message::getInstanceCount());
}
