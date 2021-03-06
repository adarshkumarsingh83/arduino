
#include "Pca9685.h"

int MAX_PINS = 16;
Pca9685 pca9685 = Pca9685();
void setup() {
  Serial.begin(9600);
  //setting board address
  pca9685.setBoardAddress(0x40);
  //setting board frequency
  pca9685.setPwmFrequency(50);
  //init the board
  pca9685.initPca9685();
  //setting up the range for open and close
  for (int i = 0; i < 16; i++) {
    pca9685.setSwitchOpenCloseRange(i, 100, 400);
  }
}

void loop() {

  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  //throwing switch on particular pin
  pca9685.throwSwitchPca9685Pin(pinNo);
  pca9685.displayPca9685PinState();
  delay(2000);
  //cloasing switch on particular pin
  pca9685.closeSwitchPca9685Pin(pinNo);
  pca9685.displayPca9685PinState();
  delay(2000);

}
