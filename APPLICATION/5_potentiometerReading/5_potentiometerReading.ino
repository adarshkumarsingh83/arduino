
int readValuePin = A3;
int redValueRaw;
float voltage;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  redValueRaw = analogRead(readValuePin);
  voltage = (5. / 1023.) * redValueRaw;
  Serial.println(voltage);
  delay(1000);
}
