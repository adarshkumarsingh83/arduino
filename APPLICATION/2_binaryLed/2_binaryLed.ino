
const byte pinLenght = 4;
byte pinList[] = {13,12,11,10};
char myArray[8];

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
   for (byte i=0; i< pinLenght; i++) {
      pinMode(pinList[i],OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int st = 0; st<16; st++){

   int pin1 = bitRead(st, 0);
   int pin2 = bitRead(st, 1);
   int pin3 = bitRead(st, 2);
   int pin4 = bitRead(st, 3);
   Serial.print(st);
   Serial.print("-");
   Serial.print(pin4);
   Serial.print(pin3);
   Serial.print(pin2);
   Serial.print(pin1);
   Serial.println();
   digitalWrite(pinList[0],pin1);
   digitalWrite(pinList[1],pin2);
   digitalWrite(pinList[2],pin3);
   digitalWrite(pinList[3],pin4);
   
   delay(1000);
    for (int i =0; i <4; i++){
       digitalWrite(pinList[i],LOW);
    }
    delay(1000);
  }
}
