
#include "Config.h"
#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(RX_PIN, TX_PIN);
void setup() {
  softwareSerial.begin(COMMUNICATION_BROAD_RATE);
  Serial.begin(MESSAGE_BROAD_RATE);
}

void loop() {

  for (int i = 0; i < NODE_COUNT; i++) {
     softwareSerial.print(nodes[i].nodeNo);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].lightStartAddress);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].lightCount);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].signal2LedStartAddress);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].signal2LedCount);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].signal3LedAddress);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].signal3LedCount);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].turnoutServoSartAddress);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].turnoutServoCount);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].turnoutSnapSartAddress);
    softwareSerial.print(" ");
    softwareSerial.print(nodes[i].turnoutSnapCount);
    softwareSerial.println();

    Serial.print(nodes[i].nodeNo);
    Serial.print(" ");
    Serial.print(nodes[i].lightStartAddress);
    Serial.print(" ");
    Serial.print(nodes[i].lightCount);
    Serial.print(" ");
    Serial.print(nodes[i].signal2LedStartAddress);
    Serial.print(" ");
    Serial.print(nodes[i].signal2LedCount);
    Serial.print(" ");
    Serial.print(nodes[i].signal3LedAddress);
    Serial.print(" ");
    Serial.print(nodes[i].signal3LedCount);
    Serial.print(" ");
    Serial.print(nodes[i].turnoutServoSartAddress);
    Serial.print(" ");
    Serial.print(nodes[i].turnoutServoCount);
    Serial.print(" ");
    Serial.print(nodes[i].turnoutSnapSartAddress);
    Serial.print(" ");
    Serial.print(nodes[i].turnoutSnapCount);
    Serial.println(); 
  }

}
