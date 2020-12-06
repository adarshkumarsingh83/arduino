/*
   NOTE
   1. SINGNAL CODE SEND FROM ONE BLOCK TO OTHER BLOCK
      400 FOR RED, 600 FOR YELLOW, 1000 FOR GREEN
   2. CURRENT BLOCK IS ALWAYS POINT OF REFERENCE FOR THE PROCESSING
   3. SIGNAL FROM PREVIOUS BLOCK FOR FORWARD SIGNAL
      SIGNAL FROM NEXT BLOCK FOR BACKWARD SIGNAL


   1 CASE FORWARD_GREEN_BACKWARD_GREEN
      SIGNAL TO PREVIOUS BLOCK 1000
      SIGNAL TO NEXT BLOCK 1000
      SIGNAL FROM PREVIOUS BLOCK 1000
      SINGAL FROM NEXT BLOCK 1000

            EMPTY                              EMPTY                                EMPTY
     G                                    G                                    G            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              G                                    G                                   G

    2 CASE
    FORWARD_RED_AND_BACKWARD_GREEN
    SIGNAL FROM PREVIOUS BLOCK 400
    SINGAL TO NEXT BLOCK 600
    SIGNAL FROM PREVIOUS BLOCK 1000
    SIGNAL FROM NEXT BLOCK 1000

          NON EMPTY                              EMPTY                                EMMPTY
     G                                    R                                    Y            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              G                                    G                                   G

    3 CASE
      FORWARD_GREEN_AND_BACKWARD_GREEN_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 1000
      SIGNAL FROM NEXT BLOCK 1000

          EMPTY                                 NON EMPTY                            EMPTY
     G                                    G                                    R           <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    G                                   G

    4 CASE
     FORWRD_GREEN_AND_BACKWARD_RED
     SIGNAL TO PREVIOUS BLOCK 600
     SIGNAL TO NEXT BLOCK 1000
     SIGNAL FROM PREVIOUS BLOCK 1000
     SIGNAL FROM NEXT BLOCK 400

          EMPTY                                  EMPTY                              NON EMPTY
     G                                    G                                    G            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              Y                                    R                                   G

    5 CASE
      FORWARD_RED_AND_BACKWARD_RED
      SIGNAL TO PREVIOUS BLOCK 600
      SIGNAL TO NEXT BLOCK     600
      SIGNAL FROM PREVIOUS BLOCK 400
      SIGNAL FROM NEXT BLOCK  400

         NON EMPTY                              EMPTY                                NON EMPTY
     G                                    R                                    Y            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              Y                                    R                                    G

    6 CASE
     FORWARD_RED_AND_BACKWARD_GREEN_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 400
      SIGNAL FROM NEXT BLOCK 1000

         NON EMPTY                              NON EMPTY                           EMPTY
     G                                    R                                    R            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    G                                    G

    7 CASE
     FORWARD_GREEN_AND_BACKWARD_RED_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 1000
      SIGNAL FROM NEXT BLOCK 400

          EMPTY                                 NON EMPTY                           NON EMPTY
     G                                     G                                    R            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    R                                    G

    8 CASE
     FORWARD_RED_AND_BACKWARD_RED_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 400
      SIGNAL FROM NEXT BLOCK 400

           NON EMPTY                           NON EMPTY                             NON EMPTY
     G                                     R                                    R            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    R                                    G
*/

// CURRENT BLOCK FORWARD AND BACKWARD SENSOR PIN CONFIGURATION
const int FORWARD_SENSOR = A0; // CURRENT BLOCK FORWRD SENSOR 1 ON PIN AO
const int BACKWARD_SENSOR = A1; // CURRENT BLOCK BACKWARD SENSOR 2 ON PIN A1

// FIRST/FORWARD LIGHT BLOCK SIGNAL
const int FORWARD_GREEN = 2;
const int FORWARD_YELLOW = 3;
const int FORWARD_RED = 4;

// SECOUND/BACKWARD LIGHT BLOCK SIGNAL
const int BACKWARD_GREEN = 5;
const int BACKWARD_YELLOW = 6;
const int BACKWARD_RED = 7;

// PUBLISHING CHANNELS FOR OTHER BLOCKS
const int PREVIOUS_BLOCK_PUBLISHING_CHANNEL = 8; //PUBLISHING SINGAL TO PREVIOUS BLOCK SYAING CURRENT BLOCK IS OCCUPIED
const int NEXT_BLOCK_PUBLISHING_CHANNEL = 9; //PUBLISHING SINGAL TO NEXT BLOCK SYAING CURRENT BLOCK IS OCCUPIED

