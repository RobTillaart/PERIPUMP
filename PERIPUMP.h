#pragma once
//
//    FILE: PERIPUMP.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2022-10-13
// PURPOSE: Arduino library for peristaltic pump
//
// Tested with a dfrobot peristaltic pump DFR0523
//


#include "Arduino.h"

#define PERIPUMP_LIB_VERSION        (F("0.1.0"))


class PERIPUMP
{
public:
  PERIPUMP(uint8_t pumpPin);

  void   begin();

  void   stop();
  void   setPercentage(float percentage);
  float  getPercentage();


private:
  uint8_t _pin;
  float   _percentage;
  
  void    _move(int speed);
};


// -- END OF FILE --

