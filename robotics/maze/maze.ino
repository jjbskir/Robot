/*
  maze
*/

#include <DCMotorControl.h>

DCMotorControl motorControl(158, 200, 10, 5, 9, 7, 8, 6);
int button = 13;
int sensor1 = 12;
int sensor2 = 4;
boolean buttonState;
int state = 100;
int distance = 1.0;

void setup()
{
  Serial.begin(9600); 
  pinMode(button, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  Serial.print("Robot on \n");
}


void loop()
{
  if (state == 0)
  {
    start();
  }
  else if (state == 1)
  {
     followWall();
  }
  else if (state == 2) 
  {
     followCorner(); 
  }
  else if (digitalRead(button) != HIGH)
  {
    state = 0;
  }
}

void start()
{
  if (findWall(3) == true)
  {
    state = 1;
  }
  else
  {
    state = 0;
  }
}


void spiral()
{
  double r = 0;
  double a = 1.0;
  double b = 0;
  double angle = 0;
  double radian = 0;
  for (radian; radian < 6.28; radian += .001) 
  {
    r = radian*a + b;
    angle = radianToDeg(radian);
    motorControl.forward(r);
    motorControl.right(angle);
    if (digitalRead(sensor1) == HIGH || digitalRead(sensor2) == HIGH)
    {
      state = 1;
      break;
    }
  }
}

double radianToDeg(double radian)
{
  double deg = (180/3.14) * radian;
  return deg;
}

boolean findWall(double mult)
{
 for (double x = 0; x < distance*mult; x += .05)
  {
    motorControl.forward(.05);
    if (digitalRead(sensor1) == HIGH || digitalRead(sensor2) == HIGH)
    {
      return true;
    }
  }
 return false;
}

void followWall() 
{
  motorControl.backward(distance);
  motorControl.right(90);
  if (findWall(1) == true)
  {
    state = 1;
    return;
  }
  motorControl.left(90);
  if (findWall(2) == false)
  {
    state = 2;
  }
  else 
  {
    state = 1;
  }
}

void followCorner()
{
  motorControl.left(90);
  if (findWall(2) == true)
  {
    state = 1;
    return;
  }
  motorControl.left(90);
  if (findWall(2) == false)
  {
    state = 1;
  }
  else 
  {
    state = 1;
  }
}









