#include <Servo.h> 
int sensor=0; 
Servo myservo;  
Servo myservo1;   
 void setup() 
{ 
  myservo.attach(9);  
  myservo1.attach(10);
   Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
} 
 
void loop() 
{  digitalWrite(13, HIGH); 
   sensor = digitalRead(11);
  Serial.println(sensor); 
   myservo1.write(40);
   myservo.write(90);
 if(sensor==0)
 {
  myservo1.write(100);
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo1.write(40);
  delay(1000);
  myservo.write(60);
  delay(1000);
 }
} 

