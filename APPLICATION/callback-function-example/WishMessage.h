#ifndef WishMessage_h
#define WishMessage_h
#include "Arduino.h"

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define WISH_CALLBACK_SIGNATURE std::function<void(String, int)> callback
#else
#define WISH_CALLBACK_SIGNATURE void (*callback)(String, int)
#endif

class WishMessage {

  private:
    WISH_CALLBACK_SIGNATURE;
    void processWishMessage();

  public:
    WishMessage() {
    }
    void setCallback(WISH_CALLBACK_SIGNATURE);
    void loop();
    ~WishMessage() {
    }


};
#endif