// RECIVEING CHANNELS FROM OTHER BLOCKS
const int PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL = A2; //LISTENING SINGAL FROM PREVIOUS BLOCK SYAING PREVIOUS BLOCK IS OCCUPIED
const int NEXT_BLOCK_SUBSCRIPTION_CHANNEL = A3; //LISTENING SINGAL FROM NEXT BLOCK SYAING NEXT BLOCK IS OCCUPIED

// VALUES PUBLISHING FOR OTHER BLOCKS FOR DIFFERENT TYPES OF LIGHTS
const int RED_SIGNAL_VALUE = 400;
const int YELLOW_SIGNAL_VALIUE = 600;
const int GREEN_SIGNAL_VALUE = 1000;

const int DELAY_TIME = 500;


enum SIGNAL_STATES {

  // CASE 1  WHEN CURRENT AND PREVIOUS AND NEXT BLOCK IS EMPTY
  FOWARD_GREEN_BACKWARD_GREEN,

  // CASE 2 WHEN CURRENT AND NEXT BLOCK BLOCK IS EMPTY AND PREVIOUS IS NOT EMPTY
  FOWARD_RED_BACKWARD_GREEN,

  // CASE 3 WHEN PREVIOUS AND NEXT BLOCK IS EMPTY AND CURRENT BLOCK IS NOT EMPTY
  FORWARD_GREEN_AND_BACKWARD_GREEN_1,

  // CASE 4 WHEN PREVIOUS AND CURRENT BLOCK EMPTY AND NEXT BLOCK IS NOT EMPTY
  FORWRD_GREEN_AND_BACKWARD_RED,

  // CASE 5 WHEN CURRENT BLOCK IS EMPTY AND PREVIOUS AND NEXT BLOCK IS NOT EMPTY
  FORWARD_RED_AND_BACKWARD_RED,

  // CASE 6 WHEN PREVIOUS AND CURRENT IS EMPTY AND NEXT BLOCK IS NOT EMPTY
  FORWARD_RED_AND_BACKWARD_GREEN_1,

  // CASE 7 WHEN PREVIOUS IS EMPTY AND CURRENT AND NEXT BLOCK IS NOT EMPTY
  FORWARD_GREEN_AND_BACKWARD_RED_1,

  // CASE 8 WHEN PREVUIOS CURRENT AND NEXT IS NOT EMPTY
  FORWARD_RED_AND_BACKWARD_RED_1
};



SIGNAL_STATES singnalState = FOWARD_GREEN_BACKWARD_GREEN;
int forwardSensor;
int backwardSensor;
int previousBlockOccupancySingal;
int nextBlockOccupancySingal;



void setup() {
  Serial.begin(9600);

  // SENSORS FOR BLOCK SINGAL INPUTS
  pinMode(FORWARD_SENSOR, INPUT);
  pinMode(BACKWARD_SENSOR, INPUT);

  // PREVIOUS AND NEXT BLOCKS SINGAL INPUTS SUBSCIPRITONS CHANNELS
  pinMode(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);
  pinMode(NEXT_BLOCK_SUBSCRIPTION_CHANNEL, INPUT);

  // PRVIOUS AND NEXT BLOCK PUBLISHING CHANNELS FOR OUTPUT
  pinMode(PREVIOUS_BLOCK_PUBLISHING_CHANNEL, OUTPUT);
  pinMode(NEXT_BLOCK_PUBLISHING_CHANNEL, OUTPUT);

  // CURENT BLOCK FORWARD/FIRST SINGAL LIGHT
  pinMode(FORWARD_GREEN, OUTPUT);
  pinMode(FORWARD_YELLOW, OUTPUT);
  pinMode(FORWARD_RED, OUTPUT);

  // CURENT BLOCK BACKWARD/SECOUND SINGAL LIGHT
  pinMode(BACKWARD_GREEN, OUTPUT);
  pinMode(BACKWARD_YELLOW, OUTPUT);
  pinMode(BACKWARD_RED, OUTPUT);
}

