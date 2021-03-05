/*
  PIN FOR COMMUNICATION IN NODE MCU
  SCK =  D5 GPIO14 (HSCKL)
  MISO = D6 GPIO15 (HMISO)
  MOSI = D7 GPIO16 (HMOSI)
  SS =   D8 /GPIO 17(HCS)

  PIN FOR COMMUNICATION IN ARDUINO UNO
  MOSI = 11 or ICSP-4
  MISO = 12 or ICSP-1
  SCK = 13 or ICSP-3
  SS = 10

  PIN MAPPING
  NODE MCU SLAVE     UNO MASTER
  D5                  13
  D6                  12
  D7                  11
  D8                  10
  GND                 GND
*/

#include<SPI.h>
#define LED_PIN 7

const String MSG = " HI_RADHA_SINGH:";
const int dataSize = MSG.length();

char dataBuffer[20];
volatile byte index;
bool dataToReceived = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MISO, OUTPUT);                  //Sets MISO as OUTPUT (Have to Send data to Master IN
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  dataToReceived = false;
  SPI.attachInterrupt();
  index = -1;
}

ISR (SPI_STC_vect) {
  dataToReceived = true;
}

void loop() {
  //Serial.print("SLAVE ");
  //Serial.println(index);

  if (index == -1) {
    if (dataToReceived) {
      char requestInit = SPDR;
      if (requestInit == 'A') {
        SPDR = requestInit;
        index = 0;
      }
    }
  } else if (index != -1 && index < dataSize) {
    digitalWrite(LED_PIN, HIGH);   
    dataRecieved();
  } else {
    digitalWrite(LED_PIN, LOW);   
    index = 0;
    Serial.println(dataBuffer);
    for (int i = 0; i < 20 ; i++) {
      dataBuffer[i] = ' ';
    }
  }
}

void dataRecieved() {
  if (dataToReceived) {
    char received = SPDR;
    if (received != ':') {
      dataBuffer[index] = received;
      SPDR =  MSG[index];
      index += 1;
    } else {
      index = dataSize;
    }
    dataToReceived = false;
  }
}
