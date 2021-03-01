#include "CircularQueue.cpp"

const CircularQueue<int> circularQueueInt = CircularQueue<int>(5, "int-queue");
const CircularQueue<String> circularQueueString = CircularQueue<String>(5, "string-queue");

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  if (!circularQueueInt.push(random(300))) {
    circularQueueInt.displayQueue();
    circularQueueInt.resetQueue();
  }

  String d = "adi_";
  d += random(100);
  if (!circularQueueString.push(d)) {
    circularQueueString.displayQueue();
    circularQueueString.resetQueue();
  }
}
