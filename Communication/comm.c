#include "comm.h"

void send(SoftwareSerial serial, float data, data_type type) {
    char msg[SIZE];
    switch (type) {
	case LIGHT:
	    msg[0] = pLIGHT;
	    break;
	case TEMP:
	    msg[0] = pTEMP;
	    break;
	case HUM:
	    msg[0] = pHUM;
	    break;
    }
    sprintf(&msg[1], "%f", data);
    serial.println(msg);
}

void receive(SoftwareSerial serial, Data *data) {
    char msg[SIZE];
    int i = 0;
    while (!serial.available());
    char type = serial.read(); i++;
    while (!serial.available());
    while (serial.available() && i < SIZE) {
	if (isalpha(serial.peek())) break;
	msg[i++] = serial.read();
    }
    data->type = type;
    data->value = strtof(&msg[1], NULL);
}