void loop() {


  forwardSensor = analogRead(FORWARD_SENSOR);
  backwardSensor = analogRead(BACKWARD_SENSOR);
  previousBlockOccupancySingal = analogRead(PREVIOUS_BLOCK_SUBSCRIPTION_CHANNEL);
  nextBlockOccupancySingal = analogRead(NEXT_BLOCK_SUBSCRIPTION_CHANNEL);

  Serial.println(forwardSensor);
  Serial.println(backwardSensor);
  Serial.println(previousBlockOccupancySingal);
  Serial.println(nextBlockOccupancySingal);

  switch (singnalState) {

    // CASE 1  WHEN CURRENT AND PREVIOUS AND NEXT BLOCK IS EMPTY
    case FOWARD_GREEN_BACKWARD_GREEN:
      forwardGreenAndBackwardGreenSignal(forwardSensor
                                         , backwardSensor
                                         , previousBlockOccupancySingal
                                         , nextBlockOccupancySingal);
      break;

    // CASE 2 WHEN CURRENT AND NEXT BLOCK BLOCK IS EMPTY AND PREVIOUS IS NOT EMPTY
    case FOWARD_RED_BACKWARD_GREEN:
      forwardRedAndBackwardGreenSignal(forwardSensor
                                       , backwardSensor
                                       , previousBlockOccupancySingal
                                       , nextBlockOccupancySingal);
      break;

    // CASE 3 WHEN PREVIOUS AND NEXT BLOCK IS EMPTY AND CURRENT BLOCK IS NOT EMPTY
    case FORWARD_GREEN_AND_BACKWARD_GREEN_1:
      forwardRedAndBackwardGreen1Signal(forwardSensor
                                        , backwardSensor
                                        , previousBlockOccupancySingal
                                        , nextBlockOccupancySingal);
      break;

    // CASE 4 WHEN PREVIOUS AND CURRENT BLOCK EMPTY AND NEXT BLOCK IS NOT EMPTY
    case FORWRD_GREEN_AND_BACKWARD_RED:
      forwardGreenAndBackwardRed(forwardSensor
                                 , backwardSensor
                                 , previousBlockOccupancySingal
                                 , nextBlockOccupancySingal);
      break;

    // CASE 5 WHEN CURRENT BLOCK IS EMPTY AND PREVIOUS AND NEXT BLOCK IS NOT EMPTY
    case FORWARD_RED_AND_BACKWARD_RED:
      forwardRedAndBackwardRed(forwardSensor
                               , backwardSensor
                               , previousBlockOccupancySingal
                               , nextBlockOccupancySingal);
      break;

    // CASE 6 WHEN PREVIOUS AND CURRENT IS EMPTY AND NEXT BLOCK IS NOT EMPTY
    case FORWARD_RED_AND_BACKWARD_GREEN_1:
      forwardRedAndBackwardGreen1(forwardSensor
                                  , backwardSensor
                                  , previousBlockOccupancySingal
                                  , nextBlockOccupancySingal);
      break;

    // CASE 7 WHEN PREVIOUS IS EMPTY AND CURRENT AND NEXT BLOCK IS NOT EMPTY
    case FORWARD_GREEN_AND_BACKWARD_RED_1:
      forwardGreenAndBackwardRed1(forwardSensor
                                  , backwardSensor
                                  , previousBlockOccupancySingal
                                  , nextBlockOccupancySingal);
      break;

    // CASE 8 WHEN PREVUIOS CURRENT AND NEXT IS NOT EMPTY
    case FORWARD_RED_AND_BACKWARD_RED_1:
      forwardRedAndBackwardRed1(forwardSensor
                                , backwardSensor
                                , previousBlockOccupancySingal
                                , nextBlockOccupancySingal);
      break;
  }
}


