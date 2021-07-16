#include <Wire.h>
String message;

void setup() {
  Wire.begin(4, 5);
  Serial.begin(115200);
}

void loop() {
  Wire.beginTransmission(8);//0x08 = 8;
  Wire.write("hi arduino \n");
  Wire.endTransmission();

  Wire.requestFrom(8, 10);//0x08 = 8;

  String response;
  while (0 < Wire.available()) {
    char c = Wire.read();
    response += c;
  }
  Serial.println(response);
  delay(1000);
}
