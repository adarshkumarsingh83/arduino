#include<Stepper.h>

int pin0 = 8;//definition digital 8 pins as pin to control the IN1 (ULN24L01)
int pin1 = 9;//definition digital 9 pins as pin to control the IN2 (ULN24L01)
int pin2 = 10;//definition digital 10 pins as pin to control the IN3 (ULN24L01)
int pin3 = 11;//definition digital 11 pins as pin to control the IN4 (ULN24L01)

int stepsPerRevolution = 2048;
int moterSpeed = 1;
Stepper stepperMoter(stepsPerRevolution, pin0, pin1, pin2, pin3);

void setup() {
  Serial.begin(9600);
  stepperMoter.setSpeed(moterSpeed);
}

void loop() {

  stepperMoter.step(stepsPerRevolution);
  delay(50);
  stepperMoter.step(-stepsPerRevolution);
  delay(50);
}
