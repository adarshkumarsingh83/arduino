
#include "Pcf8574.h"
#include "Pcf8574Board.h"

Pcf8574 pcf8574 = Pcf8574(0x20);

Pcf8574  pcf8574Array1[] = {Pcf8574(0x20)};
Pcf8574Board pcf8574Board1 = Pcf8574Board(pcf8574Array1, 1);

Pcf8574  pcf8574Array2[] = {Pcf8574(0x20), Pcf8574(0x21)};
Pcf8574Board pcf8574Board2 = Pcf8574Board(pcf8574Array2, 2);

Pcf8574  pcf8574Array3[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22)};
Pcf8574Board pcf8574Board3 = Pcf8574Board(pcf8574Array3, 3);

Pcf8574  pcf8574Array4[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22), Pcf8574(0x23)};
Pcf8574Board pcf8574Board4 = Pcf8574Board(pcf8574Array4, 4);

Pcf8574  pcf8574Array5[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22), Pcf8574(0x23), Pcf8574(0x24)};
Pcf8574Board pcf8574Board5 = Pcf8574Board(pcf8574Array5, 5);

Pcf8574  pcf8574Array6[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22), Pcf8574(0x23), Pcf8574(0x24), Pcf8574(0x25)};
Pcf8574Board pcf8574Board6 = Pcf8574Board(pcf8574Array6, 6);

Pcf8574  pcf8574Array7[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22), Pcf8574(0x23), Pcf8574(0x24), Pcf8574(0x25), Pcf8574(0x26)};
Pcf8574Board pcf8574Board7 = Pcf8574Board(pcf8574Array7, 7);

Pcf8574  pcf8574Array8[] = {Pcf8574(0x20), Pcf8574(0x21), Pcf8574(0x22), Pcf8574(0x23), Pcf8574(0x24), Pcf8574(0x25), Pcf8574(0x26), Pcf8574(0x27)};
Pcf8574Board pcf8574Board8 = Pcf8574Board(pcf8574Array8, 8);


void setup() {
  Serial.println("init");
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //pcf8574Boards1();
  pcf8574Boards2();
  //pcf8574Boards3();
  //pcf8574Boards4();
  //pcf8574Boards5();
  //pcf8574Boards6();
  //pcf8574Boards7();
  //pcf8574Boards8();
}


void pcf8574Boards1() {
  int pinNo = random(0, 8);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board1.switchOn(pinNo);
  pcf8574Board1.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board1.switchOff(pinNo);
  pcf8574Board1.displayPinState();
  delay(2000);
}
void pcf8574Boards2() {
  int pinNo = random(0, 16);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board2.switchOn(pinNo);
  pcf8574Board2.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board2.switchOff(pinNo);
  pcf8574Board2.displayPinState();
  delay(2000);
}
void pcf8574Boards3() {
  int pinNo = random(0, 24);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board3.switchOn(pinNo);
  pcf8574Board3.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board3.switchOff(pinNo);
  pcf8574Board3.displayPinState();
  delay(2000);
}
void pcf8574Boards4() {
  int pinNo = random(0, 32);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board4.switchOn(pinNo);
  pcf8574Board4.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board4.switchOff(pinNo);
  pcf8574Board4.displayPinState();
  delay(2000);
}
void pcf8574Boards5() {
  int pinNo = random(0, 40);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board5.switchOn(pinNo);
  pcf8574Board5.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board5.switchOff(pinNo);
  pcf8574Board5.displayPinState();
  delay(2000);
}
void pcf8574Boards6() {
  int pinNo = random(0, 48);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board6.switchOn(pinNo);
  pcf8574Board6.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board6.switchOff(pinNo);
  pcf8574Board6.displayPinState();
  delay(2000);
}
void pcf8574Boards7() {
  int pinNo = random(0, 56);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board7.switchOn(pinNo);
  pcf8574Board7.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board7.switchOff(pinNo);
  pcf8574Board7.displayPinState();
  delay(2000);
}
void pcf8574Boards8() {
  int pinNo = random(0, 63);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  digitalWrite(LED_BUILTIN, HIGH);
  pcf8574Board8.switchOn(pinNo);
  pcf8574Board8.displayPinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574Board8.switchOff(pinNo);
  pcf8574Board8.displayPinState();
  delay(2000);
}


void signalPcf8674() {
  digitalWrite(LED_BUILTIN, HIGH);
  int pinNo = random(0, 7);
  Serial.print("PinNo ");
  Serial.println(pinNo);
  pcf8574.switchPinOn(pinNo);
  pcf8574.displayPcf8574PinState();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  pcf8574.switchPinOff(pinNo);
  pcf8574.displayPcf8574PinState();
  delay(2000);
}
