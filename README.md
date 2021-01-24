# Reactive Light Up Hockey Goal

## Overview

This light up goal uses an array of Neopixels and a piezo sensor to sense vibration. When the hockey goal is hit with a puck, the piezo senses the vibration and triggers a flashing red and blue animation on the Neopixels driven by an Arduino Nano. 

## Demo

![](https://github.com/krum04/Reactive-Light-Up-Hockey-Goal/blob/main/goal_demo.gif?raw=true)

This was a quick build, please excuse the shoddy wire up.![](https://github.com/krum04/Reactive-Light-Up-Hockey-Goal/blob/main/images/electronics.jpg?raw=)

## Wiring

### Neopixel

	* D8 --> Din
	* 5+ --> 5+
	* GND --> GND

### Piezo 

 	* A0 --> Positive
 	* GND --> Negative
 	* 1MΩ pull down resistor across GND and A0



![](https://github.com/krum04/Reactive-Light-Up-Hockey-Goal/blob/main/images/goal_bb.png?raw=true)

## Code

The included code requires the Neopixel library from Adafruit that can be added through the Arduino Library manager. You can fine tune the sensitivity by changing the threshold. The range is 1 - 1023. 1 being the highest, 1023 being the lowest. 

```c++
const int threshold = 50;   // threshold value to decide when the detected sound is a knock or not
```

## To-Do

+ Create more animations for Neopixels

+ Move to Attiny85 and a dedicated PCB to create smaller package

+ Test threshold value for sensitivity

+ Clean up temporary mounting

  