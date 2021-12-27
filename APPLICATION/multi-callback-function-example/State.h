#ifndef State_h
#define State_h
#include "Arduino.h"

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

class State {

  private:
    ON_CALLBACK_SIGNATURE;
    OFF_CALLBACK_SIGNATURE;
    void processState();

  public:
    State() {
    }
    void setOnStateCallback(ON_CALLBACK_SIGNATURE);
    void setOffStateCallback(OFF_CALLBACK_SIGNATURE);
    void loop();
    ~State() {
    }


};
#endif
