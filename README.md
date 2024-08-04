WS2812 Driver for STM32
This repository provides a driver for controlling WS2812 LEDs using STM32 microcontrollers. The code is designed for the TIM1 Channel 1 of 
the STM32L474 MCU but can be adapted for other configurations.

Getting Started
1. Add the Driver to Your Project
Include Files:
Add the Inc and Src directories from this repository to your STM32 project.
Include the Header File:
Add #include "WS2812_middle.h" to your main project file where you want to use the WS2812 driver.

3. Using the Driver
You can call the functions defined in WS2812_middle.h to control WS2812 LEDs.
4. Configuration
Microcontroller Specifics:

This driver is initially configured for TIM1 Channel 1 on the STM32L474 MCU.
To use this driver with different hardware configurations, modify the settings in WS2812_Hardware.c.
LED Count:

Adjust the maximum number of LEDs by changing the value in WS2812_Hardware.h.
4. Compatibility
The overall structure of this driver code is compatible with other STM32 MCUs.
You likely won’t need to modify WS2812_middle.h and WS2812_middle.c for different MCUs.
Notes
Ensure that your hardware setup aligns with the configuration specified in WS2812_Hardware.c for proper functionality.
