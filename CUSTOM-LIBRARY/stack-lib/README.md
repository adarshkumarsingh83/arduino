# Generic Basic Stack

---

## Steps to Use the lib 

### include the .cpp file 
```
#include "Stack.cpp"
```

### create stack object 
```
const Stack<int> stackInt = Stack<int>(5, "int-stack");
const Stack<String> stackString = Stack<String>(5, "string-stack");
```

### use the utility methods 
* stackInt.push(random(300)
* stackInt.displayStack();
* stackInt.resetStack();
* stackInt.isEmpty();
* stackInt.isFull();


### Example 

```
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
```