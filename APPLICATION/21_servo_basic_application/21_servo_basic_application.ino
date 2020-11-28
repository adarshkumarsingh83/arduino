#include <Servo.h>

int servoPin = 13;
int servoPosition = 0;
Servo myServoMoter;

void setup() {
   Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  myServoMoter.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
   myServoMoter.write(servoPosition);
   if(servoPosition == 180){
     servoPosition = 0;
   }else{
     servoPosition ++;
   }
   delay(500);
}
