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
  stop();
}


void PERIPUMP::stop()
{
  _move(0);
}


void PERIPUMP::setPercentage(float percentage)
{
  _percentage = percentage;
}


float PERIPUMP::getPercentage()
{
  return _percentage;
}


void PERIPUMP::move(int speed)
{
  // TODO
}

// -- END OF FILE --

