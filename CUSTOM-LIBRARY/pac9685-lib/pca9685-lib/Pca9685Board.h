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
    int _boardAddress[64] = {
      0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
      0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
      0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
      0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
    };

    typedef struct  {
      int boardNo;
      int boardPin;
      bool processed;
    } BoardPin;

    int _totalPca9685Boards;
    Pca9685 ** _pca9685Boards;

    void initPca9685Boards();
    BoardPin findBoardPin(int pinNo);

  public:
    Pca9685Board(int totalPca9685Boards) {
      _totalPca9685Boards = totalPca9685Boards;
      _pca9685Boards = new Pca9685*[_totalPca9685Boards];
      for (int i = 0; i < _totalPca9685Boards; i++) {
        _pca9685Boards[i] = new Pca9685(_boardAddress[i]);
      }
      initPca9685Boards();
    }

    bool throwSwitch(int pinNo);
    bool closeSwitch(int pinNo);
    void restBoard(int boardNo);
    void refreshBoard(int boardNo);
    void displayPinState();

    ~Pca9685Board() {
      for (int i = 0; i < _totalPca9685Boards; i++) {
        delete _pca9685Boards[i];
      }
      delete[] _pca9685Boards;
    }
};
#endif
