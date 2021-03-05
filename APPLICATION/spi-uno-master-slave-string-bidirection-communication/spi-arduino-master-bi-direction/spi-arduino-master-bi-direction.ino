/*
  PIN FOR COMMUNICATION IN ARDUINO UNO
  MOSI = 11 or ICSP-4
  MISO = 12 or ICSP-1
  SCK = 13 or ICSP-3
  SS = 10
  PIN MAPPING
  MASTER    SLAVE
  13         13
  12         12
  11         11
  10         10
  GND        GND
*/

#include<SPI.h>

const String MSG = "HI_ADARSH_KUMAR:";
const int dataSize = MSG.length();

char dataBuffer[20];
volatile byte index;

void setup (void) {
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS, HIGH);                 // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
  index = -1;
}

void loop(void) {
  //Serial.print("MASTER ");
  //Serial.println(index);

  digitalWrite(SS, LOW);
  if (index == -1) {
    char requestInit = 'A';
    char resposneInit = SPI.transfer(requestInit);
    if (resposneInit == 'A') {
      index = 0;
    }
  } else if (index != -1 && index < dataSize) {
    sendData(index);
    index += 1;
  } else {
    index = 0;
    Serial.println(dataBuffer);
    for (int i = 0; i < 20 ; i++) {
      dataBuffer[i] = ' ';
    }
  }
  digitalWrite(SS, HIGH);
}

void sendData(int index) {
  char masterSend, masterReceive;
  masterSend = MSG[index];
  masterReceive = SPI.transfer(masterSend);
  if (masterReceive != ':') {
    dataBuffer[index] = masterReceive;
    delay(5);
  } else {
    index = dataSize;
  }
}
