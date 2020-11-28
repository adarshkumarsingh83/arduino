
int readValuePin = A3;
float lightValue;
int buzzerPin = 13;

int delayTime = 0;
int delayTime1 = 0;
int delayTime2 = 10;
int light1 = 0;
int light2 = 750;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(readValuePin, INPUT);

}

// formula to calculate angle for the servo moter based on light input value
int calaculateDelay(int lightValue) {
  float m  = (delayTime2 - delayTime1 ) / (light2 - light1);
  int delayTime = m * ( lightValue - light1 ) + delayTime1;
  Serial.println(delayTime);
  return delayTime;
}

void loop() {

  lightValue = analogRead(readValuePin);
  //delayTime = (9. / 550.) * lightValue - (9.*200 / 550.) + 1.;
  delayTime = calaculateDelay(lightValue);
  Serial.println(lightValue);
  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(delayTime);
}
