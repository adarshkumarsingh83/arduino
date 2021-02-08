
const int RED_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {

  digitalWrite(RED_PIN,LOW);
  Serial.println("low");
  delay(10000);
  digitalWrite(RED_PIN,HIGH);
  Serial.println("heigh");
  delay(10000);
}
