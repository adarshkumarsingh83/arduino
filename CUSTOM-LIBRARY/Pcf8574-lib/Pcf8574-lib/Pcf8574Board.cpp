/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#include "Pcf8574Board.h"
#include <Arduino.h>
#include <Wire.h>


void Pcf8574Board::initPcf8574Boards() {
  _pcf8574Boards = new Pcf8574[_totalPcf8574Boards];
  for (int i = 0; i < _totalPcf8574Boards; i++) {
    _pcf8574Boards[i].setBoardAddress(_boardAddress[i]);
  }
}

Pcf8574Board::BoardPinData Pcf8574Board::findBoardPin(int pinNo) {
  Pcf8574Board::BoardPinData boardPinData;
  int board = (pinNo / 8);
  if (board <= _totalPcf8574Boards && pinNo <= (_totalPcf8574Boards * 8)) {
    int totalPins = (board * 8);
    int pin = (pinNo - totalPins) - 1;
    pin = (pin == -1) ? 0 : pin;
    boardPinData.processed = true;
    boardPinData.boardNo = board;
    boardPinData.boardPin = pin;
    return boardPinData;
  }
  boardPinData.processed = false;
  return boardPinData;
}

bool Pcf8574Board::switchOn(int pinNo) {
  Pcf8574Board::BoardPinData boardPinData =  Pcf8574Board::findBoardPin(pinNo);
  Serial.println();
  Serial.print("on - board no ");
  Serial.println(boardPinData.boardNo);
  Serial.print("on - pin no ");
  Serial.println(boardPinData.boardPin);
  if (boardPinData.processed) {
    _pcf8574Boards[boardPinData.boardNo].switchPinOn(boardPinData.boardPin);
  }
  return true;
}

bool Pcf8574Board::switchOff(int pinNo) {
  Pcf8574Board::BoardPinData boardPinData =  Pcf8574Board::findBoardPin(pinNo);
  Serial.println();
  Serial.print("off - board no ");
  Serial.println(boardPinData.boardNo);
  Serial.print("off - pin no ");
  Serial.println(boardPinData.boardPin);
  if (boardPinData.processed) {
    _pcf8574Boards[boardPinData.boardNo].switchPinOff(boardPinData.boardPin);
  }
  return true;
}

void Pcf8574Board::restBoard(int boardNo) {
  _pcf8574Boards[boardNo].resetPcf8574();
}

void Pcf8574Board::refreshBoard(int boardNo) {
  _pcf8574Boards[boardNo].refreshPcf8574();
}

void Pcf8574Board::displayPinState() {
  Serial.print("Total Boards ");
  Serial.println(_totalPcf8574Boards);
  for (int i = 0; i < _totalPcf8574Boards; i++) {
    Serial.print("Address ");
    Serial.println(_pcf8574Boards[i].getBoardAddress());
  }

  for (int i = 0; i < _totalPcf8574Boards; i++) {
    _pcf8574Boards[i].displayPcf8574PinState();
    Serial.println();
  }
}
