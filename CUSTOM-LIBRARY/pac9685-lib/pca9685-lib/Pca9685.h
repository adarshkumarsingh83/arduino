/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#ifndef Pca9685_h
#define Pca9685_h

#include <Arduino.h>
//#include "Adafruit_PWMServoDriver.h"

class Pca9685 {

  private:
    typedef struct {
      int _openState;
      int _closeState;
      bool _isOpen;
    } Pca9685Pin;

    int _defaultState;
    int _totalPins=16;
    int _boardsAddress;

    Pca9685Pin * _pca9685PinList;
    //Adafruit_PWMServoDriver _pwm;

    void initPca9685();
    void refreshPin(int pinNo, Pca9685Pin pca9685Pin);

  public:

    Pca9685(int boardsAddress) {
      _boardsAddress = boardsAddress;
      _pca9685PinList = new Pca9685Pin[_totalPins];
      // _pwm = Adafruit_PWMServoDriver(boardsAddress);
      // _pwm.setPWMFreq(60);
      initPca9685();
    }

    Pca9685(int boardsAddress, int totalPins) {
      _boardsAddress = boardsAddress;
      _totalPins = totalPins;
      _pca9685PinList = new Pca9685Pin[_totalPins];
      // _pwm = Adafruit_PWMServoDriver(boardsAddress);
      // _pwm.setPWMFreq(60);
      initPca9685();
    }

    bool throwSwitchPca9685Pin(int pinNo);
    bool closeSwitchPca9685Pin(int pinNo);
    void refreshPca9685Board();
    void resetPca9685Board();
    void displayPca9685PinState();
    void displayPinState(Pca9685Pin pin);

    ~Pca9685() {
      delete [] _pca9685PinList;
    }
};
#endif
