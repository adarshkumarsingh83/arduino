
#include "Message.h"

Message message;
Message copyMsg;
// Message messageFriend;
void setup() {
  //message = Message();

  //message = Message("adarsh kumar");

  //message = Message("Hi", "adarsh kumar");

  //copy constructor
  message = Message("Hi", "adarsh kumar");
  copyMsg = message;

  //messageFriend = Message("radha singh");
}

void loop() {

  delay(3000);
  message.displayMessage();

  //copy constructor
  Serial.print(" Copy Constructor ");
  copyMsg.displayMessage();

  // friends function not working 
  //showMessage(messageFriend);
}
