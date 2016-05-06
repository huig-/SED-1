#include "Comm.h"
SoftwareSerial serial1(10,11);
//Comm comm;
char str[200];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!serial1){;}
  serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  char f;
  if(serial1.available()){
    str[i] = serial1.read(); Serial.print(str[0]);
    delay(100);
    while(serial1.available() > 0 && i < 198){
      if (isalpha(serial1.peek())){ break;}
      f = serial1.read();
      Serial.print(f);
    }
    str[i++] = '\0';
    if(i>0){
      Serial.println();
    }
  }
  //Data data = comm.receive();
  //Serial.print(data.type);
  //Serial.println(data.value);
}
