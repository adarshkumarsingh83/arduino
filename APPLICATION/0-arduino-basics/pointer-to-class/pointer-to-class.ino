
#include "Message.h"

Message message;

void setup() {
  //message = Message();

  //message = Message("adarsh kumar");

   message = Message("Hi", "adarsh kumar");
}

void loop() {

  delay(3000);
  message.displayMessage();
  displayMessageDataViaPointer(&message);
}

void displayMessageDataViaPointer(Message * messagePointer){
      Serial.print("\n CLASS METHOD CALL VIA POINTER");
      messagePointer->displayMessage();
      Serial.println();
}
