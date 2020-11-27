
int readValuePin = A3;
float voltage;

int buzzerPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(readValuePin, INPUT);
}

void loop() {
  voltage = (5. / 1023.) * analogRead(readValuePin);
  Serial.println(voltage);
  if (voltage > 2 ) {
    digitalWrite(buzzerPin, HIGH);
  }else{
     digitalWrite(buzzerPin, LOW);
  }
}
