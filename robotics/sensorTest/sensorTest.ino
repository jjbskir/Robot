/*
  maze
*/

#include <DCMotorControl.h>

DCMotorControl motorControl(158, 200, 10, 5, 9, 7, 8, 6);
int button = 13;
int sensor1 = 12;
int sensor2 = 4;
boolean buttonState;

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
  testSensor()
}

void testSensor()
{
  int signal1 = digitalRead(sensor1);
  int signal2 = digitalRead(sensor2);
  if (signal1 == HIGH) 
  {
    Serial.print("signal high");
  }
  else 
  {
    Serial.print("signal low");
  }
  Serial.print("\n");
  if (signal2 == HIGH) 
  {
    Serial.print("signal high");
  }
  else 
  {
    Serial.print("signal low");
  }
  Serial.print("\n");
  delay(1000);
}
