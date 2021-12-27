
#include"State.h"

State state;

void onStateCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void offStateCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void setup() {
  Serial.begin(115200);
  state.setOnStateCallback(onStateCallback);
  state.setOffStateCallback(offStateCallback);
}

void loop() {
  delay(1000);
  state.loop();
}
