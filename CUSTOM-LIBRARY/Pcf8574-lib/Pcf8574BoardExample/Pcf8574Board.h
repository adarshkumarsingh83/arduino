/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#ifndef Pcf8574Board_h
#define Pcf8574Board_h

#include "Pcf8574.h"

class Pcf8574Board {

  private:
    int _boardAddress[8] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27};

    typedef struct BoardPin {
      int boardNo;
      int boardPin;
      bool processed;
    } BoardPinData;

    int _totalPcf8574Boards;
    Pcf8574  * _pcf8574Boards;

    void initPcf8574Boards();
    Pcf8574Board::BoardPinData findBoardPin(int no);
    Pcf8574 getPcf8574Object(int i);

  public:

    Pcf8574Board(int totalPcf8574Boards) : _totalPcf8574Boards(totalPcf8574Boards) {
      initPcf8574Boards();
    }

    bool switchOn(int pinNo);
    bool switchOff(int pinNo);
    void restBoard(int boardNo);
    void refreshBoard(int boardNo);
    void displayPinState();

    ~Pcf8574Board() {
      for (int i = 0; i < _totalPcf8574Boards; i++) {
        delete &_pcf8574Boards[i];
      }
      delete [] _pcf8574Boards;
    }
};

#endif
