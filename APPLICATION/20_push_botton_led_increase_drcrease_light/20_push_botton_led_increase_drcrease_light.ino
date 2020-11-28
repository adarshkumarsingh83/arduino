int readPinAdd = A3;
int readPinSub = A2;
int ledPin = 13;
int ledValueCounter = 126;
int readValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(readPinAdd, INPUT);
  pinMode(readPinSub, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  Serial.println(ledValueCounter);
  readValue = (1. / 1023.) * analogRead(readPinAdd);
  if (readValue != 1) {
    if (ledValueCounter < 256) {
      ledValueCounter++;
      analogWrite(ledPin, ledValueCounter);
    }
  }
  readValue = (1. / 1023.) * analogRead(readPinSub);
  if (readValue != 1) {
    if (ledValueCounter > 127 ) {
      ledValueCounter--;
      analogWrite(ledPin, ledValueCounter);
    }
  }
  delay(100);
}
