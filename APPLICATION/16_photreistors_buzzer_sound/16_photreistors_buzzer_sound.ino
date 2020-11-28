
int readValuePin = A3;
float voltage;
int buzzerPin = 13;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(readValuePin, INPUT);

}

void loop() {
  voltage = (9. / 550.) * analogRead(readValuePin) - (9.*200 / 550.) + 1.;
  Serial.println(voltage);
  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(voltage);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(voltage);
}
