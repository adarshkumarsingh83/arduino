int outputPin = 3;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(outputPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256; i++){
    Serial.println(i);
    analogWrite(outputPin,i);
    delay(1000);
  }
}
