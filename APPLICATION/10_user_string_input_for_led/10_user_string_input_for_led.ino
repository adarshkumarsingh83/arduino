
String message = "Enter R for RED, \n Enter G for GREEN, \n Enter Y for YELLOW";
String userOption;

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

void ledAction(String userOption) {
  if (userOption == "R" || userOption == "r") {
    Serial.println("RED OPTION");
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (userOption ==  "G" || userOption == "g") {
    Serial.println("GREEN OPTION");
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (userOption == "Y" || userOption == "y") {
    Serial.println("YELLOW OPTION");
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  } else {
    Serial.println("OPTION NOT MATCHED");
  }
}


String userInput() {

  Serial.println(message);
  while (Serial.available() == 0) {}
  userOption = Serial.readString();
  userOption.trim();
  Serial.println(userOption);
  if (userOption == "R" || userOption == "G" || userOption == "Y") {
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
