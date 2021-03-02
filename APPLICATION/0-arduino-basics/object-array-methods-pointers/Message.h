#ifndef Message_h
#define Message_h

#include <Arduino.h>

class Message {

  private:
    String _type;
    String _text="-";
    void init();

  public:
    Message() {
      this->init();
    }

    Message(String text) {
      _text = text;
      this->init();
    }
    
    Message(String text,String type) {
      _text = text;
      _type = type;
      this->init();
    }

    String getText();
    void displayMessageData();

    ~ Message() {}
};


#endif
