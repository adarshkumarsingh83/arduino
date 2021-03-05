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
  UNO SLAVE    MEGA MASTER
  13               52
  12               50
  11               51
  10               53
  GND              GND
*/

#include<SPI.h>
#define LED_PIN 7

bool switchValue = false;
int x;

void setup (void) {

  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200
  pinMode(LED_PIN, OUTPUT);                   //Sets pin 7 as Output
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS, HIGH);                 // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(void) {

  byte masterSend, masterReceive;

  if (switchValue) {              //Logic for Setting x value (To be sent to slave) depending upon input from pin 2
    x = 1;
    switchValue = false;
  } else {
    x = 0;
    switchValue = true;
  }

  digitalWrite(SS, LOW);                     //Starts communication with Slave connected to master
  masterSend = x;
  masterReceive = SPI.transfer(masterSend);  //Send the mastersend value to slave also receives value from slave

  if (masterReceive == 1) {                 //Logic for setting the LED output depending upon value received from slave
    digitalWrite(LED_PIN, HIGH);             //Sets pin 7 HIGH
    Serial.println("Master LED ON");

  } else {
    digitalWrite(LED_PIN, LOW);              //Sets pin 7 LOW
    Serial.println("Master LED OFF");
  }

  digitalWrite(SS, HIGH);
  delay(1000);
}
