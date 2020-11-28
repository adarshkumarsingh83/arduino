int xpin = A2;
int ypin = A3;
int switchPin = 13;

int xpinValue;
int ypinValue;
int spinValue;

void setup() {
  Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
}

void loop() {

  xpinValue =  analogRead(xpin);
  ypinValue =  analogRead(ypin);
  spinValue = digitalRead(switchPin);
  Serial.println();
  Serial.print("value of x ");
  Serial.print(xpinValue);
  Serial.println();
  Serial.print("value of y ");
  Serial.print(ypinValue);
  Serial.println();
  Serial.print("value of swtich ");
  Serial.print(spinValue);
  delay(1000);
}
