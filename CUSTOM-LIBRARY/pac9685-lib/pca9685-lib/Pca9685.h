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
    int _totalSwtiches;
    int _boardsAddress;
    Pca9685Pin * _pca9685PinList;
    //Adafruit_PWMServoDriver _pwm;

    void initPca9685Board();
    void refreshPin(int pinNo, Pca9685Pin pca9685Pin);

  public:

    Pca9685(int boardsAddress) {
      _boardsAddress = boardsAddress;
      _totalSwtiches = 16;
      _pca9685PinList = new Pca9685Pin[boardsAddress];
      // _pwm = Adafruit_PWMServoDriver(boardsAddress);
      // _pwm.setPWMFreq(60);
      initPca9685Board();
    }

    Pca9685(int boardsAddress, int frequency) {
      _boardsAddress = boardsAddress;
      _totalSwtiches = 16;
      _pca9685PinList = new Pca9685Pin[boardsAddress];
      // _pwm = Adafruit_PWMServoDriver(boardsAddress);
      // _pwm.setPWMFreq(frequency);
      initPca9685Board();
    }

    Pca9685(int boardsAddress, int totalSwtiches, int frequency) {
      _boardsAddress = boardsAddress;
      _totalSwtiches = totalSwtiches;
      _pca9685PinList = new Pca9685Pin[boardsAddress];
      // _pwm = Adafruit_PWMServoDriver(boardsAddress);
      // _pwm.setPWMFreq(frequency);
      initPca9685Board();
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
