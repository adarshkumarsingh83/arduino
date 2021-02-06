#include "Arduino.h"
#include "PCF8574.h"

const byte INTERRUPTED_PIN = 2;

// Function interrupt
void infraRedActive();

// Set i2c address
PCF8574 pcf8574(0x20, INTERRUPTED_PIN, infraRedActive);


bool irActive = false;
void interrupt_routine();
uint8_t val = -1;

void setup() {

  Serial.begin(9600);

  // Set pinMode to OUTPUT
  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
  pcf8574.pinMode(P2, INPUT);
  pcf8574.pinMode(P3, INPUT);

  Serial.print("Init pcf8574...");
  if (pcf8574.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }
}

void loop() {
  pcf8574.digitalWrite(P0, LOW);

  if (irActive) {
    pcf8574.digitalWrite(P0, HIGH);
    pcf8574.digitalWrite(P1, LOW);
    val = pcf8574.digitalRead(P2);
    if (val == 0) {
      Serial.print("READ VALUE FROM PCF P2 ");
      Serial.println(val);
    }
    val = pcf8574.digitalRead(P3);
    if (val == 0) {
      Serial.print("READ VALUE FROM PCF P3 ");
      Serial.println(val);
    }
    delay(1000);
    irActive = false;
    pcf8574.digitalWrite(P1, HIGH);
    val = -1;
  }

}

void infraRedActive() {
  //Serial.println("*");
  irActive = true;
}
