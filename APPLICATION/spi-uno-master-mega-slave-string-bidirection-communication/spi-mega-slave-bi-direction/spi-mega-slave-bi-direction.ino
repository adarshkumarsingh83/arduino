/*
  PIN FOR COMMUNICATION IN ARDUINO MEGA
  MISO = 50 or ICSP-1
  MOSI = 51 or ICSP-4
  SCK = 52 or ICSP-3
  SS = 53
  
  #PIN FOR COMMUNICATION IN ARDUINO UNO
  MOSI = 11 or ICSP-4
  MISO = 12 or ICSP-1
  SCK = 13 or ICSP-3
  SS = 10
  
  #PIN MAPPING
  UNO MASTER    MEGA SLAVE
  13               52
  12               50
  11               51
  10               53
  GND              GND
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
    dataRecieved();
    digitalWrite(LED_PIN, HIGH);  
  } else {
    index = 0;
    digitalWrite(LED_PIN, LOW);  
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
