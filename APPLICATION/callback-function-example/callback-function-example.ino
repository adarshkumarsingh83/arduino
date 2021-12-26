
#include"WishMessage.h"

WishMessage wishMessage;

void wishMessageCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void setup() {
  Serial.begin(115200);
  wishMessage.setCallback(wishMessageCallback);
}

void loop() {
  delay(1000);
  wishMessage.loop();
}
