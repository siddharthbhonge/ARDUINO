int lm = 7;
int lm1 = 6;
int rm = 13;
int rm1 = 2;

int rightsensor = 0;
int middlesensor = 0;
int leftsensor = 0; 
int sensor4 = 0;
int sensor5 = 0;

int old_rightsensor = 0;
int old_middlesensor = 0;
int old_leftsensor = 0; 
int old_sensor4 = 0;
int old_sensor5 = 0;

int i=0;

void setup()
{
Serial.begin(9600);          
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
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
}


 


void loop()
{ digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  
  
   rightsensor = digitalRead(A0);    
   Serial.print("rightsensor=");  
   Serial.println(rightsensor);//3=rightsensor
   
   middlesensor = digitalRead(A1);    
   Serial.print("middlesensor=");  
   Serial.println(middlesensor);
       
   leftsensor = digitalRead(A2);    
   Serial.print("leftsensor=");   
   Serial.println(leftsensor);//5=leftsensro
    
   sensor4 = digitalRead(A3);    
   Serial.print("leftmost sensor="); 
   Serial.println(sensor4);
    
   sensor5 = digitalRead(A4);    
   Serial.print("rightmost sensor="); 
   Serial.println(sensor5);

   
   Serial.print("***********THE COUNTER IS***********=");
   Serial.println(i);


   if((sensor4==0 &&sensor5==0) && (old_sensor4==1 || old_sensor5==1))
     {
      i++;
      }
 old_rightsensor=rightsensor;
 old_middlesensor=middlesensor;
 old_leftsensor=leftsensor;
 old_sensor4=sensor4;
 old_sensor5=sensor5;

 
   if( (sensor4==0 && sensor5==0)||(sensor4==1 && sensor5==1))
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
   
  //   else if (leftsensor == 1 && middlesensor == 1 && rightsensor == 1){
    //digitalWrite(lm,LOW);  //left wheel
  //  digitalWrite(rm,HIGH);   //right wheel
   // digitalWrite(lm1,LOW);  //left wheel
    //digitalWrite(rm1,HIGH);   //right wheel
    //delay(10);
    //}
}



 if(i==4)
 { if (leftsensor == 0 && middlesensor == 0 && rightsensor == 0 ) {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
   }
   }
}


