#include "comm.h"

void Comm::send(SoftwareSerial serial, float data, data_type type) {
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
    serial.print(msg);
}

Data Comm::receive(SoftwareSerial serial) {
    char msg[SIZE];
    int i = 0;
    Serial.println("Esperando a recibir");
    while (!serial.available());
    char type = serial.read(); i++;
    Serial.println("Recibido 1char, esperando mas");
    while (!serial.available());
    Serial.println("Leyendo..");
    while (serial.available() && i < SIZE) {
	if (isalpha(serial.peek())) break;
	msg[i++] = serial.read();
    }
    Serial.println("Datos leidos");
    Data data;
    if (type == pHUM) data.type = HUM;
    else if (type == pTEMP) data.type = TEMP;
    else if (type == pLIGHT) data.type = LIGHT;
    data.value = strtod(&msg[1], NULL);
    return data;
}
