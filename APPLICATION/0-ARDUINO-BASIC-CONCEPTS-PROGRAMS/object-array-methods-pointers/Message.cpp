
#include<Arduino.h>
#include "Message.h"


void Message::init() {
  Serial.begin(9600);
}

String Message::getText(){
  return this->_text;  
}

void Message::displayMessageData() {
  Serial.print("Message text: ");
  Serial.print(_text);
  Serial.print(", type: ");
  Serial.print(_type);
  Serial.println();
}
