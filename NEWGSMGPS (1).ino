#include<TinyGPS++.h>
#include<SoftwareSerial.h>
SoftwareSerial Seria(9,10);
SoftwareSerial ss(2,3);
TinyGPSPlus gps;


void setup() {
  Serial.begin(9600);
  Seria.begin(9600);
  ss.begin(9600);
   /*gsm.write("ATD+919460322265;\r");
   Seria.write("AT+CMGF=1\r");
   delay(1000);
   Seria.write("AT+CMGS=\"+916000796826\"\r");
   delay(1000);
   Seria.write("his");
   Seria.println("sent");
   delay(1000);
   Seria.write(0x1A);
   delay(1000);
   gsm.write("AT+CNMI=2,2,0,0,0\r");
   delay(1000);*/
}

void loop() {
  /* Seria.write("AT+CMGF=1\r");
   delay(1000);
   Seria.write("AT+CMGS=\"+916000796826\"\r");
   delay(1000);
   Seria.write("hi");
   Seria.println("sent");
   delay(1000);
   Seria.write(0x1A);
   delay(1000);*/
  while(ss.available()>0)
  {
    gps.encode(ss.read());
    if(gps.location.isUpdated()){
      Serial.print("Latitude=");
      Serial.print(gps.location.lat(),6);
      Serial.print("Longitude=");
      Serial.print(gps.location.lng(),6);
      delay(1000); 
    }
  }
}
/*if(gsm.available()>0)
{
  inchar=gsm.read();
  if(inchar=='#')
  {
    delay(10);
    inchar=gsm.read();
    if(inchar=='0')
    {
      Serial.write("off");
      digitalWrite(2,LOW);
    }
    
   else if(inchar=='1')
    {
      Serial.write("on");
      digitalWrite(2,HIGH);
    }
    delay(3000);
  }
}*/
