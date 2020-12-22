
#define BROAD_RATE 9600
const int RED_PIN = 13;
const int IR_SENSOR_PIN = 3;
void setup() {
  Serial.begin(BROAD_RATE);
  pinMode(RED_PIN, OUTPUT);
  pinMode(IR_SENSOR_PIN, INPUT);
}

void loop() {
  if (digitalRead(IR_SENSOR_PIN) == LOW) {
    digitalWrite(RED_PIN, HIGH);
    delay(100);
  } else {
    digitalWrite(RED_PIN, LOW);
    delay(100);
  }
}
