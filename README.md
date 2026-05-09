# SensorLapTimer

SensorTimeLogger is a lap timing device based on the STM32F411CEU6 MCU.
Its purpose is to measure and record lap times using a reflective sensor.

The sensor continuously emits an electromagnetic beam. When the beam reaches a preplaced mirror (our sector), it is reflected back to the sensor. Once the reflected signal is detected, the MCU recognizes that the sector has been crossed and starts to process the sector timing data.


## Features

- Reflective sensor-based sector detection
- Writing data do microSD card
- Battery powered
- Lap time delta calculation
- Sector quantity configuration

## Hardware

- MCU: STM32F411CEU6
- Display: 5x 7-segment displays
- UI: On/Off Toggle switch, 4x interface buttons
- Sensor: WO-RPPW1

## Power Supply

Device is powered by 11.1V LiPo accumulator.
