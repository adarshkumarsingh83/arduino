
int meterPin = A3;
int ledPin = 12;
float ledValue;
void setup() {
  // for Serial buffer
  Serial.begin(9600);
  pinMode(meterPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  //reading value from meter and then mapping to the led value scale 
  // meter will read from 0-1023 and led has value from 0-255 
  //mapping has been done here 
  ledValue = (255. / 1023.) * analogRead(meterPin);
  Serial.println(ledValue);
  analogWrite(ledPin, ledValue);
}
