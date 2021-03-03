/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#ifndef Pca9685Board_h
#define Pca9685Board_h

#include <Arduino.h>
#include "Pca9685.h"

class Pca9685Board {

  private:

    typedef struct  {
      int boardNo;
      int boardPin;
      bool processed;
    } BoardPin;

    int _totalPca9685Boards;
    Pca9685 * _pca9685Boards;

    void initPca9685Boards();
    BoardPin findBoardPin(int pinNo);

  public:
    Pca9685Board() {

    }
    
    bool throwSwitch(int pinNo);
    bool closeSwitch(int pinNo);
    void restBoard(int boardNo);
    void refreshBoard(int boardNo);
    void displayPinState();

    ~Pca9685Board() {
      delete[] _pca9685Boards;
    }
};
#endif
