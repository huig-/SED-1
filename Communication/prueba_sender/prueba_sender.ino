#include "Comm.h"

#define rxPIN 10
#define txPIN 11

SoftwareSerial serial1(rxPIN, txPIN);
Comm comm;

void setup() {
  // put your setup code here, to run once:
  pinMode(rxPIN, INPUT);
  pinMode(txPIN, OUTPUT);
  Serial.begin(9600);
  serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  comm.send(serial1, 5332, TEMP);
}
