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

    void initPcf8574Boards();
    void boardRefresh(int sum);

  public:
    const static bool _OFF = true;
    const static bool _ON = false;

    Pcf8574(int boardsAddress) {
      _boardsAddress = boardsAddress;
      _boardPinsState = new int[8];
      initPcf8574Boards();
    }

    bool switchOn(int pinNo);
    bool switchOff(int pinNo);
    void displayPinState();

    ~Pcf8574() {
      delete[] _boardPinsState;
    }
};

#endif
