int lm = 7;
int lm1 = 6;
int rm = 13;
int rm1 = 2;

int val0 = 0;
int val1 = 0;
int val2 = 0; 
int val3 = 0;
int val4 = 0;  

int leftsensor=0;
int middlesensor=0;
int rightsensor=0;
int sensor4=0;
int sensor5=0;
int obstacle=0;

int i=0;
int flag=0;
int old4=0;
int old5=0;
int old_m1=0;
int old_m2=0;
int old_val4=0;
int old_val5=0;
int old4_1=0;
int old4_2=0;
int old4_3=0;
int old4_4=0;
int old4_5=0;
int old5_6=0;
int old5_5=0;
int old5_8=0;
int old4_8=0;
int old5_1=0;
int flag4=8;
int flag5=8;
int flag4_1=8;
int oldm=8;
int oldr=8;
int j=8;
      
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
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(10,OUTPUT);
}


void linetracer()
{
  {
  if(sensor4==1 && sensor5==1)
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
}
}


void loop()
{ digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
 
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  
  
   val0 = digitalRead(A1);    
   rightsensor=val0;
    //3=rightsensor
   val1 = digitalRead(A2);    
   middlesensor=val1;
     
   val2 = digitalRead(A3);    
   leftsensor=val2;  
   


   val3 = digitalRead(A0);    
   sensor4=val3; 
   val4 = digitalRead(A4);    
   sensor5=val4;  
   obstacle=digitalRead(4);  
   
   
Serial.println(i);

if((i==0 || i==1 ) && sensor4==1 && old4 == 0)
{
  i++;
  delay(10);
}
 
   old4=sensor4;
   old5=sensor5;
  
  if(i==2)
  { 
   if(sensor4 ==1 && old4_1==0)
   {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(950);
    Serial.println(i);
    i=3;
   }
 else
   {
      linetracer();
      delay(10);
    } 
     
old4_1=sensor4;
  }

   else if(i==3)
  {
    if(sensor5==1 && oldr==0)
    {
    delay(100);
    linetracer();
     j=1;
    Serial.println(i);
   }
   else if(j==1 && sensor5==0 && old5_5 )
    {
      delay(100);
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,HIGH);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(700);
     i=4;
    Serial.println(i);
    }
    else
    {
      linetracer();
      delay(10);
    }
  old5_5=sensor5;
  oldm=middlesensor;
  oldr=sensor5;
  }
    
    else if(i==4)
    {
    if((sensor5==0 && middlesensor==0 && sensor4==0) && (old4_2 || old5_6==1))
    {  
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(600);
    i=5;
    
    Serial.println(i);
    
    
    }
    else
    {
      linetracer();
      delay(10);
    }
    
    old4_2=sensor4;
    old5_6=sensor5;
    }
    
    else if(i==5)
    {
    if(sensor4==0 && middlesensor==0 && old_m2==1)
    {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(600);
    Serial.println(i);
     sensor4=~(sensor4 & 0);
    i=6;
    
    }
    else
    {
      linetracer();
      delay(10);
    }
    
    old_m2=middlesensor;
    }
        else if(i==6)
    {
       {
    if((sensor5==0 && sensor4==0) && (old4_2 || old5_8==1))
    {  
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(100);
    
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,HIGH);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(550);
    
    i=7;
    
    Serial.println(i);
    
    
    }
    else
    {
      linetracer();
      delay(10);
    }
    
    old4_8=sensor4;
    old5_8=sensor5;
    }
    }
    
    else if(i==7)
    {
    
   linetracer();
    sensor5=~(sensor5 & 0);
    if(sensor4==0 && flag4==1)
    {
    /*digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel*/
    delay(100);
      i=8;
    Serial.println(i);
    
    }
    else
    {
     linetracer();
     delay(10);
     }
    flag4=sensor4;
    flag5=sensor5;
}

    else if(i==8)
    {
    if(sensor4==0 && flag4_1==1)
    {
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(50); 
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,HIGH);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(500);

    
      i=9;
    Serial.println(i);
    
    }
    
    else
    {
      linetracer();
      delay(10);
    }
    flag4_1=sensor4;
    }
    
    else if(i==9)
    {
      if(obstacle==0)
     {  
        digitalWrite(lm,LOW);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,LOW);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(700);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,HIGH);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,HIGH);   //right wheel
        delay(1000);

        digitalWrite(lm,HIGH);  //left wheel
        digitalWrite(rm,LOW);   //right wheel
        digitalWrite(lm1,HIGH);  //left wheel
        digitalWrite(rm1,LOW);   //right wheel
        delay(750);
       }
       else
       {
      linetracer();
      delay(10);
    }
    
   }
}   
