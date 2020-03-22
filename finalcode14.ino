#include<Servo.h>
Servo myservo;
const int watersens=A0;
int pos=0;
const int trigpin = 8;
const int echopin = 10;
const int buzzerPin = 4;
const int flamePin = 11;
const int pumppin=9;
int Flame = HIGH;
int redled = 5;
int greenled = 6;
long duration;
int distance;
int safetydistance;
void setup()
{
pinMode(buzzerPin, OUTPUT);
pinMode(pumppin,OUTPUT);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(flamePin, INPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);
myservo.attach(7);
}
void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  safetydistance = distance;
  Flame = digitalRead(flamePin);
if(safetydistance<=1)
{
  digitalWrite(buzzerPin,HIGH);
  digitalWrite(redled,HIGH);
  digitalWrite(greenled,LOW);
  Serial.println("ATD8341231333;");
  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"+918341231333\"\r");
  Serial.println("the dustbin 1 is filled in the vignan university");
  Serial.println((char)26);
  }
  if(safetydistance>=1)
  {
    digitalWrite(buzzerPin,LOW);
    digitalWrite(redled,LOW);
    digitalWrite(greenled,HIGH);
    }
  

if(Flame== LOW)
{
Serial.println("ATD9493268215");
digitalWrite(buzzerPin, HIGH);
digitalWrite(pumppin,HIGH);
digitalWrite(redled, HIGH);
digitalWrite(greenled, LOW);
Serial.println("AT+CMGF=1");
delay(1000);

Serial.println("AT+CMGS=\"+919493268215\"\r");
Serial.println("fire in the dustbin 1 in vignan university");
Serial.println((char)26);
}
if(Flame== HIGH)
{
digitalWrite(buzzerPin, LOW);
digitalWrite(pumppin,LOW);
digitalWrite(greenled, HIGH);
digitalWrite(redled, LOW);
}
 int sensorvalue=analogRead(watersens);
  sensorvalue=map(sensorvalue,0,1023,0,180);
  if(sensorvalue>=50)
  {
    for(pos=0;pos<=180;pos+=1)
    {
      myservo.write(pos);
      delay(15);
    }
    for(pos=180;pos>=0;pos-=1)
    {
      myservo.write(pos);
      delay(15);
    }
  }
  else{
    myservo.write(0);
  }
  Serial.println(sensorvalue);
  }
