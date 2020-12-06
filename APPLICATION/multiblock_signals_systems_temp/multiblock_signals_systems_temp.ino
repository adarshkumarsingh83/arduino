const int FORWARD_SENSOR = A0; //Sensor 1 is setup on pin A0
const int BACKWARD_SENSOR = A1; //Sensor 2 is setup on pin A1
const int FORWARD_GREEN = 2; // Green Signal 1 is digital pin 2
const int FORWARD_YELLOW = 3;// Yellow Signal 1 is digital pin 3
const int FORWARD_RED = 4;// Red Signal 1 is digital pin 4
const int BACKWARD_GREEN = 5;// Green Signal 2 is digital pin 5
const int BACKWARD_YELLOW = 6;// Yellow Signal 1 is digital pin 6
const int BACKWARD_RED = 7;//Red Signal 2 is digital pin 7
const int PREVIOUS_BLOCK_PUBLISHING_CHANNEL = 8; // The transmit pin for the previous block in the sequence
const int NEXT_BLOCK_PUBLISHING_CHANNEL = 9; // The transmit pin for the next block in the sequence
const int PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL = A2; // The recieve pin for the previous block in the sequence
const int NEXT_BLOCK_SUBSCRIPTION_CHANNEL = A3; // The recieve pin for the next block in the sequence

const int DELAY_TIME = 500;
const int OCCUPIED_SINGAL = 1023;
const int UNOCCUPIED_SINGAL = 0;

int forwardSensor;
int backwardSensor;
int previousBlockOccupancySignal;
int nextBlockOccupancySignal;

enum SIGNAL_STATES {
  ST_FORWARD_GREEN_BACKWARD_GREEN,
  ST_FORWARD_GREEN_BACKWARD_YELLOW,
  ST_FORWARD_YELLOW_BACKWARD_GREEN,
  ST_FORWARD_YELLOW_BACKWARD_YELLOW,
  ST_FORWARD_RED_BACKWARD_RED_1,
  ST_FORWARD_RED_BACKWARD_RED_2,
  ST_FORWARD_RED_BACKWARD_RED_3,
}; //Sets up different signal states for the entire program

SIGNAL_STATES signalState = ST_FORWARD_GREEN_BACKWARD_GREEN; //Sets default state to Green and Green

void setup() {
  Serial.begin(9600);

  //Establish all of our pins at inputs or outputs

  pinMode(FORWARD_SENSOR, INPUT);
  pinMode(BACKWARD_SENSOR, INPUT);
  pinMode(FORWARD_GREEN, OUTPUT);
  pinMode(FORWARD_YELLOW, OUTPUT);
  pinMode(FORWARD_RED, OUTPUT);
  pinMode(BACKWARD_GREEN, OUTPUT);
  pinMode(BACKWARD_YELLOW, OUTPUT);
  pinMode(BACKWARD_RED, OUTPUT);
  pinMode(PREVIOUS_BLOCK_PUBLISHING_CHANNEL, OUTPUT);
  pinMode(NEXT_BLOCK_PUBLISHING_CHANNEL, OUTPUT);
  pinMode(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);
  pinMode(NEXT_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);

}

void loop() {

  forwardSensor = analogRead(FORWARD_SENSOR);
  backwardSensor = analogRead(BACKWARD_SENSOR);

  previousBlockOccupancySignal = analogRead(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL);
  nextBlockOccupancySignal = analogRead(NEXT_BLOCK_SUBSCRIPTION_CHANNEL);

  // Sets up the values of the different signals we will be reading
  Serial.println(forwardSensor);
  Serial.println(backwardSensor);
  Serial.println(previousBlockOccupancySignal);
  Serial.println(nextBlockOccupancySignal);

  // Sets up the different values to be read on the serial monitor in the Arduino IDE
  delay(DELAY_TIME);

  switch (signalState) {

    case ST_FORWARD_GREEN_BACKWARD_GREEN:
      forwardGreenBackwardGreenSignal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_GREEN_BACKWARD_YELLOW:
      forwardGreenBackwardYellowSignal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_YELLOW_BACKWARD_GREEN:
      forwardYellowBackwardGreenSignal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_YELLOW_BACKWARD_YELLOW:
      forwardYellowBackwardYellowSignal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_RED_BACKWARD_RED_1:
      forwardRedBackwardRed1Signal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_RED_BACKWARD_RED_2:
      forwardRedBackwardRed2Signal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
    case ST_FORWARD_RED_BACKWARD_RED_3:
      forwardRedBackwardRed3Signal(forwardSensor, backwardSensor, previousBlockOccupancySignal, nextBlockOccupancySignal);
      break;
      //this sets up our different loops within the main loop for our different signal states
  }
}

