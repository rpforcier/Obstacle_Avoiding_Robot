#ifndef sound_h
#define sound_h

#include "sound.h"

//Motor and Speaker Variables
int motorSpeed = HIGH;
int delayTime = 3000;

int enablePin12 = 9;
int motorPin1 = 8;
int motorPin2 = 7;

int enablePin34 = 6;
int motorPin4 = A4;
int motorPin3 = A3;

int ledPin = A5;

//Limit Switch Variables
int limitPin1 = 3;
int limitPin2 = 2;
int hitFlag = 0; 

//Collision Interrupt
void hitISR()
{
  hitFlag = 1;
}

//Startup Function
void pinAssign()
{
  pinMode(enablePin12, OUTPUT);
  pinMode(enablePin34, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  pinMode(limitPin1, INPUT_PULLUP);
  pinMode(limitPin2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2), hitISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), hitISR, FALLING);

  digitalWrite(enablePin12, HIGH);
  digitalWrite(enablePin34, HIGH);

  startupSound();  
}

//Motor Functions
void forward()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin4, HIGH);
}

void back()
{
  digitalWrite(motorPin1, 0);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, 0);
}

void right()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, 0);
}

void left()
{
  digitalWrite(motorPin1, 0);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin4, HIGH);
}

void brake()
{
  digitalWrite(motorPin1, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin4, 0);
}

void flash(int repeatFlash)
{
  for (int i = 0; i < repeatFlash; i++)
  {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  }
}

void rightOrLeft()
{
  randomSeed(analogRead(A6));
  int randDirection = random(1,3);

  if (randDirection == 1)
  {
    flash(1);
    right();
  }
  else if (randDirection == 2)
  {
    flash(2);
    left();
  }
  
}

void newPath()
{
    brake();
    hitSound();
    flash(3);
    back();
    delay(2000);
    brake();
    delay(1000);
    rightOrLeft();
    delay(500);
    brake();
    delay(1000);
}

#endif
