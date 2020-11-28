int readPin = A3;
int ledPin = 13;
int readValue = 0;
bool ledOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  readValue = (1. / 1023.) * analogRead(readPin);
  Serial.println(readValue);
  if (readValue == 0) {
    if (ledOn == false) {
      digitalWrite(ledPin, HIGH);
      ledOn = true;
    } else {
      digitalWrite(ledPin, LOW);
      ledOn = false;
    }
  }
  delay(50);
}
