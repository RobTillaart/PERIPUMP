//
//    FILE: PERIPUMP.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2022-10-13
// PURPOSE: Arduino library for peristaltic pump
//
//  HISTORY:
//  0.1.0  2022-10-13  initial version


#include "PERIPUMP.h"


//  CONSTRUCTOR
PERIPUMP::PERIPUMP(uint8_t pumpPin)
{
  _pin        = pumpPin;
  _percentage = 0;
}


void PERIPUMP::begin()
{
  _myServo.attach(_pin);
  stop();
  resetSeconds();
}


void PERIPUMP::stop()
{
  _myServo.writeMicroseconds(1500);
  if (_start != 0)
  {
    _sumTime += (millis() - _start);
    _start = 0;
  }
}


void PERIPUMP::setPercentage(float percentage)
{
  _percentage = constrain(percentage, -100, 100);

  uint16_t ms = 0;
  if (_percentage == 0)
  {
    ms = 1500;
    if (_start != 0)
    {
      _sumTime += (millis() - _start);
      _start = 0;
    }
  }
  if (_percentage < 0)
  {
    ms = 1400 + 9 * _percentage;
    if (_start == 0) _start = millis();
  }
  if (_percentage > 0)
  {
    ms = 1600 + 9 * _percentage;
    if (_start == 0) _start = millis();
  }
  _myServo.writeMicroseconds(ms);
}


float PERIPUMP::getPercentage()
{
  return _percentage;
}


//////////////////////////////////////////////////////
//
//  DURATION
//
float PERIPUMP::getSeconds()
{
  float seconds = _sumTime;
  if (_start != 0) seconds += (millis() - _start);
  return seconds * 0.001;
}


float PERIPUMP::resetSeconds()
{
  float s = getSeconds();
  _sumTime = 0;
  _start = 0;
  return s;
}


// -- END OF FILE --

