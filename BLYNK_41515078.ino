/***********************************
BlYNK Arduino Code _Made By 41515015  
************************************/

#define BLYNK_PRINT Serial

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

//You Should Get Auth Token In The Blynk App
// Go To The Project Settings (nut icon).

char auth[] = "8A_iFjUvgnQuOYLikYwFZSPwXLDMiczi";  //Auth Token

//Your Wifi Credentials
const char* ssid="EDIYA 2F";  //Your Network Name
const char* pass="ed20160708";     //Your Password

int LD1 = D3; //gpio0
int LD2 = D4; //gpio2 Defalut LED

void setup()
{
  //Debug Console
  Serial.begin(115200);
  pinMode(LD1,OUTPUT);
  pinMode(LD2,OUTPUT);
  digitalWrite(LD1, LOW);   //if HIGH than LED On
  digitalWrite(LD2, HIGH);  //if LOW than LED On
  Blynk.begin(auth,ssid,pass);

  //You can also specify server
  //Blynk.begin(auth,ssid,pass,"blynk-cloud.com",8422);
  //Blynk.begin(auth,ssid,pass,IPAddress(192,168,1,123),8422);

  //timer.setinterval(1000L,blinkLedWidget); //Timer on
}

void loop()
{
  Blynk.run();
//timer.run();
}

BLYNK_WRITE(V0){
  int pinValue=param.asInt(); //V3에서 들어오는 값을 변수에 할당

  if(pinValue==1){
    digitalWrite(LD1,HIGH); //LED를 켬
  }
  else{
    digitalWrite(LD1,LOW); //LED를 끔
  }
//  Serial.println(pinValue);
}

BLYNK_WRITE(V2){
  int pinValue=param.asInt(); //V3에서 들어오는 값을 변수에 할당

  if(pinValue==1){
    digitalWrite(LD2,HIGH); //LED를 켬
  }
  else{
    digitalWrite(LD2,LOW); //LED를 끔
  }
//  Serial.println(pinValue);
}
  
