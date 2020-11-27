String message = "Enter 1 for RED, \n Enter 2 for GREEN, \n Enter 3 for BLUE";
int userOption = 0;

int redPin = 13;
int greenPin = 12;
int bluePin = 11;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void ledAction(int userOption) {
  switch (userOption) {
    case 1:
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 2:
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 3:
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      break;
    default:
      Serial.println("input not matched with avalable options");
      break;
  }
}


int userInput() {

  Serial.println(message);
  while (Serial.available() == 0) {}
  userOption = Serial.parseInt();

  if (userOption > 0 && userOption < 4) {
    ledAction(userOption);
  } else {
    Serial.println("invalid Option please provide input again ");
    userInput();
  }
  return userOption;
}


void loop() {

  userOption = userInput();

  ledAction(userOption);

}
