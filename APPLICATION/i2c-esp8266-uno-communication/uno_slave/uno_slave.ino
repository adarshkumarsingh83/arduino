#include <Wire.h>

void setup() {
  Wire.begin(8);  //0x08 =8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendEvent);
  Serial.begin(115200);
}

void loop() {
  delay(1000);
}

void receiveEvent(int howMany) {
  String message;
  while (0 < Wire.available()) {
    char c = Wire.read();
    message += c;
  }
  Serial.println(message);
}

static int count = 0;
void sendEvent(int howmany) {
  Wire.write("hi esp8266 \n");
  count = count + 1;
}
