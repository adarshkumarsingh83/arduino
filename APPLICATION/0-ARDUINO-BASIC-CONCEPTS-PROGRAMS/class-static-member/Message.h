#ifndef Message_h
#define Message_h

class Message {

    String type = "text-messge";

  private:
    String _msg;
    String _name;
    void initMessage();

  public:

    static int _instanceCount;

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

    static int getInstanceCount() {
      return _instanceCount;
    }

    ~Message(void) {
      delete &_msg;
    }

};

#endif
