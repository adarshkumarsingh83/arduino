const int motorIn1 = 11;  //attach to one of the pin of the motor
const int motorIn2 = 10;  //attach to another pin of the the motor

const int forwardButtonPin = 13;
const int backwardButtonPin = 12;
const int stopButtonPin = 7;

int state = 0;            //Record the motor state. 0:STOP  1:forward  2:reverse
int dcMotorSpeed = 128;   //Motor speed  0~255

int buttonValue;
void setup() {
  Serial.begin(9600);
  pinMode(motorIn1, OUTPUT);    //initialize the motorIn1 pin as output
  pinMode(motorIn2, OUTPUT);  //initialize the motorIn2 pin as output
  pinMode(forwardButtonPin, INPUT_PULLUP);
  pinMode(backwardButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);
}

void loop() {
  delay(100);

  buttonValue = digitalRead(forwardButtonPin);
  if (buttonValue == LOW) {
    clockwise(0);
    state = 1;
    dcMotorSpeed = 148;
    buttonValue = HIGH;
  }

  buttonValue = digitalRead(backwardButtonPin);
  if (buttonValue == LOW) {
    clockwise(0);
    state = 2;
    dcMotorSpeed = 148;
    buttonValue = HIGH;
  }

  buttonValue = digitalRead(stopButtonPin);
  if (buttonValue == LOW) {
    state = 0;
    dcMotorSpeed = 128;
    buttonValue = HIGH;
  }

  Serial.println(state);
  Serial.println(dcMotorSpeed);

  switch (state) {
    case 0:  clockwise(0);                  //motor stop
      break;
    case 1:  clockwise(dcMotorSpeed);       //rotate clockwise
      break;
    case 2:  counterclockwise(dcMotorSpeed);//rotate counterclockwise
      break;
    default: clockwise(0);                  //motor stop
      break;
  }

}

//The function to drive motor rotate clockwise
void clockwise(int dcMotorSpeed) {
  analogWrite(motorIn2, 0);    //stop the motorIn2 pin of motor
  analogWrite(motorIn1, dcMotorSpeed); //set the speed of motor
}

//The function to drive motor rotate counterclockwise
void counterclockwise(int dcMotorSpeed) {
  analogWrite(motorIn1, 0);    //stop the motorIn1 pin of motor
  analogWrite(motorIn2, dcMotorSpeed); //set the speed of motor
}
