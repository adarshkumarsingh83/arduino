
#include <Arduino.h>
#include "Message.h"


//copy constructor
Message::Message(const Message &message) {
  initMessage();
  _msg = message._msg;
  _name = message._name;
}

// constructor
Message::Message(String msg = "hellow", String name = "user"): _msg(msg), _name(name) {
  initMessage();
}

void Message::initMessage() {
   Message::_instanceCount++;
  Serial.begin(9600);
}



void Message::displayMessage() {
  Serial.println();
  Serial.print("Message Data: ");
  Serial.print(_msg);
  Serial.print("  ");
  Serial.print("Name: ");
  Serial.print(_name);
  Serial.println();
}

void Message::displayMessageWiwhThis() {
  Serial.println();
  Serial.print("Message Data: ");
  Serial.print(this->_msg);
  Serial.print("  ");
  Serial.print("Name: ");
  Serial.print(this->_name);
  Serial.println();
}
