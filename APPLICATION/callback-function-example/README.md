# Arduino Callback function example 

--- 

### define the callback function defination in the XXXClass.h file 
```
#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define WISH_CALLBACK_SIGNATURE std::function<void(String, int)> callback
#else
#define WISH_CALLBACK_SIGNATURE void (*callback)(String, int)
#endif

```
* or 

### define call back function without condition like below 
```
#define WISH_CALLBACK_SIGNATURE void (*callback)(String, int)

```

### define the function signature as the class private vairable 

```
class WishMessage {

  private:
    WISH_CALLBACK_SIGNATURE;
     void processWishMessage();

   .......

   .......
 }   
```


### define the setter function to set the callback method implementions 
```

class WishMessage {

  ...............

  public:
    void setCallback(WISH_CALLBACK_SIGNATURE);

  ................

}
````

### define the invocation method for the callback 
````

class WishMessage {

  ...............

  public:
    void loop();

  ................

}

````

### provide the implemenation for each method in the XXXClass.cpp file 
```

void XXXClass::processWishMessage() {
  if (callback) {
    callback(message, message.length());
  }
}

void XXXClass::setCallback(WISH_CALLBACK_SIGNATURE) {
  this->callback = callback;
}

void XXXClass:: loop() {
  processWishMessage();
}
```

### in driver class create the object and defien the callback method defination with implemenation and set the callback emthod 
```

#include"XXXClass.h"

XXXClass wishMessage;

void wishMessageCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void setup() {
  Serial.begin(115200);
  wishMessage.setCallback(wishMessageCallback);
}

void loop() {
  delay(1000);
  wishMessage.loop();
}

```
