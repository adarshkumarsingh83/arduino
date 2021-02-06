
/*
RISING: when the pin goes from LOW to HIGH, the interrupt is triggered
FALLING: when the pin goes from HIGH to low, the interrupt is triggered
LOW: when the pin is LOW, the interrupt is triggered
CHANGE: when the pin changes from either LOW to HIGH or HIGH to LOW, the interrupt is triggered
 */

const byte led_pin = 8;
const byte interrupt_pin = 2;
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),interrupt_routine,CHANGE);
}

void loop() {
  if (state==HIGH){
    digitalWrite(led_pin,HIGH);
    delay(500);   
  }
  if (state==HIGH) {
    Serial.println("low");
    state = LOW;
    digitalWrite(led_pin,LOW);
  }
}

void interrupt_routine(){
  state = HIGH;
  Serial.println("interrupt");
}
