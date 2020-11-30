
//deciaml literal
int decimalCounter = 0;

//octal literal
byte octalCounter = 00;

//binary literal
byte binaryCounter = B00000000;

//hexa deciaml literal
byte hexaDeciamlCounter = 0x0;

const int DELAY_TIME = 500;
void setup() {
  Serial.begin(9600);
}

void loop() {
  //binary number
  Serial.print(decimalCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print(decimalCounter, OCT);
  Serial.print("\t");
  // hexa decimal number
  Serial.print(decimalCounter, HEX);
  Serial.println();


    //binary number
  Serial.print(binaryCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print(binaryCounter, OCT);
  Serial.print("\t");
  // hexa decimal number
  Serial.print(binaryCounter, HEX);
  Serial.println();


      //binary number
  Serial.print(octalCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print(octalCounter, OCT);
  Serial.print("\t");
  // hexa decimal number
  Serial.print(octalCounter, HEX);
  Serial.println();

  
    //binary number
  Serial.print(hexaDeciamlCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print(hexaDeciamlCounter, OCT);
  Serial.print("\t");
  // hexa decimal number
  Serial.print(hexaDeciamlCounter, HEX);
  Serial.println();
  Serial.println();

  binaryCounter++;
  decimalCounter++;
  octalCounter++;
  hexaDeciamlCounter++;
  
  delay(DELAY_TIME);
}
