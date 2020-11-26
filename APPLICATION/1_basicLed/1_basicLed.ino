
int outputPin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outputPin,HIGH);
  delay(1000);
  digitalWrite(outputPin,LOW);

}
