int OPEN = 12;
int CLOSE = 13;

void setup() {
  Serial.begin(9600);
  pinMode(OPEN, OUTPUT);
  pinMode(CLOSE, OUTPUT);

}
enum SWITCHSTATES {
  ST_OFF1,
  ST_OFF2,
  ST_STRAIGHT,
  ST_TURN,
};

SWITCHSTATES switchState = ST_OFF1;

bool flag = true;
int inputInt = 0;

void loop() {

  if (true) {
    inputInt = 1;
    flag = false;
  } else {
    inputInt = 0;
    flag = true;
  }


  delay(200);
  switch (switchState) {

    case ST_OFF1:
      switchoff1(inputInt); //sets up changes to ST_OFF1
      break;
    case ST_OFF2:
      switchoff2(inputInt); //sets up changes to ST_OFF2
      break;
    case ST_STRAIGHT:
      switchstraight(inputInt);
      break;
    case ST_TURN:
      switchturn(inputInt);
      break;
  }
}

void switchoff1(int buttonRead) {
  digitalWrite(OPEN, LOW);
  digitalWrite(CLOSE, LOW);

  if (buttonRead == 1) {
    switchState = ST_TURN; //switches to different state

  }
}

void switchturn(int buttonRead) {
  digitalWrite(OPEN, HIGH); //activates relay 1
  digitalWrite(CLOSE, LOW); // keeps relay 2 off
  delay(200);
  digitalWrite(OPEN, LOW); //turns off relay 1
  digitalWrite(CLOSE, LOW); //keeps relay 2 off
  switchState = ST_OFF2; //chages to ST_OFF2
}

void switchoff2(int buttonRead) {
  digitalWrite(OPEN, LOW); // keeps Relay 1 in the off position
  digitalWrite(CLOSE, LOW); //keeps relay 2 in the off position

  if (buttonRead == 1) {
    switchState = ST_STRAIGHT; //switches to Straight

  }
}

void switchstraight(int buttonRead) {
  digitalWrite(OPEN, LOW); //keeps relay 1 off
  digitalWrite(CLOSE, HIGH); // activates relay 2
  delay(200);
  digitalWrite(OPEN, LOW); //keeps relay 1 off
  digitalWrite(CLOSE, LOW); //turns off relay 2
  switchState = ST_OFF1; //chages to ST_OFF1
}
