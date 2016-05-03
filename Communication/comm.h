#ifndef _COMM_H
#define _COMM_H

#include <stdio.h>
#include <SotwareSerial.h>
#include <ctype.h>
#include <cstdlib.h>

#define pLIGHT 'l'
#define pTEMP 't'
#define pHUM 'h'
#define SIZE 50

typedef enum { LIGHT, TEMP, HUM} data_type;
struct Data {
    data_type type;
    float value;
};

void send(SoftwareSerial serial, float data, data_type type);
float receive(SoftwareSerial serial, Data *data);
