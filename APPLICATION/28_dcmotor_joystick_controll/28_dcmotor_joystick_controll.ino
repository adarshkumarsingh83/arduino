const int motorForward = 11;  //attach to one of the pin of the motor
const int motorBackward = 10;  //attach to another pin of the the motor

const int xpin = A2;
const int ypin = A3;
const int switchPin = 8;

const int forwardButtonPin = 13;
const int backwardButtonPin = 12;
const int stopButtonPin = 7;

int state = 0;            //Record the motor state. 0:STOP  1:forward  2:reverse
int dcMotorSpeed = 128;   //Motor speed  0~255

int buttonValue;
int xpinValue;
int ypinValue;
int spinValue;

const float minJSValue = 0;
const float midJSValue = 532;
const float maxJSValue = 1023;
const float minMoterSpeed = 0;
const float maxMoterSpeed = 255;

void setup() {
  Serial.begin(9600);
  pinMode(motorForward, OUTPUT);    //initialize the motorIn1 pin as output
  pinMode(motorBackward, OUTPUT);  //initialize the motorIn2 pin as output
  pinMode(forwardButtonPin, INPUT_PULLUP);
  pinMode(backwardButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);

  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {

  delay(1000);

  joystick(state, dcMotorSpeed);

  xpinValue =  analogRead(xpin);

  dcMotorSpeed = calculateSpeed(xpinValue);

  state = calculateDirection(xpinValue);

  Serial.println(state);
  Serial.println(dcMotorSpeed);
  switch (state) {
    case 0:  stopMoter();                  //motor stop
      break;
    case 1:  forwardMoter(dcMotorSpeed);   //rotate forward
      break;
    case 2:  backwardMoter(dcMotorSpeed);  //rotate backward
      break;
    default: stopMoter();                  //motor stop
      break;
  }

}


int calculateDirection(int xpinValue) {

  if (xpinValue == midJSValue) {
    state  = 0 ;
  } else if (xpinValue < midJSValue) {
    state = 2;
  } else if (xpinValue > midJSValue) {
    state = 1;
  }
  return state;
}

int calculateSpeed(int xpinValue) {

  if (xpinValue == midJSValue) {
    Serial.println("stopped ");
    stopMoter();
  } else if (xpinValue < midJSValue) {
    Serial.println("backward");
    //backward calulation
    float mappingBackWard = (maxMoterSpeed - minMoterSpeed) / (minJSValue - midJSValue);
    Serial.println(mappingBackWard);
    float speedVaue =  (mappingBackWard * xpinValue) + maxMoterSpeed;
    dcMotorSpeed = speedVaue;
  } else if (xpinValue > midJSValue) {
    Serial.println("forward");
    //forward calculation
    float mappingFoarward = (minMoterSpeed - maxMoterSpeed) / (midJSValue - maxJSValue);
    Serial.println(mappingFoarward);
    float speedVaue =  mappingFoarward * (xpinValue - maxJSValue) + maxMoterSpeed ;
    dcMotorSpeed = speedVaue;
  }
  return dcMotorSpeed;
}

void joystick(int state, int dcMotorSpeed) {
  xpinValue =  analogRead(xpin);
  ypinValue =  analogRead(ypin);
  Serial.println();
  Serial.print("value of x ");
  Serial.print(xpinValue);
  Serial.println();
  Serial.print("value of y ");
  Serial.print(ypinValue);
  Serial.println();
}


//The function to drive motor rotate clockwise
void stopMoter() {
  state = 0 ;
  analogWrite(motorBackward, 0); //set the speed of motor
  analogWrite(motorForward, 0); //set the speed of motor
}

//The function to drive motor rotate forward
void forwardMoter(int dcMotorSpeed) {
  Serial.println(state);
  Serial.println(dcMotorSpeed);
  analogWrite(motorBackward, 0);
  analogWrite(motorForward, dcMotorSpeed);
}

//The function to drive motor rotate backward
void backwardMoter(int dcMotorSpeed) {
  Serial.println(state);
  Serial.println(dcMotorSpeed);
  analogWrite(motorForward, 0);
  analogWrite(motorBackward, dcMotorSpeed);
}
