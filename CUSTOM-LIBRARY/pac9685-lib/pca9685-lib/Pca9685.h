/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#ifndef Pca9685_h
#define Pca9685_h

#include <Arduino.h>
#include "Adafruit_PWMServoDriver.h"

class Pca9685 {

  private:
    typedef struct {
      int _openState;
      int _closeState;
      bool _isOpen;
    } Pca9685Pin;

    int _defaultState;
    int _totalPins = -1;
    int _boardsAddress;
    int _pwmFrequency;

    Pca9685Pin * _pca9685PinList;
    Adafruit_PWMServoDriver _pwm;

    void init();
    void refreshPin(int pinNo, Pca9685Pin pca9685Pin);

  public:

    Pca9685() {
      init();
    }
    void initPca9685();
    void setBoardAddress(int boardsAddress);
    int getBoardAddress();
    void setPwmFrequency(int pwmFrequency);
    bool setSwitchOpenCloseRange(int pinNo, int openRange, int closeRange);
    bool throwSwitchPca9685Pin(int pinNo);
    bool closeSwitchPca9685Pin(int pinNo);
    void refreshPca9685Board();
    void resetPca9685Board();
    void displayPca9685PinState();
    void displayPinState(int pinNo);

    ~Pca9685() {
      delete [] _pca9685PinList;
    }
};
#endif
