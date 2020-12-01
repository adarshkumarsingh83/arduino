#include <LiquidCrystal.h>

const int lcdRSPin = 7;
const int lcdENPin = 8;
const int lcdD4Pin = 9;
const int lcdD5Pin = 10;
const int lcdD6Pin = 11;
const int lcdD7Pin = 12;

//lcd object creation
const LiquidCrystal lcd(lcdRSPin, lcdENPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void setup() {
  Serial.begin(9600);
  //lcd 2row 16collumn defined
  lcd.begin(16, 2);
}

void loop() {

  // set the cursor to the colum 0 and row 0 postion
  lcd.setCursor(0, 0);
  //printing into the lcd;
  lcd.print("adarsh kumar");
  // set the cursor to the  colum 0 and row 1 postion
  lcd.setCursor(0, 1);
  //printing into the lcd;
  lcd.print("love you radha  ");
  delay(1000);
  lcd.clear();
}
