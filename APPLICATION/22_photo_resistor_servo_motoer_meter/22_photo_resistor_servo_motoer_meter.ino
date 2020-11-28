#include <Servo.h>

int servoPin = 13;
int servoPosition = 0;
Servo myServoMoter;

int readPin = A3;

float angle1 = 0;
float angle2 = 180;
float light1 = 0;
float light2 = 750;

// formula to calculate angle for the servo moter based on light input value
int calaculateAngle(int lightValue) {
  float m = (angle2 - angle1) / (light2 - light1);
  int angleValue = m * ( lightValue - light1) + angle1;
  Serial.println(angleValue);
  return angleValue;
}


void setup() {
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(servoPin, OUTPUT);
  myServoMoter.attach(servoPin);

  calaculateAngle(145);
}

void loop() {

  int value = analogRead(readPin);
  Serial.println(value);
  servoPosition = calaculateAngle(value);
  myServoMoter.write(servoPosition);
  delay(500);
}
