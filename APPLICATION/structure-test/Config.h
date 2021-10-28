/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshmodeltrains@gmail.com
*/

#ifndef Config_h
#define Config_h

#include <Arduino.h>

#define DELEY_TIME 100
#define MESSAGE_BROAD_RATE 4800
#define COMMUNICATION_BROAD_RATE 115200
#define RX_PIN 7
#define TX_PIN 8
/*

    JMRI ADDRESS 100  -> 499   SNAP SWITCHES  => 399
    JMRI ADDRESS 500  -> 999   SERVO SWITCHES => 499
    JMRI ADDRESS 1000 -> 1499  2LED SIGNALS   => 499
    JMRI ADDRESS 1500 -> 1999  3LED SIGNALS   => 499
    JMRI ADDRESS 2000 -> 2048  LIGHTS         => 48

*/


typedef struct Node {
  const int nodeNo;
  const int lightStartAddress;         //  LIGHT STARTING ADDRESS
  const int lightCount;                //  LIGHT COUNT
  const int signal2LedStartAddress;    //  2LED SIGNAL STARTING ADDRESS
  const int signal2LedCount;           //  2LED SIGNAL COUNT
  const int signal3LedAddress;         //  3LED SIGNAL STARTING ADDRESS
  const int signal3LedCount;           //  3LED SIGNAL COUNT
  const int turnoutServoSartAddress;   //  SERVO TURNOUT STARTING ADDRESS
  const int turnoutServoCount;         //  SERVO TURNOUT COUNT
  const int turnoutSnapSartAddress;    //  SNAP TURNOUT STARTING ADDRESS
  const int turnoutSnapCount;          //  SNAP TURNOUT COUNT
};


#define NODE_COUNT 3

const Node nodes[NODE_COUNT] = {
  {
    .nodeNo = 1,
    .lightStartAddress = 0,
    .lightCount = 0,
    .signal2LedStartAddress = 0,
    .signal2LedCount = 0,
    .signal3LedAddress = 0,
    .signal3LedCount = 0,
    .turnoutServoSartAddress = 0,
    .turnoutServoCount = 0,
    .turnoutSnapSartAddress = 0,
    .turnoutSnapCount = 0
  },
  {
    .nodeNo = 2,
    .lightStartAddress = 0,
    .lightCount = 0,
    .signal2LedStartAddress = 0,
    .signal2LedCount = 0,
    .signal3LedAddress = 0,
    .signal3LedCount = 0,
    .turnoutServoSartAddress = 0,
    .turnoutServoCount = 0,
    .turnoutSnapSartAddress = 0,
    .turnoutSnapCount = 0
  },
  {
    .nodeNo = 3,
    .lightStartAddress = 0,
    .lightCount = 0,
    .signal2LedStartAddress = 0,
    .signal2LedCount = 0,
    .signal3LedAddress = 0,
    .signal3LedCount = 0,
    .turnoutServoSartAddress = 0,
    .turnoutServoCount = 0,
    .turnoutSnapSartAddress = 0,
    .turnoutSnapCount = 0
  }
};
#endif
