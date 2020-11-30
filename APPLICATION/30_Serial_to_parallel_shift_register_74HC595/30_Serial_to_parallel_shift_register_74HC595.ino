
// for sending data to the chip
const int dataPin = 12;
// for opening and closing latch of the chip
const int latchPin = 11;
const int clockPin = 9;

byte LEDS_ON = 0x00;
byte LEDS_OFF = 0xFF;

byte counter = 0b0;
void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {

  if (counter < 255) {
    Serial.println(counter, BIN);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, counter);
    digitalWrite(latchPin, HIGH);
    delay(5000);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDS_OFF);
    digitalWrite(latchPin, HIGH);
    delay(1000);
  } else {
    delay(10000);
    counter = 0;
  }
  counter++;
}
