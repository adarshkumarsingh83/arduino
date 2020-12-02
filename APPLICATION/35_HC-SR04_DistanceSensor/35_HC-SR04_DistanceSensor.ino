const int tiggerPin = 12;
const int echoPin = 11;
int pingTrvaelTime;

void setup() {
  Serial.begin(9600);
  pinMode(tiggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  digitalWrite(tiggerPin, LOW);
  delayMicroseconds(1000);

  digitalWrite(tiggerPin, HIGH);
  delayMicroseconds(1000);

  pingTrvaelTime = pulseIn(echoPin, HIGH);
  Serial.println(pingTrvaelTime);

  digitalWrite(tiggerPin, LOW);

}
