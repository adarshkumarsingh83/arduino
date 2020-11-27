int readValuePin = A3;
int redValueRaw;
float voltage;

int redPin = 13;
int greenPin = 12;
int yellowPin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redValueRaw = analogRead(readValuePin);
  voltage = (5. / 1023.) * redValueRaw;
  Serial.println(voltage);

  if ( voltage > 3) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
  } else if (voltage > 2.5 && voltage < 3.5 ) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
  delay(1000);
}
