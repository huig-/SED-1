/*

Example of BH1750 library usage.

This example initalises the BH1750 object using the default
high resolution mode and then makes a light level reading every second.

Connection:
 VCC-5v
 GND-GND
 SCL-SCL(analog pin 5)
 SDA-SDA(analog pin 4)
 ADD-NC or GND

*/

#include <Wire.h>
#include <BH1750.h>
#include "comm.h"

#define rxPIN 0
#define txPIN 1

BH1750 lightMeter;
SoftwareSerial serial(rxPIN, txPIN);
Comm comm;

void setup(){
  while (!serial);
  serial.begin(9600);
  lightMeter.begin();
  delay(5000); //wait for STM32 to be running
}


void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  comm.send(serial, lux, LIGHT); 
  delay(5000); //for synchronizing
}
