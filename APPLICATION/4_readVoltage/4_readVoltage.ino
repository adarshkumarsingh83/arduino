int readPin1=A3;
int readVoltage1=0;
float outputVoltage1=0.;
int readPin2=A4;
int readVoltage2=0;
float outputVoltage2=0.;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(readPin1,INPUT);
 pinMode(readPin2,INPUT);
}

void loop() {
  // put your m9ain code here, to run repeatedly:
  readVoltage1=analogRead(readPin1);
  outputVoltage1= (5./1023.)*readVoltage1;
  Serial.println(outputVoltage1);
  
    readVoltage2=analogRead(readPin2);
    outputVoltage2= (5./1023.)*readVoltage2;
  Serial.println(outputVoltage2);
  delay(1000);
  Serial.println("----");
}
