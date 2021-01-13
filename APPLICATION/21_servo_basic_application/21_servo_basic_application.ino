#include <Servo.h>

int servoPin = 13;
int servoPosition = 0;
String direction = "F";
bool initCheckVar = true;
Servo myServoMoter;

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  myServoMoter.attach(servoPin);
}

void loop() {
  if (initCheckVar) {
    initCheckVar = initCheck(initCheckVar);
  }

  myServoMoter.write(servoPosition);
  Serial.print("DIRECTION IS ");
  Serial.print(direction);
  Serial.print(" ");
  Serial.println(servoPosition);
  if (direction == "F") {
    servoPosition ++;
    if (servoPosition == 180) {
      direction = "B";
      Serial.println("DIRECTION IS CHANGING TO BACKWARD");
    }
  } else {
    servoPosition --;
    if (servoPosition == 0) {
      direction = "F";
      Serial.println("DIRECTION IS CHANGING TO FORWARD");
    }
  }

  delay(200);
}

bool initCheck(bool initCheckVar) {
  Serial.println("initCheck executed");
  myServoMoter.write(0);
  delay(100);
  myServoMoter.write(90);
  delay(100);
  myServoMoter.write(180);
  delay(100);
  myServoMoter.write(90);
  initCheckVar = false;
  return initCheckVar;
}
