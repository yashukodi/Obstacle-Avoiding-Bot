#include<SoftwareSerial.h>
#define en1 11
#define en2 12
int trigPin = 9; // trig pin of HC-SR04
int echoPin = 10; // Echo pin of HC-SR04
int revleft4 = 4; //REVerse motion of Left motor
int fwdleft5 = 5; //ForWarD motion of Left motor
int revright6 = 6; //REVerse motion of Right motor
int fwdright7 = 7; //ForWarD motion of Right motor
long duration, distance;
void setup() {
delay(random(500,2000)); // delay for random time
Serial.begin(9600);
pinMode(revleft4, OUTPUT); // set Motor pins as output
pinMode(fwdleft5, OUTPUT);
pinMode(revright6, OUTPUT);
pinMode(fwdright7, OUTPUT);
pinMode(trigPin, OUTPUT); // set trig pin as output
pinMode(echoPin, INPUT);
pinMode(3,OUTPUT);//set echo pin as input to capture reflected waves
}
void loop() {
digitalWrite(3,HIGH);
digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // send waves for 10 us
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);    
duration = pulseIn(echoPin, HIGH); // receive reflected waves
distance = duration*0.034/2;// convert to distance
delay(10);
// If you dont get proper movements of your robot then alter the pin numbers
if (distance >= 19)
{
digitalWrite(fwdright7, HIGH); // move forward
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, HIGH);
digitalWrite(revleft4, LOW);
}
Serial.println(distance);
if (distance < 5)
    {
digitalWrite(fwdright7, LOW); //Stop
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, LOW);
delay(100);
digitalWrite(fwdright7, LOW); //movebackword
digitalWrite(revright6, HIGH);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, HIGH);
delay(100);
digitalWrite(fwdright7, LOW); //Stop
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, LOW);
delay(100);
digitalWrite(fwdright7, HIGH);
digitalWrite(revright6, LOW);
digitalWrite(revleft4, LOW);
digitalWrite(fwdleft5, LOW);
delay(100);
}
}
