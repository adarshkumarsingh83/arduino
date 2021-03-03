#ifndef Message_h
#define Message_h

class Message {
    
    String type = "text-messge";
    
  private:
    String _msg;
    String _name;
    void initMessage();

  protected:

    String toUpperCaseMessage();

  public:

    Message() {
      initMessage();
    }

    Message(String msg) {
      _msg = msg;
      initMessage();
    }

    //copy constructor
    Message(const Message &message);

    Message(String msg, String nameValue);

    void displayMessage();
    
    void displayMessageWiwhThis();

    friend void showMessage(Message message);

    ~Message(void) {
      delete &_msg;
    }

};

#endif
