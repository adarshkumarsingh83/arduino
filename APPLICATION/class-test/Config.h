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


class Config {

  public:
    int nodeNo;
    int lightStartAddress;         //  LIGHT STARTING ADDRESS
    int lightCount;                //  LIGHT COUNT
    int signal2LedStartAddress;    //  2LED SIGNAL STARTING ADDRESS
    int signal2LedCount;           //  2LED SIGNAL COUNT
    int signal3LedAddress;         //  3LED SIGNAL STARTING ADDRESS
    int signal3LedCount;           //  3LED SIGNAL COUNT
    int turnoutServoSartAddress;   //  SERVO TURNOUT STARTING ADDRESS
    int turnoutServoCount;         //  SERVO TURNOUT COUNT
    int turnoutSnapSartAddress;    //  SNAP TURNOUT STARTING ADDRESS
    int turnoutSnapCount;          //  SNAP TURNOUT COUNT

    int i;
    int *lightState;
    int *signal2LedState;
    int *signal3LedState;
    int *turnoutServoState;
    int *turnoutSnapState;

    void init() {
      this->lightState = new int[lightCount];
      for (i = 0; i < lightCount; i++) {
        this->lightState[i] = i;
      }
      this->signal2LedState = new int[signal2LedCount];
      for (i = 0; i < signal2LedCount; i++) {
        this->signal2LedState[i] = i;
      }
      this->signal3LedState = new int[signal3LedCount];
      for (i = 0; i < signal3LedCount; i++) {
        this->signal3LedState[i] = i;
      }
      this->turnoutServoState = new int[turnoutServoCount];
      for (i = 0; i < turnoutServoCount; i++) {
        this->turnoutServoState[i] = i;
      }
      this->turnoutSnapState = new int[turnoutSnapCount];
      for (i = 0; i < turnoutSnapCount; i++) {
        this->turnoutSnapState[i] = i;
      }
    }

};


#define NODE_COUNT 3

/*
  Config node1 =  Config {
  .nodeNo = 10,
  .lightStartAddress = 1,
  .lightCount = 1,
  .signal2LedStartAddress = 1,
  .signal2LedCount = 1,
  .signal3LedAddress = 1,
  .signal3LedCount = 1,
  .turnoutServoSartAddress = 1,
  .turnoutServoCount = 1,
  .turnoutSnapSartAddress = 1,
  .turnoutSnapCount = 1
  };

  Config node2 =  Config {
  .nodeNo = 20,
  .lightStartAddress = 2,
  .lightCount = 2,
  .signal2LedStartAddress = 2,
  .signal2LedCount = 2,
  .signal3LedAddress = 2,
  .signal3LedCount = 2,
  .turnoutServoSartAddress = 2,
  .turnoutServoCount = 2,
  .turnoutSnapSartAddress = 2,
  .turnoutSnapCount = 2,
  };

  Config node3 =  Config {
  .nodeNo = 30,
  .lightStartAddress = 3,
  .lightCount = 3,
  .signal2LedStartAddress = 3,
  .signal2LedCount = 3,
  .signal3LedAddress = 3,
  .signal3LedCount = 3,
  .turnoutServoSartAddress = 3,
  .turnoutServoCount = 3,
  .turnoutSnapSartAddress = 3,
  .turnoutSnapCount = 3,
  };

  const Config nodes[NODE_COUNT] = { node1, node2, node3};
*/

const Config nodes[NODE_COUNT] = {
  Config {
    .nodeNo = 10,
    .lightStartAddress = 1,
    .lightCount = 10,
    .signal2LedStartAddress = 200,
    .signal2LedCount = 20,
    .signal3LedAddress = 300,
    .signal3LedCount = 23,
    .turnoutServoSartAddress = 400,
    .turnoutServoCount = 5,
    .turnoutSnapSartAddress = 500,
    .turnoutSnapCount = 8
  },
  Config {
    .nodeNo = 20,
    .lightStartAddress = 2,
    .lightCount = 2,
    .signal2LedStartAddress = 2,
    .signal2LedCount = 2,
    .signal3LedAddress = 2,
    .signal3LedCount = 2,
    .turnoutServoSartAddress = 2,
    .turnoutServoCount = 2,
    .turnoutSnapSartAddress = 2,
    .turnoutSnapCount = 2,
  },
  Config {
    .nodeNo = 30,
    .lightStartAddress = 3,
    .lightCount = 3,
    .signal2LedStartAddress = 3,
    .signal2LedCount = 3,
    .signal3LedAddress = 3,
    .signal3LedCount = 3,
    .turnoutServoSartAddress = 3,
    .turnoutServoCount = 3,
    .turnoutSnapSartAddress = 3,
    .turnoutSnapCount = 3,
  }
};


#endif
