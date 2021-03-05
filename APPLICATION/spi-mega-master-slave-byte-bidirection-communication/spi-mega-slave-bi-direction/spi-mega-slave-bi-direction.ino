/*
  PIN FOR COMMUNICATION IN ARDUINO MEGA
  MISO = 50 or ICSP-1
  MOSI = 51 or ICSP-4
  SCK = 52 or ICSP-3
  SS = 53

  PIN MAPPING
  MASTER    SLAVE
  50         50
  51         51
  52         52
  53         53
  GND        GND
*/

#include<SPI.h>

#define LED_PIN 7

volatile boolean dataToReceived;
volatile byte slaveReceived, slaveSend;
bool switchValue;
int x;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);                // Setting pin 7 as OUTPUT
  pinMode(MISO, OUTPUT);                  //Sets MISO as OUTPUT (Have to Send data to Master IN
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  dataToReceived = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
}

ISR (SPI_STC_vect) {                       //Inerrrput routine function
  slaveReceived = SPDR;                    // Value received from master if store in variable slavereceived
  dataToReceived = true;                        //Sets received as True
}

void loop() {

  if (dataToReceived) {                          //Logic to SET LED ON OR OFF depending upon the value recerived from master

    if (slaveReceived == 1) {
      digitalWrite(LED_PIN, HIGH);        //Sets pin 7 as HIGH LED ON
      Serial.println("Slave LED ON");
    } else {
      digitalWrite(LED_PIN, LOW);         //Sets pin 7 as LOW LED OFF
      Serial.println("Slave LED OFF");
    }

    if (switchValue) {
      x = 1;
      switchValue = false;
    } else {
      x = 0;
      switchValue = true;
    }
    slaveSend = x;
    SPDR = slaveSend;                           //Sends the x value to master via SPDR
    dataToReceived = false;
    delay(1000);
  }
}
