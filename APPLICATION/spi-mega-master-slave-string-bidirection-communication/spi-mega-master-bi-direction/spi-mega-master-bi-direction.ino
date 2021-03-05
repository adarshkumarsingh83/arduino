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

const String MSG = "HI_ADARSH_KUMAR:";
const int dataSize = MSG.length();

char dataBuffer[20];
volatile byte index;

void setup (void) {
  Serial.begin(115200);                   
  pinMode(LED_PIN, OUTPUT);  
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
    digitalWrite(LED_PIN, HIGH);  
  } else {
    index = 0;
    digitalWrite(LED_PIN, LOW);  
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
