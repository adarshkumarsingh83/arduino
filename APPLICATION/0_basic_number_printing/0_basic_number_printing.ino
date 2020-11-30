
//binary literal
byte binaryCounter = B00000000;

//deciaml literal
int decimalCounter = 0;

//octal literal
byte octalCounter = 00;


//hexa deciaml literal
byte hexaDeciamlCounter = 0x0;

const int DELAY_TIME = 500;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println();
  //binary number
  Serial.print("Binary \t");
  Serial.print(decimalCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print("Octal \t");
  Serial.print(decimalCounter, OCT);
  Serial.print("\t");
  //decimal number
  Serial.print("Decimal \t");
  Serial.print(decimalCounter, DEC);
  Serial.print("\t");
  // hexa decimal number
  Serial.print("HexaDecimal \t");
  Serial.print(decimalCounter, HEX);
  Serial.println();


  //binary number
  Serial.print("Binary \t");
  Serial.print(binaryCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print("Octal \t");
  Serial.print(binaryCounter, OCT);
  Serial.print("\t");
  //decimal number
  Serial.print("Decimal \t");
  Serial.print(binaryCounter, DEC);
  Serial.print("\t");
  // hexa decimal number
  Serial.print("HexaDecimal \t");
  Serial.print(binaryCounter, HEX);
  Serial.println();


  //binary number
  Serial.print("Binary \t");
  Serial.print(octalCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print("Octal \t");
  Serial.print(octalCounter, OCT);
  Serial.print("\t");
  //decimal number
  Serial.print("Decimal \t");
  Serial.print(octalCounter, DEC);
  Serial.print("\t");
  // hexa decimal number
  Serial.print("HexaDecimal \t");
  Serial.print(octalCounter, HEX);
  Serial.println();


  //binary number
  Serial.print("Binary \t");
  Serial.print(hexaDeciamlCounter, BIN);
  Serial.print("\t");
  //octal number
  Serial.print("Octal \t");
  Serial.print(hexaDeciamlCounter, OCT);
  Serial.print("\t");
  //decimal number
  Serial.print("Decimal \t");
  Serial.print(hexaDeciamlCounter, DEC);
  Serial.print("\t");
  // hexa decimal number
  Serial.print("HexaDecimal \t");
  Serial.print(hexaDeciamlCounter, HEX);
  Serial.println();

  binaryCounter++;
  decimalCounter++;
  octalCounter++;
  hexaDeciamlCounter++;

  delay(DELAY_TIME);
}
