
// for sending data to the chip
const int dataPin = 12;
// for opening and closing latch of the chip
const int latchPin = 11;
const int clockPin = 9;

byte LEDS_ON = 0x00;
byte LEDS_OFF = 0xFF;
void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDS_ON);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDS_OFF);
    digitalWrite(latchPin, HIGH);
    delay(1000);
}
