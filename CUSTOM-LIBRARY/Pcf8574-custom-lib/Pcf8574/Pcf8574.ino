
#include "Pcf8574.h"

Pcf8574 pcf8574 = Pcf8574(20);
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("init");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  int pinNo = random(0, 7);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  pcf8574.switchOn(pinNo);
  pcf8574.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574.switchOff(pinNo);
  pcf8574.displayPinState();
  delay(2000);
}
