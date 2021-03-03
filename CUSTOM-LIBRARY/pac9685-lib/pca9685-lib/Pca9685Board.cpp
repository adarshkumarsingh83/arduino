
/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include "Pca9685Board.h"


void Pca9685Board::initPca9685Boards() {
}


Pca9685Board::BoardPin Pca9685Board::findBoardPin(int pinNo) {
  Pca9685Board::BoardPin boardSlot;
  int board = (pinNo / 16);
  if (board <= _totalPca9685Boards && pinNo <= (_totalPca9685Boards * 16)) {
    int totalPins = (board * 16);
    int pin = (pinNo - totalPins) - 1;
    pin = (pin == -1) ? 0 : pin;
    boardSlot.processed = true;
    boardSlot.boardNo = board;
    boardSlot.boardPin = pin;
    return boardSlot;
  }
  boardSlot.processed = false;
  return boardSlot;
}

bool Pca9685Board::throwSwitch(int pinNo) {
  Pca9685Board::BoardPin boardSlot = findBoardPin(pinNo);
  _pca9685Boards[boardSlot.boardNo]->throwSwitchPca9685Pin(boardSlot.boardPin);

}
bool Pca9685Board::closeSwitch(int pinNo) {
  Pca9685Board::BoardPin boardSlot = findBoardPin(pinNo);
  _pca9685Boards[boardSlot.boardNo]->closeSwitchPca9685Pin(boardSlot.boardPin);
  return true;
}

void Pca9685Board::restBoard(int boardNo) {
  _pca9685Boards[boardNo]->resetPca9685Board();
}

void Pca9685Board::refreshBoard(int boardNo) {
  _pca9685Boards[boardNo]->refreshPca9685Board();
}

void Pca9685Board::displayPinState() {
  for (int i = 0; i < _totalPca9685Boards; i++) {
    _pca9685Boards[i]->displayPca9685PinState();
    Serial.println("-");
  }
}
