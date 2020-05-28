#include<SoftwareSerial.h>
const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 3;
const int LED5 = 5;
const int LED6 = 6;
char data = 0;

SoftwareSerial BTSerial(11,12);

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop(){
  if (BTSerial.available()){
    data = BTSerial.read();
    Serial.write(data);
    switch(data)
    {
      case'1':digitalWrite(LED1, HIGH); break;
      case'2':digitalWrite(LED2, HIGH); break;
      case'3':digitalWrite(LED3, HIGH); break;
      case'4':digitalWrite(LED4, LOW); break;
      case'5':digitalWrite(LED5, LOW); break;
      case'6':digitalWrite(LED6, LOW); break;
    }
  }
  if(Serial.available())
  BTSerial.write(Serial.read());
  delay(1);
}
