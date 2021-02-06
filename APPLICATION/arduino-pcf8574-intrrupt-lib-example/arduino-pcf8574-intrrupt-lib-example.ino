#include "Arduino.h"
#include "PCF8574.h"

#define INTERRUPTED_PIN 2

bool irActive = false;

// Function interrupt
void infraRedActive();

// Set i2c address
PCF8574 pcf8574(0x20, INTERRUPTED_PIN, infraRedActive);


void setup() {
  Serial.begin(9600);
  // Set pinMode to OUTPUT
  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
  pcf8574.pinMode(P3, INPUT);

  Serial.print("Init pcf8574...");
  if (pcf8574.begin()) {
    Serial.println("INIT OK");
  } else {
    Serial.println("INIT FAILED");
  }
}

void loop() {
  if (irActive) {
    pcf8574.digitalWrite(P0, HIGH);
    pcf8574.digitalWrite(P1, LOW);
    uint8_t val = pcf8574.digitalRead(P3);
    Serial.print("READ VALUE FROM PCF ");
    Serial.println(val);
     delay(1000);
    irActive = false;
  } else {
    pcf8574.digitalWrite(P1, HIGH);

    pcf8574.digitalWrite(P0, HIGH);
    delay(1000);
    pcf8574.digitalWrite(P0, LOW);
    delay(1000);
  }
}

void infraRedActive() {
  /*
    Interrupt called (No Serial no read no wire in this
    function, and DEBUG disabled on PCF library)
  */
  irActive = true;
}
