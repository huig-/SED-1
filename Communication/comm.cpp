#include "comm.h"

void Comm::send(SoftwareSerial serial, float data, data_type type) {
    char header;
    switch (type) {
	case LIGHT:
	    header = pLIGHT;
	    break;
	case TEMP:
	    header = pTEMP;
	    break;
	case HUM:
	    header = pHUM;
	    break;
    }
    serial.print(header);
    serial.print(data);
    serial.print('\n');
    
}

Data Comm::receive(SoftwareSerial serial) {
    char msg[SIZE];
    int i = 0;
    while (!serial.available());
    char type = serial.read(); i++;
    while (!serial.available());
    while (serial.available() && i < SIZE) {
	if (isalpha(serial.peek())) break;
	msg[i++] = serial.read();
    }
    Data data;
    if (type == pHUM) data.type = HUM;
    else if (type == pTEMP) data.type = TEMP;
    else if (type == pLIGHT) data.type = LIGHT;
    data.value = strtod(&msg[1], NULL);
    return data;
}
