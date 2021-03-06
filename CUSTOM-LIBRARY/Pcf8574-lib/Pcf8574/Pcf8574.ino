
#include "Pcf8574.h"

Pcf8574 pcf8574 = Pcf8574();
void setup() {
  Serial.begin(9600);
  pcf8574.setBoardAddress(0x20);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("init");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  int pinNo = random(0, 7);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  pcf8574.switchPinOn(pinNo);
  pcf8574.displayPcf8574PinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574.switchPinOff(pinNo);
  pcf8574.displayPcf8574PinState();
  delay(2000);
}
