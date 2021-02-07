#include "Arduino.h"
#include "PCF8574.h"

const byte INTERRUPTED_PIN = 2;

// Function interrupt
void infraRedActive();

// Set i2c address
PCF8574 pcf8574List [] = { PCF8574(0x20, INTERRUPTED_PIN, infraRedActive), PCF8574(0x21, INTERRUPTED_PIN, infraRedActive) } ;

bool irActive = false;

int i = 0;
uint8_t val = -1;
const int pcf8574Count = 2;

void setup() {

  Serial.begin(9600);
  for ( i = 0; i < pcf8574Count ; i++) {
    // Set pinMode to OUTPUT
    pcf8574List[i].pinMode(P0, OUTPUT);
    pcf8574List[i].pinMode(P1, OUTPUT);
    pcf8574List[i].pinMode(P6, INPUT);
    pcf8574List[i].pinMode(P7, INPUT);

    Serial.print("Init pcf8574..." + i );
    if (pcf8574List[i].begin()) {
      Serial.println("PCF8574 INIT SUCCESS ");
    } else {
      Serial.println("PCF8574 INIT FAILED ");
    }
  }
}

void loop() {
  delay(500);
  doOperation(pcf8574List[0], 1);  
  doOperation(pcf8574List[1], 2);
  irActive = false;
}

void doOperation(PCF8574 pcf8574, int no) {
  pcf8574.digitalWrite(P0, LOW);
  if (irActive) {
    Serial.println(no);
    pcf8574.digitalWrite(P0, HIGH);
    pcf8574.digitalWrite(P1, LOW);
    val = pcf8574.digitalRead(P6);
    if (val == 0) {
      Serial.print("P6 ");
      Serial.println(val);
    }
    val = -1;
    val = pcf8574.digitalRead(P7);
    if (val == 0) {
      Serial.print("P7 ");
      Serial.println(val);
    }
    delay(1000);
    pcf8574.digitalWrite(P1, HIGH);
    val = -1;
  }
}

void infraRedActive() {
  //Serial.println("*");
  irActive = true;
}
