#include <Servo.h>

// joystick
int xpin = A2;
int ypin = A3;
int switchPin = 13;

int xpinValue;
int ypinValue;
int spinValue;

float readValueMin = 0;
float readValueMax = 1023;
float angleValueMin = 0;
float angleValueMax = 180;

// servo moter X
int servoPinX = 12;
int servoAngleX = 0;
Servo servoMotorX;

// servo motor Y
int servoPinY = 12;
int servoAngleY = 0;
Servo servoMotorY;

void setup() {
  Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);

  pinMode(servoPinX, OUTPUT);
  servoMotorX.attach(servoPinX);

  pinMode(servoPinY, OUTPUT);
  servoMotorY.attach(servoPinY);
}

int calculateAngle(int value) {
  float m = (angleValueMax - angleValueMin) / (readValueMax - readValueMin);
  int angleValue = m * ( value - readValueMin) + angleValueMin;
  return angleValue;
}

void loop() {

  xpinValue =  analogRead(xpin);
  ypinValue =  analogRead(ypin);
  spinValue = digitalRead(switchPin);
  Serial.println();
  Serial.print("value of x ");
  Serial.print(xpinValue);
  Serial.println();
  Serial.print("value of y ");
  Serial.print(ypinValue);
  Serial.println();
  Serial.print("value of swtich ");
  Serial.print(spinValue);

  servoAngleX = calculateAngle(xpinValue);
  Serial.println();
  Serial.print(servoAngleX);
  servoMotorX.write(servoAngleX);

  servoAngleY = calculateAngle(ypinValue);
  Serial.println();
  Serial.print(servoAngleY);
  servoMotorY.write(servoAngleY);

  delay(1000);
}
