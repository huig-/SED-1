#include "Comm.h"

#define rxPIN 0
#define txPIN 1

SoftwareSerial serial1(rxPIN, txPIN);
Comm comm;

void setup() {
  // put your setup code here, to run once:
  while (!serial1);
  serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  comm.send(serial1, 1298.2, TEMP);
  delay(5000);
  
}
