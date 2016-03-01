int lm = 7;
int lm1 = 6;
int rm = 13;
int rm1 = 2;

int leftsensor=0;
int middlesensor=0;
int rightsensor=0;

int val0 = 0;
int val1 = 0;
int val2 = 0; 
int val3 = 0;
int val4 = 0;  
int old_5=0;

int i=0;
int flag=0;
int old5=0;
int varchaflag=0;
int obstacle=0;
 
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

}

void linetracer()
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
   
   Serial.print("flag=");  
   Serial.println(flag);
   
  
   middlesensor = digitalRead(A1);    
   Serial.print("varchaflag=");
       
     
     
   Serial.println(varchaflag); //5=leftsensro 


   val3 = digitalRead(A3);    
   int sensor4=val3; 
   
   val4 = digitalRead(A4);    
   int sensor5=val4;  
   //Serial.print("varchaflag"); 
   //Serial.println(sensor5); 

    obstacle= digitalRead(A5);


    if(sensor5==1 && old_5==0)
    {
      flag==0;  
    }
    old_5=sensor5;

   if(flag==0)
   {
    linetracer();
    if(sensor4 == 1 && sensor5 == 0){
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);
    flag=1;
    }
}


    if(flag==1)
    {
      digitalWrite(9,LOW);
      linetracer();
      if(sensor4==0 && leftsensor == 1 && middlesensor == 1 && rightsensor == 1)
      {
        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(10);
        }
    }

    if(obstacle==0)
    {
      varchaflag=1;
      flag=2;
    }

    if(varchaflag==1)
    {
        digitalWrite(lm,LOW);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,LOW);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(500);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,HIGH);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,HIGH);   //right wheel
        delay(500);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(500);

        varchaflag=0;
        flag=1;
    }
}




