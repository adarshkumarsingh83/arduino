
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

void loop() {
  redLed();
  delay(1000);
  greenLed();
  delay(1000);
  blueLed();
  delay(1000);
}


void redLed() {
  for (int r = 0; r < 256; r++) {
    for (int g = 0; g < 256; g++) {
      for (int b = 0; b < 256; b++) {
        analogWrite(redPin, r);
        analogWrite(greenPin, g);
        analogWrite(bluePin, b);
        resetLed(r, g, b);
      }
    }
  }
}

void greenLed() {
  for (int g = 0; g < 256; g++) {
    for (int r = 0; r < 256; r++) {
      for (int b = 0; b < 256; b++) {
        analogWrite(greenPin, g);
        analogWrite(redPin, r);
        analogWrite(bluePin, b);
        resetLed(r, g, b);
      }
    }
  }
}

void blueLed() {
  for (int b = 0; b < 256; b++) {
    for (int g = 0; g < 256; g++) {
      for (int r = 0; r < 256; r++) {
        analogWrite(bluePin, b);
        analogWrite(redPin, r);
        analogWrite(greenPin, g);
        resetLed(r, g, b);
      }
    }
  }
}

void resetLed(int r,int g,int b) {
  Serial.println(r);
  Serial.println(g);
  Serial.println(b);
  Serial.println("-");
  delay(10);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(10);
}