void forwardGreenBackwardGreenSignal(int forwardSensor
                                     , int backwardSensor
                                     , int previousBlockOccupancySignal
                                     , int nextBlockOccupancySignal) {

  setForwardSignals( LOW, HIGH, HIGH);
  setBackwardSignals(LOW, HIGH, HIGH);
  setPublishingChannelForAdjacentBlocks(UNOCCUPIED_SINGAL, UNOCCUPIED_SINGAL);

  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor > 500)) {
    if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_YELLOW;//block not occupied but Block B is
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_GREEN;//block not occupied but Block A is
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_YELLOW;//block not occupied but Block B and Block A are
    }
  } else if ((forwardSensor < 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_1;// block is occupied entered from FORWARD_SENSOR
  } else if ((forwardSensor > 500) && (backwardSensor < 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_2;// block is occupied entered from BACKWARD_SENSOR
  }
}

void forwardGreenBackwardYellowSignal(int forwardSensor
                                      , int backwardSensor
                                      , int previousBlockOccupancySignal
                                      , int nextBlockOccupancySignal) {
  setForwardSignals( LOW, HIGH, HIGH);
  setBackwardSignals(HIGH, LOW, HIGH);
  setPublishingChannelForAdjacentBlocks(0, 0);
  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor > 500)) {
    if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_GREEN;//block not occupied No adjacent blocks occupied
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_GREEN;//block not occupied but Block A is
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_YELLOW;//block not occupied but Block B and Block A are
    }
  } else if ((forwardSensor < 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_1;// block is occupied entered from FORWARD_SENSOR
  } else if ((forwardSensor > 500) && (backwardSensor < 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_2;// block is occupied entered from BACKWARD_SENSOR
  }
}

void forwardYellowBackwardGreenSignal(int forwardSensor
                                      , int backwardSensor
                                      , int previousBlockOccupancySignal
                                      , int nextBlockOccupancySignal) {
  setForwardSignals( HIGH, LOW, HIGH);
  setBackwardSignals(LOW, HIGH, HIGH);
  setPublishingChannelForAdjacentBlocks(UNOCCUPIED_SINGAL, UNOCCUPIED_SINGAL);
  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor > 500)) {
    if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_GREEN;//block not occupied No adjacent blocks occupied
    } else if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_YELLOW;//block not occupied but Block B is
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_YELLOW;//block not occupied but Block B and Block A are
    }
  } else if ((forwardSensor < 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_1;// block is occupied entered from FORWARD_SENSOR
  } else if ((forwardSensor > 500) && (backwardSensor < 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_2;// block is occupied entered from BACKWARD_SENSOR
  }
}

void forwardYellowBackwardYellowSignal(int forwardSensor
                                       , int backwardSensor
                                       , int previousBlockOccupancySignal
                                       , int nextBlockOccupancySignal) {
  setForwardSignals( HIGH, LOW, HIGH);
  setBackwardSignals(HIGH, LOW, HIGH);
  setPublishingChannelForAdjacentBlocks(UNOCCUPIED_SINGAL, UNOCCUPIED_SINGAL);
  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor > 500)) {
    if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_GREEN;//block not occupied No adjacent blocks occupied
    } else if ((previousBlockOccupancySignal < 300) && (nextBlockOccupancySignal > 300)) {
      signalState = ST_FORWARD_GREEN_BACKWARD_YELLOW;//block not occupied but Block B is
    } else if ((previousBlockOccupancySignal > 300) && (nextBlockOccupancySignal < 300)) {
      signalState = ST_FORWARD_YELLOW_BACKWARD_GREEN;//block not occupied but Block B and Block A are
    }
  } else if ((forwardSensor < 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_1;// block is occupied entered from FORWARD_SENSOR
  } else if ((forwardSensor > 500) && (backwardSensor < 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_2;// block is occupied entered from BACKWARD_SENSOR
  }
}

void forwardRedBackwardRed1Signal(int forwardSensor
                                  , int backwardSensor
                                  , int previousBlockOccupancySignal
                                  , int nextBlockOccupancySignal) {

  setForwardSignals( HIGH, HIGH, LOW);
  setBackwardSignals(HIGH, HIGH, LOW);
  setPublishingChannelForAdjacentBlocks(OCCUPIED_SINGAL, OCCUPIED_SINGAL);
  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor < 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_3; //switched to transition Red signal state
  }
}

