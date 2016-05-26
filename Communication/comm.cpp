#include "comm.h"

void Comm::send(SoftwareSerial serial, float data, data_type type) {
    char header;
    switch (type) {
	case LIGHT:
	    char d;
	    header = pLIGHT;
	    if (data < 0.02 && data > 0.001) d = NIGHT;
	    else if (data >= 0.02 && data < 0.3) d = MOON;
	    else if (data >= 5 && data < 50) d = CLOUDY_INDOOR;
	    else if (data >= 50 && data < 500) d = CLOUDY_OUTDOOR;
	    else if (data >= 100 && data < 1000) d = SUNNY_INDOOR;
	    else if (data >= 10000) d = SUNLIGHT;
	    serial.print(header);
	    serial.print(c);
	    serial.print('\n');
	    break;
	case TEMP:
	    header = pTEMP;
	    serial.print(header);
	    serial.print(data);
	    serial.print('\n');
	    break;
	case HUM:
	    header = pHUM;
	    serial.print(header);
	    serial.print(data);
	    serial.print('\n');
	    break;
    }
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
