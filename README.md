
[![Arduino CI](https://github.com/RobTillaart/PERIPUMP/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/PERIPUMP/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/PERIPUMP/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/PERIPUMP/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/PERIPUMP/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/PERIPUMP/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/PERIPUMP.svg?maxAge=3600)](https://github.com/RobTillaart/PERIPUMP/releases)


# PERIPUMP

Arduino library for peristaltic pump DFR0523 and compatibles.


## Description

VERY EXPERIMENTAL - AVR (UNO) only for now. 

The DFR0523 is a peristaltic pump which can be controlled by a PWM signal. 
To hide the details of the servo this library gives control by setting the
speed as a percentage -100.0% .. 100.0%. 
The code allows 900 steps for 0..100% so in theory precision is about 1 decimal.

Furthermore the library adds a minimalistic time registration. 
It measures how long the pump has been running since the start of the sketch or 
since the last call to **resetRunTime()**. 

As the DFR0523 uses ~1A when running, an external power supply is mandatory.




## Hardware schema

TODO verify.

As the pump draws quite a current (1-2A) a separate power supply of 5V is needed.

```
//  POWER SUPPLY     PROCESSOR     PUMP
//
//                    PWM----------PWM
//        GND---------GND----------GND
//
//    5V  VCC----------------------VCC
//
```


## Interface

### Base

- **PERIPUMP(uint8_t pumpPin)** constructor. pumpPin should be a PWM supporting pin.
- **void begin()** initialize the internal variables.
- **void stop()** set speed percentage to zero, effectively stop the motor.
Also stops the duration counter.
- **void setPercentage(float percentage)** sets speed as a percentage from
-100.0 % .. +100.0 %.
  - If percentage == 0, the pump stops. 
  - Negative values set the pump in reverse.
  - Positive values set the pump in forward mode.
- **float getPercentage()** returns set speed as percentage.


### Duration

- **float getRunTime()** returns total seconds running since last reset / start.
- **float resetRunTime()** returns total running since last reset / start.
Resets the internal time counter to zero again.


## Operation

The examples show the basic working of the functions.


## Future

#### Should

- update readme.md
- test
- examples
- investigate flowrate == (non) linear?
- investigate low percentages do they work?

#### Could

- investigate timeAccounting?
  - sum += time x speed - is that better? 
- investigate flow support
  - add **void setVolumePerSecond(float flow)** indication cm^3 / sec
  - at full speed?
  - linear / non linear interpolatable (multimap).
  - difference per pump?
- add **void pump_ml(int ml)**  autostop after X ml? possible?
- add **void slowStop()** 
  - blocking, 
  - example?
- default percentage == 0 ?


#### Won't

- unit test possible?
  - No servo.h include fails.
  - compilation of examples works for UNO and RP2040 pico.
  
