/*
  DCMotorControl library. For controling two DC motors.
  Author: Jeremy Bohrer
  Date: 3/31/2013
  Released into the public domain.
*/

#include "Arduino.h"
#include "DCMotorControl.h"

DCMotorControl::DCMotorControl(int _speedR, int _speedL, int _enablePinR, int _enablePinL, 
    int _inR1Pin, int _inR2Pin, int _inL1Pin, int _inL2Pin)
{
	speedL = _speedL;
    speedR = _speedR;
    enablePinL = _enablePinL;
    enablePinR = _enablePinR;
    inL1Pin = _inL1Pin;
    inL2Pin = _inL2Pin;
    inR1Pin = _inR1Pin;
    inR2Pin = _inR2Pin;
    
    pinMode(enablePinL, OUTPUT);
  	pinMode(inL1Pin, OUTPUT);
 	pinMode(inL2Pin, OUTPUT);
  
  	pinMode(enablePinR, OUTPUT);
  	pinMode(inR1Pin, OUTPUT);
  	pinMode(inR2Pin, OUTPUT);
}

double DCMotorControl::degToTime(double deg)
{
	double degToTime = 3.7;
	return deg * degToTime;
}

double DCMotorControl::meterToTime(double meter)
{
	double meterToTime = 500;
	return meterToTime * meter;
}

void DCMotorControl::setMotorL(int _speed, boolean _reverse=false)
{
	analogWrite(enablePinL, _speed);
  	digitalWrite(inL1Pin, _reverse);
 	digitalWrite(inL2Pin, !  _reverse);
}

void DCMotorControl::setMotorR(int _speed, boolean _reverse=false)
{
	analogWrite(enablePinR, _speed);
  	digitalWrite(inR1Pin, _reverse);
  	digitalWrite(inR2Pin, ! _reverse);
}

void DCMotorControl::forward(double meter)
{
	setMotorL(speedL);
  	setMotorR(speedR);
  	delay(meterToTime(meter));
}

void DCMotorControl::backward(double meter)
{
	setMotorL(speedL, true);
  	setMotorR(speedR, true);
  	delay(meterToTime(meter));
}

void DCMotorControl::right(double deg)
{
  	setMotorL(speedL); 
  	setMotorR(speedR, true);
  	delay(degToTime(deg));
}

void DCMotorControl::left(double deg)
{
	setMotorL(speedL, true); 
  	setMotorR(speedR);
  	delay(degToTime(deg));
}

void DCMotorControl::turn(double deg)
{
	if (deg > 0)
	{
		right(deg);
	}
	else
	{
		left(abs(deg));
	}
}

void DCMotorControl::stop()
{
	setMotorL(0); 
  	setMotorR(0);
}











