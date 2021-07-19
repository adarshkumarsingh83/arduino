#include "Stack.cpp"


const Stack<int> stackInt = Stack<int>(5, "int-stack");
const Stack<String> stackString = Stack<String>(5, "string-stack");

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  if (!stackInt.push(random(300))) {
    stackInt.displayStack();
    stackInt.resetStack();
  }

  String d = "adi_";
  d += random(100);
  if (!stackString.push(d)) {
    stackString.displayStack();
    stackString.resetStack();
  }

}
