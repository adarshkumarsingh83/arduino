
const int RED_PIN = 7;
const int GREEN_PIN = 6;
const int BLUE_PIN = 5;
void setup() {

  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  //GREEN
  analogWrite(BLUE_PIN, 0);
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  delay(1000);
  //RED
  analogWrite(BLUE_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(RED_PIN, 255);
  delay(1000);
  //BLUE
  analogWrite(BLUE_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(RED_PIN, 0);
  delay(1000);
  //YELLOW
  analogWrite(BLUE_PIN, 0);
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  delay(1000);
  //RESET ALL PINS
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  delay(1000);
}
