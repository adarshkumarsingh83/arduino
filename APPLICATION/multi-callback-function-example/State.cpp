

#include"State.h"

int counter = 0;

const String messageOn = "welcome to espark on state";
const String messageOff = "welcome to espark off state";

void State::processState() {
  if (counter % 2 == 0) {
    if (onStateCallback) {
      onStateCallback(messageOn, messageOn.length());
    }
  } else {
    if (offStateCallback) {
      offStateCallback(messageOff, messageOff.length());
    }
  }
  counter = counter + 1;
}

void State::setOnStateCallback(ON_CALLBACK_SIGNATURE) {
  this->onStateCallback = onStateCallback;
}
void State::setOffStateCallback(OFF_CALLBACK_SIGNATURE) {
  this->offStateCallback = offStateCallback;
}

void State::loop() {
  processState();
}
