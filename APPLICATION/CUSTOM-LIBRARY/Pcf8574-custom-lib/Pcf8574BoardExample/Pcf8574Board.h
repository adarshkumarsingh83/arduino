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

     Pcf8574Board(Pcf8574 * pcf8574Boards, int totalPcf8574Boards) {
      _pcf8574Boards = pcf8574Boards;
      _totalPcf8574Boards = totalPcf8574Boards;
    }

    bool switchOn(int pinNo);
    bool switchOff(int pinNo);
    void restBoard(int boardNo);
    void refreshBoard(int boardNo);
    void displayPinState();

    ~Pcf8574Board() {
      delete [] _pcf8574Boards;
    }
};

#endif
