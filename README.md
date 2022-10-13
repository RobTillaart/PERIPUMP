
[![Arduino CI](https://github.com/RobTillaart/PERIPUMP/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/PERIPUMP/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/PERIPUMP/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/PERIPUMP/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/PERIPUMP/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/PERIPUMP/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/PERIPUMP.svg?maxAge=3600)](https://github.com/RobTillaart/PERIPUMP/releases)


# PERIPUMP

Arduino library for peristaltic pump DFR0523 and compatibles.


## Description

The DFR0523 is a peristaltic pump which can be controlled by a PWM signal.

- TODO
- 6V 5W
- external power supply.


## Hardware schema

TODO


## Interface

#### Base

- **PERIPUMP(uint8_t pumpPin);** constructor. 
- **void begin()** initialize thingies?
- **void stop()** set % to zero.
- **void setPercentage(float percentage)** -100.0 % .. +100.0 %
- **float getPercentage()** returns set value.


## Operation

The examples show the basic working of the functions.


## Future

#### Should

- update readme.md
  - get hardware schema
  - details ...
- test
- unit test possible?
- example
- CHANGELOG.md


#### Could

- add **void setVolumePerSecond(float flow)** indication cm^3 / sec
  - at full speed?
  - need runtime counter.
- add **void pump_ml(int ml)**  autostop after X ml? possible?
- add **void slowStop()** 
  - blocking, 
  - example?
