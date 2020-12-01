// for sending data to the chip
const int dataPin = 12;
// for opening and closing latch of the chip
const int latchPin = 11;
const int clockPin = 9;

int temp = 0;
int shitOperation = 0;
bool fwarward = true;

void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void rightShitOperation(byte counter ) {
  if (counter > 0) {
    Serial.println(counter, BIN);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, counter);
    digitalWrite(latchPin, HIGH);
    delay(500);
    counter = counter / 2;
    rightShitOperation(counter);
  }
  return 0;
}

void leftShitOperation(byte counter) {
  if (counter <= 255) {
    Serial.println(counter, BIN);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, counter);
    digitalWrite(latchPin, HIGH);
    delay(500);
    counter = counter * 2;
    leftShitOperation(counter);
  }
  return 0;
}


void circularShift(byte counter) {
  if (temp <= 7 && fwarward) {
    counter = counter / 128 + counter * 2;
    Serial.println(counter, BIN);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, counter);
    digitalWrite(latchPin, HIGH);
    delay(500);
    temp ++;
    if (temp == 7) {
      fwarward = false;
    }
  } else if (temp >= 0 && !fwarward) {
    counter = counter * 128 + counter / 2;
    Serial.println(counter, BIN);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, counter);
    digitalWrite(latchPin, HIGH);
    delay(500);
    temp --;
    if (temp == 0 ) {
      fwarward = true;
    }
  }
  circularShift(counter);
}

void loop() {


  //rightShitOperation(0B11111111);
  
  //leftShitOperation(0b00000001);

  circularShift(0B11111110);

}