void forwardRedBackwardRed2Signal(int forwardSensor
                                  , int backwardSensor
                                  , int previousBlockOccupancySignal
                                  , int nextBlockOccupancySignal) {

  setForwardSignals( HIGH, HIGH, LOW);
  setBackwardSignals(HIGH, HIGH, LOW);
  setPublishingChannelForAdjacentBlocks(OCCUPIED_SINGAL, OCCUPIED_SINGAL);
  delay(DELAY_TIME);

  if ((forwardSensor < 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_RED_BACKWARD_RED_3; //switched to transition Red signal state
  }
}

void forwardRedBackwardRed3Signal(int forwardSensor
                                  , int backwardSensor
                                  , int previousBlockOccupancySignal
                                  , int nextBlockOccupancySignal) {

  setForwardSignals( HIGH, HIGH, LOW);
  setBackwardSignals(HIGH, HIGH, LOW);
  setPublishingChannelForAdjacentBlocks(OCCUPIED_SINGAL, OCCUPIED_SINGAL);
  delay(DELAY_TIME);

  if ((forwardSensor > 500) && (backwardSensor > 500)) {
    signalState = ST_FORWARD_GREEN_BACKWARD_GREEN; //switched to Green unoccupied signal
  }
}


/*----------------------------------------------------------------------------------------------------------------------*/
//        UTILITY METHOD FOR SETTING UP THE VALUES FOR THE LED LIGHTS AND OUTPUT PINS FOR OTHER BLOCKS
/*----------------------------------------------------------------------------------------------------------------------*/
// SETTING UP THE VALUES FOR CURRRENT BLOCK FORWARD SIGNALS FIRST
void setForwardSignals( int forwardGreen,
                        int forwardYellow,
                        int forwardRed) {
  //LOW FOR ON HIGH FOR OFF
  digitalWrite(FORWARD_GREEN, forwardGreen);
  digitalWrite(FORWARD_YELLOW, forwardYellow);
  digitalWrite(FORWARD_RED, forwardRed);
}

// SETTING UP THE VALUES FOR CURRRENT BLOCK BACKWARD SIGNALS SECOUND
void setBackwardSignals( int backwardGreen,
                         int backwardYellow,
                         int backwardRed) {
  //LOW FOR ON HIGH FOR OFF
  digitalWrite(BACKWARD_GREEN, backwardGreen);
  digitalWrite(BACKWARD_YELLOW, backwardYellow);
  digitalWrite(BACKWARD_RED, backwardRed);
}


// SETTING UP THE VALUES FOR CURRRENT BLOCK OCCUPANCY PUBLISHING TO CHANNELS FOR PREVIOUS AND NEXT BLOCK
void setPublishingChannelForAdjacentBlocks(int previousBlockPublishingChannel,
    int nextBlockPublishingChannel) {
  analogWrite(PREVIOUS_BLOCK_PUBLISHING_CHANNEL, previousBlockPublishingChannel);
  analogWrite(NEXT_BLOCK_PUBLISHING_CHANNEL, nextBlockPublishingChannel);
}
