/*
  DCMotorControl library. For controling two DC motors.
  Author: Jeremy Bohrer
  Date: 3/31/2013
  Released into the public domain.
*/

#ifndef DCMotorControl_h
#define DCMotorControl_h

#include "Arduino.h"

class DCMotorControl
{
  public: 
    DCMotorControl(int _speedL, int _speedR, int _enablePinL, int _enablePinR, 
    int _inL1Pin, int _inL2Pin, int _inR1Pin, int _inR2Pin);
    void setMotorL(int _speed, boolean _reverse);
    void setMotorR(int _speed, boolean _reverse);
    void forward(double meter);
    void backward(double meter);
    void right(double deg);
    void left(double deg);
    void turn(double deg);
    void stop();
  private:
    int speedL;
    int speedR;
    int enablePinL;
    int enablePinR;
    int inL1Pin;
    int inL2Pin;
    int inR1Pin;
    int inR2Pin;
    double degToTime(double deg);
    double meterToTime(double meter);
};

#endif
