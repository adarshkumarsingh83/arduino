#include<SoftwareSerial.h>

#define LED_PIN 16

char recStr[10] = "";
char ourStr[8] = "Arduino";
bool flag = false;
String ledStatus = "";
String recievedData = "";

SoftwareSerial SUART(4, 5);  //D2, D1 = SRX, STX

void setup() {
  Serial.begin(115200);
  SUART.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {

  SUART.print(ledStatus);
  byte n = SUART.available();
  if (n != 0) {
    SUART.readBytesUntil('!', recStr, 10);
    recievedData = recStr;
    recievedData.replace(" ", "");
    if (recievedData.indexOf("ON") > 0) {
      digitalWrite(LED_PIN, HIGH);
    } else if (recievedData.indexOf("OFF") > 0)  {
      digitalWrite(LED_PIN, LOW);
    }
    delay(1000);
    Serial.println(recievedData);
    recievedData = "";
    for (int i = 0; i < 10; i++) {
      recStr[i] = ' ';
    }
  }
  if (flag) {
    ledStatus = "LED:OFF!";
    flag = false;
  } else {
    ledStatus = "LED:ON!";
    flag = true;
  }
}
