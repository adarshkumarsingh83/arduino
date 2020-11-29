int tiltSwitchPin = 2;
int tiltSwitchValue = 0;
int redLedPin = 3;
int greenLedPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(tiltSwitchPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(tiltSwitchPin, HIGH);
}

void loop() {
  tiltSwitchValue = digitalRead(tiltSwitchPin);
  Serial.println(tiltSwitchValue);
  if(tiltSwitchValue == 0 ){
    digitalWrite(greenLedPin,HIGH);
    digitalWrite(redLedPin,LOW);
  }else{
    digitalWrite(greenLedPin,LOW);
    digitalWrite(redLedPin,HIGH);
  }
  delay(100);
}
