int readPin = A3;
int readValue = 0;
int redLedPin = 13;
int greenLedPin = 12;
void setup() {
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);
  Serial.println(readValue);
  if (readValue == 0) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
}
