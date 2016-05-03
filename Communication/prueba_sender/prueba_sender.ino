#include "Comm.h"
SoftwareSerial serial1(10,11);
Comm comm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!serial1) {;}
  serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  comm.send(serial1, 5332, TEMP);
}
