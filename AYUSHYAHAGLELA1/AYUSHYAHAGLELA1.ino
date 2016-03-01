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

int oldr=8;
int oldl=8;


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
   
 else if(lmsensor==1&&rmsensor==0 ) 
    {{
      digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,HIGH);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(50);
      }
      
    }
  else if(lmsensor==0&&rmsensor==1 ) 
  {  {
    digitalWrite(lmb,HIGH);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(50);
      }
      
  }
 
else  if ((lmsensor==0 && rmsensor==0) || (leftsensor==0 && middlesensor==0 && rightsensor==0))
  {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(2000000000000);
   }


  
   }






