#include <Servo.h> 
int sensor=0; 
Servo myservo;  
Servo myservo1;

int lm = 7;
int lm1 = 6;
int rm = 13;
int rm1 = 2;
int val0 = 0;
int val1 = 0;
int val2 = 0; 
int val3 = 0;
int val4 = 0;  
int old_val5=0;
int flag=0;
int obstacle=0;
int old_obstacle=0;
int obstacle_counter=0; 

int f1=0;
int f2=0;

void setup()
{
Serial.begin(9600);          
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(lm,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(rm,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(10,OUTPUT);

myservo.attach(9);  
myservo1.attach(10);
   Serial.begin(9600);
}




void loop()
{ digitalWrite(8, HIGH);
 // digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
 // digitalWrite(10, LOW);
  
  
  
   val0 = digitalRead(A0);    
   int rightsensor=val0;
   Serial.println(rightsensor);    //3=rightsensor
   val1 = digitalRead(A1);    
   int middlesensor=val1;
   Serial.println(middlesensor);    
   val2 = digitalRead(A2);    
   int leftsensor=val2;  
   Serial.println(leftsensor); //5=leftsensro 
   val3 = digitalRead(A3);    
   int sensor4=val3; 
   Serial.println(sensor4); 
   val4 = digitalRead(A4);    
   int sensor5=val4;  
   Serial.println(sensor5);
   obstacle = digitalRead(A5); 

  



   if(f1==0)
   {
     myservo1.write(40);
   myservo.write(90);
   delay(1000);
    
    myservo.write(0);
    delay(1000);
    myservo1.write(40);
    delay(1000);
    myservo.write(90);
    delay(1000);
    

    f1=1;
    delay(10);
     Serial.print("************");
    Serial.println(f1);
    delay(10);
   }

   else if(f1==2)
   {
     myservo.write(0);
    delay(1000);
    myservo1.write(100);
    delay(1000);
    myservo.write(90);
    delay(1000);
    Serial.print("**************");
    Serial.println(f1);
    delay(10);
    
   }
   
   
   else
   {
   if(sensor4 == 1 && sensor5 == 1 && old_val5 == 0 )
    {
      flag++;  
    }
   Serial.print( "------------flag--------------");
   Serial.println(flag);
    if(obstacle==0 && old_obstacle==1)
    {
      obstacle_counter++;
     }
   Serial.print( "------------obstacle_counter--------------");
   Serial.println(obstacle_counter);

   
   old_val5=sensor5;
   old_obstacle=obstacle;

 
   if(flag==1)
   {
    if (leftsensor == 0 && middlesensor == 0 && rightsensor == 0 ) {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
   
    else if (leftsensor == 0 && middlesensor == 0 && rightsensor == 1){
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
    
    else if (leftsensor == 0 && middlesensor == 1 && rightsensor == 1) {
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
    
   
   else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 1) {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
   
 else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 0)  {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
   }
   
   
  else  if (leftsensor == 1 && middlesensor == 1 && rightsensor == 0){
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
  } 
  else if(sensor4 == 1 && sensor5 == 0 &&  leftsensor == 1 && middlesensor == 1 && rightsensor == 1 ){
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
   
    }
}


    else
    { 
      sensor5=~(sensor5 & 0);  
    if (leftsensor == 0 && middlesensor == 0 && rightsensor == 0 ) {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
   
    else if (leftsensor == 0 && middlesensor == 0 && rightsensor == 1){
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
    
    else if (leftsensor == 0 && middlesensor == 1 && rightsensor == 1) {
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
    
   
   else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 1) {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
   }
   
 else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 0)  {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
   }
   
   
  else  if (leftsensor == 1 && middlesensor == 1 && rightsensor == 0){
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
  }
    
  else  if(sensor4==0 && leftsensor == 1 && middlesensor == 1 && rightsensor == 1) {
        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(10);
      }

  if(obstacle==0)

  {  if(obstacle_counter==2)
       {
        
        digitalWrite(lm,LOW);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,HIGH);   //right wheel
        delay(10);
        f1=2;
        delay(10);
       }  

       
     if(obstacle_counter==1)
     {
        digitalWrite(lm,LOW);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,LOW);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(1000);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,HIGH);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,HIGH);   //right wheel
        delay(1000);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(700);
       }
  }

}
   }
}