// WHEN CURRENT AND PREVIOUS AND NEXT BLOCK IS EMPTY
/*
   1 CASE
      FORWARD_GREEN_BACKWARD_GREEN
      SIGNAL TO PREVIOUS BLOCK 1000
      SIGNAL TO NEXT BLOCK 1000
      SIGNAL FROM PREVIOUS BLOCK 1000
      SINGAL FROM NEXT BLOCK 1000
            EMPTY                              EMPTY                                EMPTY
     G                                    G                                    G            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              G                                    G                                   G
*/
void forwardGreenAndBackwardGreenSignal(int forwardSensor
                                        , int backwardSensor
                                        , int previousBlockOccupancySingal
                                        , int nextBlockOccupancySingal) {
  setForwardSignals(LOW, HIGH, HIGH);
  setBackwardSignals(LOW, HIGH, HIGH);
  setPublishingChannelForAdjacentBlocks(GREEN_SIGNAL_VALUE, GREEN_SIGNAL_VALUE);
  delay(DELAY_TIME);
  if (forwardSensor > 500 && backwardSensor > 500 ) {

    if (previousBlockOccupancySingal == GREEN_SIGNAL_VALUE && nextBlockOccupancySingal == GREEN_SIGNAL_VALUE) {
      // PREVIOUS CURRENT AND NEXT BLOCK IS NOT OCCUPIED
      singnalState = FORWARD_GREEN_BACKWARD_GREEN;
      setPublishingChannelForAdjacentBlocks(GREEN_SIGNAL_VALUE, GREEN_SIGNAL_VALUE);
    } else if (previousBlockOccupancySingal == YELLOW_SIGNAL_VALIUE && nextBlockOccupancySingal == GREEN_SIGNAL_VALUE) {
      // BLOCK AHEAD OF PREVUIOS BLOCK IS OCCUPIED 
      
    } else if (previousBlockOccupancySingal == RED_SIGNAL_VALUE && nextBlockOccupancySingal == GREEN_SIGNAL_VALUE) {
      //PREVIOUS BLOCK IS OCCUPIED 
    }

  } else if (forwardSensor < 500 && backwardSensor > 500) {
    // CURRENT BLOCK IS STARTED TO FILL FROM FORWARD SIDE

  } else if (forwardSensor > 500 && backwardSensor < 500) {
    // CURRENT BLOCK IS STARTED TO FILL FROM BACKWARD SIDE
  }
}

// WHEN CURRENT AND NEXT BLOCK BLOCK IS EMPTY AND PREVIOUS IS NOT EMPTY
/*
  2 CASE
    FORWARD_RED_AND_BACKWARD_GREEN
    SIGNAL FROM PREVIOUS BLOCK 400
    SINGAL TO NEXT BLOCK 600
    SIGNAL FROM PREVIOUS BLOCK 1000
    SIGNAL FROM NEXT BLOCK 1000
          NON EMPTY                              EMPTY                                EMMPTY
     G                                    R                                    Y            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              G                                    G                                   G
*/
void forwardRedAndBackwardGreenSignal(int forwardSensor
                                      , int backwardSensor
                                      , int previousBlockOccupancySingal
                                      , int nextBlockOccupancySingal) {

}


// WHEN PREVIOUS AND NEXT BLOCK IS EMPTY AND CURRENT BLOCK IS NOT EMPTY
/*
  3 CASE
      FORWARD_GREEN_AND_BACKWARD_GREEN_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 1000
      SIGNAL FROM NEXT BLOCK 1000
          EMPTY                                 NON EMPTY                            EMPTY
     G                                    G                                    R           <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    G                                   G
*/
void forwardRedAndBackwardGreen1Signal(int forwardSensor
                                       , int backwardSensor
                                       , int previousBlockOccupancySingal
                                       , int nextBlockOccupancySingal) {

}


// WHEN PREVIOUS AND CURRENT BLOCK IS EMPTY AND NEXT BLOCK IS NOT EMPTY
/*
  4 CASE
     FORWRD_GREEN_AND_BACKWARD_RED
     SIGNAL TO PREVIOUS BLOCK 600
     SIGNAL TO NEXT BLOCK 1000
     SIGNAL FROM PREVIOUS BLOCK 1000
     SIGNAL FROM NEXT BLOCK 400
          EMPTY                                  EMPTY                              NON EMPTY
     G                                    G                                    G            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              Y                                    R                                   G
*/
void forwardGreenAndBackwardRed(int forwardSensor
                                , int backwardSensor
                                , int previousBlockOccupancySingal
                                , int nextBlockOccupancySingal) {

}

// WHEN CURRENT BLOCK IS EMPTY AND PREVIOUS AND NEXT BLOCK IS NOT EMPTY
/*
  5 CASE
      FORWARD_RED_AND_BACKWARD_RED
      SIGNAL TO PREVIOUS BLOCK 600
      SIGNAL TO NEXT BLOCK     600
      SIGNAL FROM PREVIOUS BLOCK 400
      SIGNAL FROM NEXT BLOCK  400
         NON EMPTY                              EMPTY                                NON EMPTY
     G                                    R                                    Y            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              Y                                    R                                    G
*/
void forwardRedAndBackwardRed(int forwardSensor
                              , int backwardSensor
                              , int previousBlockOccupancySingal
                              , int nextBlockOccupancySingal) {

}


