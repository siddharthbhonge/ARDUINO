int leftmotor = 7;
int leftmotor1 = 6;
int rightmotor = 1;
int rightmotor1 = 2;

int val0 = 0;
int val1 = 0;
int val2 = 0;                  
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
pinMode(leftmotor,OUTPUT);
pinMode(leftmotor1,OUTPUT);
pinMode(rightmotor,OUTPUT);
pinMode(rightmotor1,OUTPUT);
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
   val0 = digitalRead(A0);    
   int sensor1=val0; 
   Serial.println(sensor1);    //3=rightsensor
   val1 = digitalRead(A1);    
   int sensor2=val1;
   Serial.println(sensor2);    
   val2 = digitalRead(A2);    
   int sensor3=val2;  
   Serial.println(sensor3); //5=leftsensro 

   if (sensor3 == 0 && sensor2 == 0 && sensor1 == 0)  // GO FORWARD
   {
    digitalWrite(leftmotor,LOW);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,LOW);   //right wheel
    delay(10);
   }
   
   if (sensor3 == 0 && sensor2 == 0 && sensor1 == 1)  // RIGHT SENSOR HIGH TURN RIGHT
   {
    digitalWrite(leftmotor,HIGH);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,LOW);   //right wheel
    delay(10);
   }
    
   if (sensor3 == 0 && sensor2 == 1 && sensor1 == 1)  // 
     {
    digitalWrite(leftmotor,HIGH);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,LOW);   //right wheel
    delay(10);
   }
    
   
   if (sensor3 == 1 && sensor2 == 0 && sensor1 == 1)  // 
   {
    digitalWrite(leftmotor,LOW);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,LOW);   //right wheel
    delay(10);
   }
   
    if (sensor3 == 1 && sensor2 == 0 && sensor1 == 0)  // 
      {
    digitalWrite(leftmotor,LOW);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,HIGH);   //right wheel
    delay(10);
   }
   
   
    if (sensor3 == 1 && sensor2 == 1 && sensor1 == 0)  // 
   {
    digitalWrite(leftmotor,LOW);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,LOW);  //left wheel
    digitalWrite(rightmotor1,HIGH);   //right wheel
    delay(10);
   }
   
    if (sensor3 == 1 && sensor2 == 1 && sensor1 == 1)  // 
   {
    digitalWrite(leftmotor,LOW);  //left wheel
    digitalWrite(rightmotor,LOW);   //right wheel
    digitalWrite(leftmotor1,HIGH);  //left wheel
    digitalWrite(rightmotor1,HIGH);   //right wheel
    delay(10);
    }
  }
