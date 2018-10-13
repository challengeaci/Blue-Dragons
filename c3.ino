#include<SoftwareSerial.h>

SoftwareSerial mySerial(9,10);
const int MQ3=0;
const int Buzzer=8;
const int LED=13;
int Value;
void setup(){
  //put your setup code here,to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(MQ3,INPUT);
   pinMode(Buzzer,OUTPUT);
    pinMode(LED,OUTPUT);
    digitalWrite(Buzzer,LOW);
    digitalWrite(LED,LOW);
}
void SendMessage()
{
  mySerial.println("AT+CMGF=1");
  Serial.write(mySerial.read());
  delay(1000);
  mySerial.println("AT+CMGS=\"+919515388167\"\r");
  Serial.write(mySerial.read());
  delay(1000);
  mySerial.println("you are caught");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void loop()
{
  Value=analogRead(MQ3);
  Serial.println(Value);
  if(Value>550)
  {
    digitalWrite(Buzzer,HIGH);
    digitalWrite(LED,HIGH);
    SendMessage();
  }
  else
  {
    digitalWrite(Buzzer,LOW);
    digitalWrite(LED,LOW);
    
  }
  delay(1000);
}
  
