#ifndef COMM_H
#define COMM_H
#endif

#include <stdio.h>
#include <SoftwareSerial.h>
#include <ctype.h>
#include <stdlib.h>

#define pLIGHT 'l'
#define pTEMP 't'
#define pHUM 'h'
#define SIZE 50

typedef enum { LIGHT, TEMP, HUM} data_type;
struct Data {
    data_type type;
    float value;
};

class Comm {
    public:
	void send(SoftwareSerial serial, float data, data_type type);
	Data receive(SoftwareSerial serial);
};

