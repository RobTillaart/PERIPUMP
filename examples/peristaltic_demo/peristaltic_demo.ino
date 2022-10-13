//
//    FILE: peristaltic_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: minimal demo
//     URL: https://github.com/RobTillaart/peristaltic
//


#include "peristaltic.h"

PERIPUMP pump(5);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("PERIPUMP_LIB_VERSION: ");
  Serial.println(PERIPUMP_LIB_VERSION);

  pump.begin();
  pump.stop();
}


void loop()
{
  int pos = analogRead(A0) - 512;   //  assumes  UNO 10 bits ADC
  pump.setPercentage(pos / 5.12);
  delay(250);
}


//  -- END OF FILE --

