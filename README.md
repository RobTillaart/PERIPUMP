
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
The code allows 900 steps for 0..100% so in theory precission is about 1 decimal.

Furthermore the library adds a minimalistic time registration, how long the 
pump was running since start of sketch or reset. 

- TODO
- 6V 5W
- external power supply.
- flowrate ?
  - (non) linear
- low percentages do they work?


## Hardware schema

TODO verify.

As the pump draws quite a current (1-2A) a separate power supply is needed.

```
//  POWER SUPPLY     PROCESSOR     PUMP
//
//                    PWM----------PWM
//    GND-------------GND----------GND
//
//    VCC--------------------------VCC  5V
//
```


## Interface

### Base

- **PERIPUMP(uint8_t pumpPin);** constructor. 
- **void begin()** initialize the internal variables.
- **void stop()** set speed percentage to zero, effectively stop the motor.
Also stops the duration counter.
- **void setPercentage(float percentage)** sets speed as a percentage from
-100.0 % .. +100.0 % (unknown how linear this is).
If percentage == 0, the pump stops. 
Negative values set the pump in reverse.
Positive values set the pump in forward mode.
- **float getPercentage()** returns set speed as percentage.


### Duration

- **float getRunTime()** returns total seconds running since last reset / start.
- **float resetRunTime()** returns total running since last reset / start.
Resets the internal counter to zero again.


## Operation

The examples show the basic working of the functions.


## Future

#### Should

- update readme.md
  - get hardware schema
  - details ...
- test
- examples


#### Could

- elaborate timeAccounting
  - sum += time x speed. (is that better.
- add **void setVolumePerSecond(float flow)** indication cm^3 / sec
  - at full speed?
  - need runtime counter.
  - linear / non linear interpolatable (multimap).
- add **void pump_ml(int ml)**  autostop after X ml? possible?
- add **void slowStop()** 
  - blocking, 
  - example?
- default percentage == 0 ?


#### Won't

- unit test possible?
  - No servo include fails.
  - compilation of examples works for UNO and RP2040 pico.
  
