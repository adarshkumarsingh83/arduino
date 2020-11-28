
int readValuePin = A3;
float voltage;
int redPin = 13;
int greenPin = 12;

void setup() {

  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(readValuePin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = (5. / 1023.) * analogRead(readValuePin);
  Serial.println(voltage);
  if (voltage > 2 ) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }
}
