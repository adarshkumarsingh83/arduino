/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#ifndef Pcf8574_h
#define Pcf8574_h

class Pcf8574 {

  private:
    int  _boardsAddress;
    int *_boardPinsState;

    void initPcf8574();
    void boardRefresh(int sum);

  public:
    const static bool _OFF = true;
    const static bool _ON = false;

    Pcf8574(int boardsAddress) {            
      _boardsAddress = boardsAddress;
      _boardPinsState = new int[8];
      initPcf8574();
    }

    bool switchPinOn(int pinNo);
    bool switchPinOff(int pinNo);
    bool resetPcf8574();
    bool refreshPcf8574();
    void displayPcf8574PinState();

    ~Pcf8574() {
      delete[] _boardPinsState;
    }
};

#endif
