
#define LED_PIN 7

bool flag = false;
char recStr[10] = "";
String ledStatus = "";
String recievedData = "";

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  byte n = Serial1.available();
  if (n != 0) {
    Serial1.readBytesUntil('!', recStr, 10);
    recievedData = recStr;
    recievedData.replace(" ", "");
    Serial.println(recievedData);
    if (recievedData.indexOf("ON") > 0) {
      digitalWrite(LED_PIN, HIGH);
    } else if (recievedData.indexOf("OFF") > 0)  {
      digitalWrite(LED_PIN, LOW);
    }
  }
  recievedData = "";
  for (int i = 0; i < 10; i++) {
    recStr[i] = ' ';
  }
  delay(1000);
  if (flag) {
    ledStatus = "LED:OFF!";
    flag = false;
  } else {
    ledStatus = "LED:ON!";
    flag = true;
  }
  Serial1.println(ledStatus);
}
