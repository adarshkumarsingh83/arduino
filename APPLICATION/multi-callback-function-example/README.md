# Arduino Multi Callback function example 

--- 

### define the callback function defination in the XXXClass.h file 
```
#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define ON_CALLBACK_SIGNATURE std::function<void(String, int)> onStateCallback
#else
#define ON_CALLBACK_SIGNATURE void (*onStateCallback)(String, int)
#endif

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define OFF_CALLBACK_SIGNATURE std::function<void(String, int)> offStateCallback
#else
#define OFF_CALLBACK_SIGNATURE void (*offStateCallback)(String, int)
#endif

```
* or 

### define call back function without condition like below 
```
#define ON_CALLBACK_SIGNATURE void (*onStateCallback)(String, int)
#define OFF_CALLBACK_SIGNATURE void (*offStateCallback)(String, int)
```

### define the function signature as the class private vairable 

```
class State {

  private:
    ON_CALLBACK_SIGNATURE;
    OFF_CALLBACK_SIGNATURE;
    void processState();

   .......

   .......
 }   
```


### define the setter function to set the callback method implementions 
```

class State {

  ...............

  public:
    void setOnStateCallback(ON_CALLBACK_SIGNATURE);
    void setOffStateCallback(OFF_CALLBACK_SIGNATURE);

  ................

}
````

### define the invocation method for the callback 
````

class State {

  ...............

  public:
    void loop();

  ................

}

````

### provide the implemenation for each method in the XXXClass.cpp file 
```

int counter = 0;

const String messageOn = "welcome to espark on state";
const String messageOff = "welcome to espark off state";

void State::processState() {
  if (counter % 2 == 0) {
    if (onStateCallback) {
      onStateCallback(messageOn, messageOn.length());
    }
  } else {
    if (offStateCallback) {
      offStateCallback(messageOff, messageOff.length());
    }
  }
  counter = counter + 1;
}

void State::setOnStateCallback(ON_CALLBACK_SIGNATURE) {
  this->onStateCallback = onStateCallback;
}
void State::setOffStateCallback(OFF_CALLBACK_SIGNATURE) {
  this->offStateCallback = offStateCallback;
}

void State::loop() {
  processState();
}
```

### in driver class create the object and defien the callback method defination with implemenation and set the callback emthod 
```

#include"XXXClass.h"

State state;

void onStateCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void offStateCallback(String message, int lengthVar) {
  Serial.println(message + " lenght for msg:=> " + String(lengthVar));
}

void setup() {
  Serial.begin(115200);
  state.setOnStateCallback(onStateCallback);
  state.setOffStateCallback(offStateCallback);
}

void loop() {
  delay(1000);
  state.loop();
}

```
