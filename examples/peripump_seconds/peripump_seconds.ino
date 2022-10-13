//
//    FILE: peripump_seconds.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/PERIPUMP.git
//


#include "PERIPUMP.h"

PERIPUMP pump(5);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("PERIPUMP_LIB_VERSION: ");
  Serial.println(PERIPUMP_LIB_VERSION);

  pump.begin();
  pump.stop();

  Serial.println(pump.getSeconds());
  delay(5000);

  Serial.println(pump.getSeconds());
  delay(1000);

  pump.setPercentage(50);
  delay(2000);
  Serial.println(pump.getSeconds());

  pump.setPercentage(75);
  delay(2000);
  Serial.println(pump.getSeconds());

  pump.stop();
  delay(2000);
  Serial.println(pump.getSeconds());
}


void loop()
{
}


//  -- END OF FILE --
