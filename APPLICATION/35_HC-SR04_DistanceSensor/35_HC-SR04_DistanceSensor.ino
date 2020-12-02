const int tiggerPin = 12;
const int echoPin = 11;
float pingTrvaelTime;

const float minTime = 200; // time take to cover the 1.25 inches
const float maxTime = 700; // time taken to cover the 5.75 inches

const float minDistance = 1.25;
const float maxDistance = 5.75;

const float oneFoot = 12; // 12 inches to one foot;
const float oneMile = 5280; // 5280 foot to one mile
const float oneSecound = 1000000; // 1000000 micro secound to one secound
const float oneHour = 3600; // one hour to 3600 secound

float inchesPerMicroSecound;
float milesPerHour;

const float SOUND_SPEED = 767;//MILES PER HOURS

void setup() {
  Serial.begin(9600);
  pinMode(tiggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(tiggerPin, LOW);
  delayMicroseconds(1000);

  digitalWrite(tiggerPin, HIGH);
  delayMicroseconds(1000);

  pingTrvaelTime = pulseIn(echoPin, HIGH);
  Serial.println(" ");
  Serial.print(pingTrvaelTime);
  Serial.println(" ");
  Serial.print("  Distance in inches per millisecound ");
  Serial.print(calculateDistanceInchesPerMicroSecound(pingTrvaelTime));
  Serial.println(" ");
  Serial.print("  Distance in miles per hour ");
  Serial.print(velocityMilesPerHour(pingTrvaelTime));
  digitalWrite(tiggerPin, LOW);

}

float calculateDistanceInchesPerMicroSecound(float pingTrvaelTime) {
  float inchesPerMiliSecound = SOUND_SPEED * (oneMile / 1 ) * ( oneFoot / 1 ) * ( 1 / oneHour ) * ( 1 / oneSecound);
  return inchesPerMiliSecound * pingTrvaelTime;
}

//calculate speed in inches per micro secound
float velocityInchesPerMicroSecound() {
  inchesPerMicroSecound = (maxDistance - minDistance) / (maxTime - minTime);
  return inchesPerMicroSecound;
}

//calculate speed in mile per hour
float  velocityMilesPerHour(float pingTrvaelTime) {
  float inchesPerMiliSecound = (SOUND_SPEED / oneHour) * (oneMile / 1 ) * ( oneFoot / 1 ) * (  1 / oneHour ) * ( 1 / oneSecound);
  inchesPerMicroSecound = inchesPerMiliSecound * pingTrvaelTime;
  return inchesPerMicroSecound * (1 / oneFoot) * (1 / oneMile) * (oneSecound / 1) * (oneHour / 1);
}
