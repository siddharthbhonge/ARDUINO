int lmf=2;
int lmb=3;
int rmf=4;
int rmb=5;

int val0=0;
int val1=0;
int val2=0;
int val3=0;
int val4=0;
int val5=0;

/*int oldlm1=0;
int oldrm1=0;
int oldl1=0;
int oldm1=0;
int oldr1=0;
int oldlm2=0;
int oldrm2=0;
int oldl2=0;
int oldm2=0;
int oldr2=0;
int oldlm3=0;
int oldrm3=0;
int oldl3=0;
int oldm3=0;
int oldr3=0;

int oldlm4=0;
int oldrm4=0;
int oldl4=0;
int oldm4=0;
int oldr4=0;

int oldlm5=0;
int oldrm5=0;
int oldl5=0;
int oldm5=0;
int oldr5=0;

int oldlm6=0;
int oldrm6=0;
int oldl6=0;
int oldm6=0;
int oldr6=0;

int oldlm7=0;
int oldrm7=0;
int oldl7=0;
int oldm7=0;
int oldr7=0;

int oldlm8=0;
int oldrm8=0;
int oldl8=0;
int oldm8=0;
int oldr8=0;

int oldlm9=0;
int oldrm9=0;
int oldl9=0;
int oldm9=0;
int oldr9=0;

int oldlm10=0;
int oldrm10=0;
int oldl10=0;
int oldm10=0;
int oldr10=0;

int oldlm11=0;
int oldrm11=0;
int oldl11=0;
int oldm11=0;
int oldr11=0;

int oldlm12=0;
int oldrm12=0;
int oldl12=0;
int oldm12=0;
int oldr12=0;

int oldlm13=0;
int oldrm13=0;
int oldl13=0;
int oldm13=0;
int oldr13=0;

int oldlm14=0;
int oldrm14=0;
int oldl14=0;
int oldm14=0;
int oldr14=0;

int oldlm15=0;
int oldrm15=0;
int oldl15=0;
int oldm15=0;
int oldr15=0;

int oldlm16=0;
int oldrm16=0;
int oldl16=0;
int oldm16=0;
int oldr16=0;
*/

void setup() 
{

Serial.begin(9600);          
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(lmf,OUTPUT);
pinMode(lmb,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(rmb,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() 
{
 digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  
   val0 = digitalRead(A0);    
   int lmsensor=val0;
    Serial.println("leftmostsensor=");  
   Serial.println(lmsensor);       
   val1 = digitalRead(A1);    
   int leftsensor=val1;  
   Serial.println(leftsensor); 
   val2 = digitalRead(A2);    
   int middlesensor=val2;
   Serial.println(middlesensor);
  val3 = digitalRead(A3);    
   int rightsensor=val3;
   Serial.println(rightsensor);
   val4 = digitalRead(A4);    
   int rmsensor=val4; 
    Serial.println("rightmostsensor"); 
   Serial.println(rmsensor); 
   val5 = digitalRead(A5);    
   int topsensor=val5;
   Serial.println(topsensor);
   
  if (lmsensor==1&& rmsensor==1 && leftsensor == 1 && middlesensor == 1 && rightsensor == 1 )
  {
    
    { if (leftsensor == 0 && middlesensor == 0 && rightsensor == 1)
    {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
    
    else if (leftsensor == 0 && middlesensor == 1 && rightsensor == 1) 
   {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
    
   
   else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 1) 
   {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
   
 else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 0)  
 {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(10);
   }
   
   
  else  if (leftsensor == 1 && middlesensor == 1 && rightsensor == 0)
  {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(10);
   }
   
 else if(lmsensor==1&&rmsensor==0) 
    {
      digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,HIGH);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(50);
      }
  else if(lmsensor==0&&rmsensor==1) 
    {
      digitalWrite(lmb,HIGH);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(50);
      }
   }
   
    delay(1000);
   
     if (middlesensor == 1 )
     {

    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(10);
     }
    
   }

else{
     if (leftsensor == 0 && middlesensor == 0 && rightsensor == 1)
    {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
    
    else if (leftsensor == 0 && middlesensor == 1 && rightsensor == 1) 
   {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
    
   
   else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 1) 
   {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
   
 else if (leftsensor == 1 && middlesensor == 0 && rightsensor == 0)  
 {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(10);
   }
   
   
  else  if (leftsensor == 1 && middlesensor == 1 && rightsensor == 0)
  {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(10);
   }
 else if(lmsensor==1&&rmsensor==0) 
    {
      digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,HIGH);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(50);
      }
  else if(lmsensor==0&&rmsensor==1) 
    {
      digitalWrite(lmb,HIGH);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(50);
      }
  
 

}
  

    /*else if (lmsensor==0 && rmsensor==0 && leftsensor == 0 && middlesensor == 0 && rightsensor == 0 )
    {
    digitalWrite(lmb,HIGH);  //left wheel
    digitalWrite(rmb,HIGH);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(300);
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(2000000);
   }*/
/*
 oldrm1=rmsensor;
oldlm1=lmsensor;
oldl1=leftsensor;
oldm1=middlesensor;
oldr1=rightsensor;
oldrm2=oldrm1;
oldlm2=oldlm1;
oldr2=oldr1;
oldm2=oldm1;
oldl2=oldl1;
oldrm3=oldrm2;
oldlm3=oldlm2;
oldr3=oldr2;
oldm3=oldm2;
oldl3=oldl2;
oldrm4=oldrm3;
oldlm4=oldlm3;
oldr4=oldr3;
oldm4=oldm3;
oldl4=oldl3;
oldrm5=oldrm4;
oldlm5=oldlm4;
oldr5=oldr4;
oldm5=oldm4;
oldl5=oldl4;
oldrm6=oldrm5;
oldlm6=oldlm5;
oldr6=oldr5;
oldm6=oldm5;
oldl6=oldl5;
oldrm7=oldrm6;
oldlm7=oldlm6;
oldr7=oldr6;
oldm7=oldm6;
oldl7=oldl6;
oldrm8=oldrm7;
oldlm8=oldlm7;
oldr8=oldr7;
oldm8=oldm7;
oldl8=oldl7;
oldrm9=oldrm8;
oldlm9=oldlm8;
oldr9=oldr8;
oldm9=oldm8;
oldl9=oldl8;
oldrm10=oldrm9;
oldlm10=oldlm9;
oldr10=oldr9;
oldm10=oldm9;
oldl10=oldl9;
oldrm11=oldrm10;
oldlm11=oldlm10;
oldr11=oldr10;
oldm11=oldm10;
oldl11=oldl10;
oldrm12=oldrm11;
oldlm12=oldlm11;
oldl12=oldl11;
oldm12=oldm11;
oldr12=oldr11;

oldrm13=oldrm12;
oldlm13=oldlm12;
oldl13=oldl12;
oldm13=oldm12;
oldr13=oldr12;

oldrm14=oldrm13;
oldlm14=oldlm13;
oldl14=oldl13;
oldm14=oldm13;
oldr14=oldr13;

oldrm15=oldrm14;
oldlm15=oldlm14;
oldl15=oldl14;
oldm15=oldm14;
oldr15=oldr14;

oldrm16=oldrm15;
oldlm16=oldlm15;
oldl16=oldl15;
oldm16=oldm15;
oldr16=oldr15;*/


    }






