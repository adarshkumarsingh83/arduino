
const int FIRST_SENSOR = A0; // CURRENT BLOCK SENSOR 1 ON PIN AO
const int SECOUND_SENSOR = A1; // CURRENT BLOCK SENSOR 2 ON PIN A1

//FIRST LIGHT BLOCK SIGNAL
const int FIRST_GREEN = 2;
const int FIRST_YELLOW = 3;
const int FIRST_RED = 4;

//SECOUND LIGHT BLOCK SIGNAL
const int SECOUND_GREEN = 5;
const int SECOUND_YELLOW = 6;
const int SECOUND_RED = 7;

//PUBLISHING CHANNELS FOR OTHER BLOCKS
const int PREVIOUS_BLOCK_PUBLISHING_CHANNEL = 8; //PUBLISHING SINGAL TO PREVIOUS BLOCK SYAING CURRENT BLOCK IS OCCUPIED
const int NEXT_BLOCK_PUBLISHING_CHANNEL = 9; //PUBLISHING SINGAL TO NEXT BLOCK SYAING CURRENT BLOCK IS OCCUPIED

//RECIEVVING CHANNELS FROM OTHER BLOCKS
const int PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL = A2; //LISTENING SINGAL FROM PREVIOUS BLOCK SYAING PREVIOUS BLOCK IS OCCUPIED
const int NEXT_BLOCK_SUBSCRIPTION_CHANNEL = A3; //LISTENING SINGAL FROM NEXT BLOCK SYAING NEXT BLOCK IS OCCUPIED

enum SIGNAL_STATES {
  SATE_FIRST_GREEN_SECOUND_GREEN,
  SATE_FIRST_GREEN_SECOUND_YELLOW,
  SATE_FIRST_YELLOW_SECOUND_GREEN,
  SATE_FIRST_YELLOW_SECOUND_YELLOW,
  SATE_FIRST_RED_SECOUND_RED,
};


SIGNAL_STATES singnalState = SATE_FIRST_GREEN_SECOUND_GREEN;

int sensorFirst;
int sensorSecound;
int previousBlockOccupancySingal;
int nextBlockOccupancySingal;



void setup() {
  Serial.begin(9600);

  // SENSORS FOR BLOCK SINGAL INPUTS
  pinMode(FIRST_SENSOR, INPUT);
  pinMode(SECOUND_SENSOR, INPUT);

  // PREVIOUS AND NEXT BLOCKS SINGAL INPUTS SUBSCIPRITONS CHANNELS
  pinMode(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);
  pinMode(NEXT_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);

  // PRVIOUS AND NEXT BLOCK PUBLISHING CHANNELS FOR OUTPUT
  pinMode(PREVIOUS_BLOCK_PUBLISHING_CHANNEL, OUTPUT);
  pinMode(NEXT_BLOCK_PUBLISHING_CHANNEL, OUTPUT);

  // CURENT BLOCK FIRST SINGAL LIGHT
  pinMode(FIRST_GREEN, OUTPUT);
  pinMode(FIRST_YELLOW, OUTPUT);
  pinMode(FIRST_RED, OUTPUT);

  // CURENT BLOCK SECOUND  SINGAL LIGHT
  pinMode(SECOUND_GREEN, OUTPUT);
  pinMode(SECOUND_YELLOW, OUTPUT);
  pinMode(SECOUND_RED, OUTPUT);
}

void loop() {


  sensorFirst = analogRead(FIRST_SENSOR);
  sensorSecound = analogRead(SECOUND_SENSOR);
  previousBlockOccupancySingal = analogRead(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL);
  nextBlockOccupancySingal = analogRead(NEXT_BLOCK_SUBSCRIPTION_CHANNEL);

  Serial.println(sensorFirst);
  Serial.println(sensorSecound);
  Serial.println(previousBlockOccupancySingal);
  Serial.println(nextBlockOccupancySingal);

  switch (singnalState) {
    case SATE_FIRST_GREEN_SECOUND_GREEN:
      break;
    case SATE_FIRST_GREEN_SECOUND_YELLOW:
      break;
    case SATE_FIRST_YELLOW_SECOUND_GREEN:
      break;
    case SATE_FIRST_YELLOW_SECOUND_YELLOW:
      break;
    case SATE_FIRST_RED_SECOUND_RED:
      break;
  }
}

void firstGreenAndSecoundGreenSignal() {

}

void firstGreenAndSecoundYellowSignal() {

}

void firstYellowAndSecoundGreenSignal() {

}

void firstYellowAndSecoundYellowSignal() {

}

void firstRedAndSecoundRedSignal() {

}






// SETTING UP THE VALUES FOR CURRRENT BLOCK SIGNALS FIRST
void setSignalsFirst( int firstGreen,
                      int firstYellow,
                      int firstRed) {
  //LOW FOR ON HIGHT FOR OFF
  digitalWrite(FIRST_GREEN, firstGreen);
  digitalWrite(FIRST_YELLOW, firstYellow);
  digitalWrite(FIRST_RED, firstRed);
}

// SETTING UP THE VALUES FOR CURRRENT BLOCK SIGNALS SECOUND
void setSignalsSecound( int secoundGreen,
                        int secoundYellow,
                        int secoundRed) {
  //LOW FOR ON HIGHT FOR OFF
  digitalWrite(SECOUND_GREEN, secoundGreen);
  digitalWrite(SECOUND_YELLOW, secoundYellow);
  digitalWrite(SECOUND_RED, secoundRed);
}


// SETTING UP THE VALUES FOR CURRRENT BLOCK OCCUPANCY PUBLISHING TO CHANNALS FOR PREVIOUS AND NEXT BLOCK
void setPublishingChannelForAdjacentBlocks(int previousBlock,
                           int nextBlock) {
  analogWrite(CURRENT_BLOCK_OCCUPANCY_PUBLISHING_TO_PREVIOUS_BLOCK, previousBlock);
  analogWrite(CURRENT_BLOCK_OCCUPANCY_PUBLISHING_TO_NEXT_BLOCK, nextBlock);
}
