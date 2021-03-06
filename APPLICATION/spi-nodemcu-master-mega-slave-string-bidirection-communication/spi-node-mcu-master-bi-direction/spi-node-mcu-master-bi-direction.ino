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
  NODE MCU MASTER    UNO SLAVE
  D5                  13
  D6                  12
  D7                  11
  D8                  10
  GND                 GND
*/

#include<SPI.h>
#define LED_PIN 5

const String MSG = "HI_ADARSH_KUMAR:";
const int dataSize = MSG.length();

char dataBuffer[20];
volatile byte indexVar = -1;

void setup (void) {
  Serial.begin(115200);    
  pinMode(LED_PIN, OUTPUT); //Starts Serial Communication at Baud Rate 115200
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS, HIGH);                 // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
  indexVar = -1;
}

void loop(void) {
  //Serial.print("MASTER ");
  //Serial.println(index);

  digitalWrite(SS, LOW);
  if (indexVar == -1) {
    char requestInit = 'A';
    char resposneInit = SPI.transfer(requestInit);
    if (resposneInit == 'A') {
      indexVar = 0;
    }
  } else if (indexVar != -1 && indexVar < dataSize) {
    sendData(indexVar);
    indexVar += 1;
    digitalWrite(LED_PIN, HIGH);  
  } else {
    digitalWrite(LED_PIN, LOW);  
    indexVar = 0;
    Serial.println(dataBuffer);
    for (int i = 0; i < 20 ; i++) {
      dataBuffer[i] = ' ';
    }
  }
  digitalWrite(SS, HIGH);
}

void sendData(int indexVar) {
  char masterSend, masterReceive;
  masterSend = MSG[indexVar];
  masterReceive = SPI.transfer(masterSend);
  if (masterReceive != ':') {
    dataBuffer[indexVar] = masterReceive;
    delay(5);
  } else {
    indexVar = dataSize;
  }
}
