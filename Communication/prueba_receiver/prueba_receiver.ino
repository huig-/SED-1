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
  Data data = comm.receive(serial1);
  Serial.print(data.type);
  Serial.println(data.value);
}
