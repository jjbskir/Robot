/*
  robotics - robotic functions.
  HW for block 2.
*/

#include <DCMotorControl.h>

DCMotorControl motorControl(158, 200, 10, 5, 9, 7, 8, 6);
int button = 13;
boolean buttonState;

void setup()
{
  Serial.begin(9600); 
  pinMode(button, INPUT);
  Serial.print("Robot on \n");
}


void loop()
{
  if (digitalRead(button) != HIGH)
  {
    spiral();
    motorControl.stop();
  }
}

double radianToDeg(double radian)
{
  double deg = (180/3.14) * radian;
  return deg;
}

void square()
{
    motorControl.forward(1);
    motorControl.right(90);
    motorControl.forward(1);
    motorControl.right(90);
    motorControl.forward(1);
    motorControl.right(90);
    motorControl.forward(1);
}

void spiral()
{
  double r = 0;
  double a = .5;
  double b = 0;
  double angle = 0;
  double radian = 0;
  for (radian; radian < 6.28; radian += .001) 
  {
    r = radian*a + b;
    angle = radianToDeg(radian);
    motorControl.forward(r);
    motorControl.right(angle);
  }
}

void gotoPositionIndirect(double x, double y)
{
  if (x >= 0 && y >= 0)
  {
    motorControl.forward(abs(y));
    motorControl.right(90);
    motorControl.forward(abs(x));
  }
  if (x < 0  && y >= 0)
  {
    motorControl.forward(abs(y));
    motorControl.left(90);
    motorControl.forward(abs(x));
  }
  if (x >= 0 && y < 0)
  {
    motorControl.right(180); 
    motorControl.forward(abs(y));
    motorControl.left(90);
    motorControl.forward(abs(x));
  }
  if (x < 0 && y < 0)
  {
    motorControl.right(180); 
    motorControl.forward(abs(y));
    motorControl.right(90);
    motorControl.forward(abs(x)); 
  }
}

void gotoPositionDirect(double x, double y)
{
  double radian =  atan2(x, y);
  double angle = radianToDeg(radian);
  double distance = abs(y / cos(radian));
  motorControl.turn(angle);
  motorControl.forward(distance);
}



