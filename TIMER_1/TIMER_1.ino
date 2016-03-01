int lmf=2;
int lmb=3;
int rmf=4;
int rmb=5;
int led = 13;
unsigned long timer; // the timer
boolean timedOut = false; // set to true when timer fired
unsigned long INTERVAL = 17100; // the timeout interval


int val0=0;
int val1=0;
int val2=0;
int val3=0;
int val4=0;
int val5=0;

int oldlm=0;
int oldrm=0;
int oldleft=0;
int oldmid=0;
int oldrite=0;

    
int lmsensor=0;
int rmsensor=0;
int rightsensor=0;
int leftsensor=0;
int middlesensor=0;

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

pinMode(led, OUTPUT); // initialize LED output
  timedOut = false; // allow timer to fire
  timer = millis(); // start timer  
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
     
          
   val1 = digitalRead(A1);    
   int leftsensor=val1;  
    
   val2 = digitalRead(A2);    
   int middlesensor=val2;
   
  val3 = digitalRead(A3);    
   int rightsensor=val3;
   
   
      val4 = digitalRead(A4);    
   int rmsensor=val4; 
    

  
  if( (lmsensor==1&&rmsensor==1) || (lmsensor==0&&rmsensor==0) )
   {
if (leftsensor == 0 && middlesensor == 0 && rightsensor == 0)
    {
    digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,HIGH);  //left wheel
    digitalWrite(rmf,HIGH);   //right wheel
    delay(10);
   }
   
     else if (leftsensor == 0 && middlesensor == 0 && rightsensor == 1)
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
  if ((!timedOut) && ((millis() - timer) > INTERVAL)) {
 timedOut = true;
  if (!digitalRead(led) && leftsensor == 1 && middlesensor == 1 && rightsensor == 1&& lmsensor==1&&rmsensor==1) 
  digitalWrite(led,HIGH);
   delay(20);
   digitalWrite(led,LOW);
   digitalWrite(lmb,LOW);  //left wheel
    digitalWrite(rmb,LOW);   //right wheel
    digitalWrite(lmf,LOW);  //left wheel
    digitalWrite(rmf,LOW);   //right wheel
    delay(1000000);
  

  } 
     
   
    


  
      
   }

