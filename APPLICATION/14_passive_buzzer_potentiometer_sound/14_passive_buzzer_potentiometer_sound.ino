int readValuePin = A3;
float voltage;

int buzzerPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(readValuePin, INPUT);
}

void loop() {
  voltage = (9940. / 1023.) * analogRead(readValuePin)+60;
  Serial.println(voltage);

  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(voltage);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(voltage);
}
