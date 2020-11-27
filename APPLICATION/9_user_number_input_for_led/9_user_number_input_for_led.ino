
String message = "Enter 1 for RED, \n Enter 2 for GREEN, \n Enter 3 for YELLOW";
int userOption = 0;

int redPin = 13;
int greenPin = 12;
int yellowPin = 11;





void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void ledAction(int userOption) {
  if (userOption == 1) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (userOption ==  2) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else {
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
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