// WHEN NEXT BLOCK IS EMPTY AND PREVUIOS AND CURRENT BLOCK IS NOT EMPTY
/*
  6 CASE
     FORWARD_RED_AND_BACKWARD_GREEN_1
      SIGNAL TO PREVIOUS BLOCK 400
      SIGNAL TO NEXT BLOCK 400
      SIGNAL FROM PREVIOUS BLOCK 400
      SIGNAL FROM NEXT BLOCK 1000
         NON EMPTY                              NON EMPTY                           EMPTY
     G                                    R                                    R            <------
     |------------------|                 |------------------|                 |------------------|
     | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
     |------------------|                 |------------------|                 |------------------|
     ---->              R                                    G                                    G
*/
void forwardRedAndBackwardGreen1(int forwardSensor
                                 , int backwardSensor
                                 , int previousBlockOccupancySingal
                                 , int nextBlockOccupancySingal) {

}

// WHEN PREVUIOS BLOCK IS EMPTY AND CURRENT AND NEXT BLOCK IS NOT EMPTY
/*
  7 CASE
    FORWARD_GREEN_AND_BACKWARD_RED_1
     SIGNAL TO PREVIOUS BLOCK 400
     SIGNAL TO NEXT BLOCK 400
     SIGNAL FROM PREVIOUS BLOCK 1000
     SIGNAL FROM NEXT BLOCK 400
         EMPTY                                 NON EMPTY                           NON EMPTY
    G                                     G                                    R            <------
    |------------------|                 |------------------|                 |------------------|
    | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
    |------------------|                 |------------------|                 |------------------|
    ---->              R                                    R                                    G
*/
void forwardGreenAndBackwardRed1(int forwardSensor
                                 , int backwardSensor
                                 , int previousBlockOccupancySingal
                                 , int nextBlockOccupancySingal) {

}

// WHEN PREVUIOS CURRENT AND NEXT BLOCK ALL ARE NOT EMPTY
/*
  8 CASE
    FORWARD_RED_AND_BACKWARD_RED_1
     SIGNAL TO PREVIOUS BLOCK 400
     SIGNAL TO NEXT BLOCK 400
     SIGNAL FROM PREVIOUS BLOCK 400
     SIGNAL FROM NEXT BLOCK 400
          NON EMPTY                           NON EMPTY                             NON EMPTY
    G                                     R                                    R            <------
    |------------------|                 |------------------|                 |------------------|
    | PREVIOUS BLOCK   |                 | CURRENT BLOCK    |                 | NEXT BLOCK       |
    |------------------|                 |------------------|                 |------------------|
    ---->              R                                    R                                    G
*/
void forwardRedAndBackwardRed1(int forwardSensor
                               , int backwardSensor
                               , int previousBlockOccupancySingal
                               , int nextBlockOccupancySingal) {

}


/*----------------------------------------------------------------------------------------------------------------------*/
//        UTILITY METHOD FOR SETTING UP THE VLAUES FOR THE LED LIGHTS AND OUPUTPINS FOR OTHER BLOCKS
/*----------------------------------------------------------------------------------------------------------------------*/
// SETTING UP THE VALUES FOR CURRRENT BLOCK FORWARD SIGNALS FIRST
void setForwardSignals( int forwardGreen,
                        int forwardYellow,
                        int fowardRed) {
  //LOW FOR ON HIGHT FOR OFF
  digitalWrite(FORWARD_GREEN, forwardGreen);
  digitalWrite(FORWARD_YELLOW, forwardYellow);
  digitalWrite(FORWARD_RED, fowardRed);
}

// SETTING UP THE VALUES FOR CURRRENT BLOCK BACKWARD SIGNALS SECOUND
void setBackwardSignals( int backwardGreen,
                         int backwardYellow,
                         int backwardRed) {
  //LOW FOR ON HIGHT FOR OFF
  digitalWrite(BACKWARD_GREEN, backwardGreen);
  digitalWrite(BACKWARD_YELLOW, backwardYellow);
  digitalWrite(BACKWARD_RED, backwardRed);
}


// SETTING UP THE VALUES FOR CURRRENT BLOCK OCCUPANCY PUBLISHING TO CHANNALS FOR PREVIOUS AND NEXT BLOCK
void setPublishingChannelForAdjacentBlocks(int previousBlockPublishingChannel,
    int nextBlockPublishingChannel) {
  analogWrite(PREVIOUS_BLOCK_PUBLISHING_CHANNEL, previousBlockPublishingChannel);
  analogWrite(NEXT_BLOCK_PUBLISHING_CHANNEL, nextBlockPublishingChannel);
}

/*----------------------------------------------------------------------------------------------------------------------*/
