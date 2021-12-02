
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver _pwmBoard =  Adafruit_PWMServoDriver(0x40);

void setup() {
  Serial.begin(115200);
  _pwmBoard.begin();
  _pwmBoard.setPWMFreq(50);

  for (int i = 0; i < 16; i++) {
    Serial.print(" Servo no ");
    Serial.print(i);
    Serial.println(" center  ");
    _pwmBoard.writeMicroseconds(i, 1500);
    delay(1000);
  }
}

void loop() {

  for (int i = 0; i < 16; i++) {
    Serial.print(" Servo no ");
    Serial.print(i);
    Serial.println(" right side ");
    _pwmBoard.writeMicroseconds(i, 1000);
    delay(1000);
  }


  for (int i = 0; i < 16; i++) {
    Serial.print(" Servo no ");
    Serial.print(i);
    Serial.println(" Left side ");
    _pwmBoard.writeMicroseconds(i, 2000);
    delay(1000);
  }

  delay(1000);
}
