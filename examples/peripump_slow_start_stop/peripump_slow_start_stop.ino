//
//    FILE: peripump_slow_start_stop.ino
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

  pump.setPercentage(0);
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(pump.getPercentage());
  Serial.println();

  //  take 0.5 seconds to go to 100%
  slowStart(100.0, 1000);
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(pump.getPercentage());
  Serial.println();
  delay(1000);

  slowStop(500);
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(pump.getPercentage());
  Serial.println();
  delay(1000);

  slow(0, 100, 250);
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(pump.getPercentage());
  Serial.println();
  delay(1000);

  slowStop(10);
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(pump.getPercentage());
  Serial.println();
  delay(1000);

  pump.stop();
  delay(1000);
}

void loop()
{
}

void slowStart(float perc, uint32_t mils)
{
  slow(0, perc, mils);
}


void slowStop(uint32_t mils)
{
  slow(pump.getPercentage(), 0, mils);
}


//  blocking slow speed adjustment
uint32_t slow(float percStart, float percStop, uint32_t mils)
{
  uint32_t count = 0;
  uint32_t start = micros();
  float step = (percStop - percStart) / (mils * 1000.0);
  while (micros() - start < (mils * 1000))
  {
    float speed = percStart + step * (micros() - start);
    pump.setPercentage(speed);
    //  Serial.println(speed);
    count++;
  }
  pump.setPercentage(percStop);
  //  Serial.println(count);
  return count;
}


//  -- END OF FILE --
