int lm = 7;
int lm1 = 6;
int rm = 9;
int rm1 = 2;

int val0 = 0;
int val1 = 0;
int val2 = 0; 
int val3 = 0;
int val4 = 0;  

int i=0;
int old4=0;
int old5=0;
 
void setup()
{
Serial.begin(9600);          
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(8,OUTPUT);
//pinMode(9,OUTPUT);
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
 // digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  
  
  val0 = digitalRead(A1);    
   int rightsensor=val0;
    Serial.println("rightsensor=");  
   Serial.println(rightsensor);    //3=rightsensor
   val1 = digitalRead(A2);    
   int middlesensor=val1;
   Serial.println(middlesensor);    
   val2 = digitalRead(A3);    
   int leftsensor=val2;  
   Serial.println(leftsensor); //5=leftsensro 


   val3 = digitalRead(A4);    
   int sensor4=val3; 
    Serial.println("sensor4"); 
   Serial.println(sensor4); 
   val4 = digitalRead(A0);    
   int sensor5=val4;  
   Serial.println(sensor5);


   if((sensor4==1 && sensor5==1) && (old4==0|| old5==0))
   {
    i++;
   }
    Serial.print("the counter is");
   Serial.println(i);

   old4=sensor4;
   old5=sensor5;
   
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
if(leftsensor == 1 && middlesensor == 1 && rightsensor == 1)
{  if( sensor4==0 && sensor5==1 )

{ 
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10); 
    /*if(leftsensor == 1 && middlesensor == 1 && rightsensor == 1){
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,);   //right wheel
    digitalWrite(lm1,HIGH);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);*/
    
}
 else if( sensor4==1 && sensor5==0)

{ 
  
    digitalWrite(lm,HIGH);  //left wheel
    digitalWrite(rm,LOW);   //right wheel
    digitalWrite(lm1,HIGH);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(10);
    }

}
/*Hif(i==3)
{  leftsensor=~(leftsensor & 0);
   middlesensor=~(middlesensor & 0);
   rightsensor=~(rightsensor & 0);
   sensor5=~(sensor5 & 0);
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,LOW);   //right wheel
    delay(100);

    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(50);
 /* val0 = digitalRead(A0);    
   int rightsensor=val0;
   Serial.print("rightsensor=");  
   Serial.println(rightsensor);//3=rightsensor
   
   val1 = digitalRead(A1);    
   int middlesensor=val1;
   Serial.print("middlesensor=");  
   Serial.println(middlesensor);
       
   val2 = digitalRead(A2);    
   int leftsensor=val2;
   Serial.print("leftsensor=");   
   Serial.println(leftsensor);//5=leftsensro
    
   val3 = digitalRead(A3);    
   int sensor4=val3; 
   Serial.print("leftmost sensor="); 
   Serial.println(sensor4);
    
   val4 = digitalRead(A4);    
   int sensor5=val4; 
   Serial.print("rightmost sensor="); 
   Serial.println(sensor5);
  
   /*leftsensor=~(leftsensor & 0);
   middlesensor=~(middlesensor & 0);
   rightsensor=~(rightsensor & 0);
   sensor5=~(sensor5 & 0);
    digitalWrite(lm,LOW);  //left wheel
    digitalWrite(rm,HIGH);   //right wheel
    digitalWrite(lm1,LOW);  //left wheel
    digitalWrite(rm1,HIGH);   //right wheel
    delay(10);*/


  
}
   


