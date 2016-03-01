int analogPin0 = A0;     //left sensor (BROWN wire)
int analogPin1 = A1;     //mid sensor (PINK wire)
int analogPin2 = A2;     // right sensor(ORANGE wire)
int val0=0;                  // variable to store the value read
int val1=0;
int val2=0;
int i=1;
int old_val1=0;
int old_val2=0;
int old_val0=0;
int LeftMotorForward = 2; // Pin 2 has Left Motor connected on Arduino boards.
int RightMotorForward = 3; // Pin 3 has Right Motor connected on Arduino boards.

void setup()
{
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(analogPin0, INPUT);
  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
  Serial.begin(9600);          //  setup serial
}

void line_tracer()
{
  if (val1 < 500 && val0 > 500 && val2 > 500)  // GO FORWARD
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,HIGH);   //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 < 500 && val2 < 500) // GO FORWARD
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,HIGH);  //right wheel
    delay(10);
   }
    else if(val1 > 500 && val0 > 500 && val2 > 500) // STOP
   { 
    digitalWrite(LeftMotorForward,LOW);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 > 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   {
    digitalWrite(LeftMotorForward,LOW);  //left wheel
    digitalWrite(RightMotorForward,HIGH);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   { 
    digitalWrite(LeftMotorForward,LOW);  //left wheelb
    digitalWrite(RightMotorForward,HIGH);  //right whe el
    delay(10);
   } 
    else if(val1 > 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
  }
}


void loop()
{
  val0 =analogRead(analogPin0);    // read the input pin
  Serial.println(val0);
  // debug value
  val1 = analogRead(analogPin1);
  Serial.println(val1);
  val2 = analogRead(analogPin2);
  Serial.println(val2);
  Serial.println(i);
  delay(50);
  
 
if(val0<500 && val2<500 && val1<500)
{
   if(old_val0<500 && old_val1<500 && old_val2>500 )                        //001
   i++;
   delay(1);
   if(old_val0>500 && old_val1<500 && old_val2<500)                       //100
   i++;
   delay(1);
   if(old_val0<500 && old_val1>500 && old_val2>500)                    //011    
   i++;
   delay(1);
   if(old_val0>500 && old_val1>500 && old_val2<500)                //110
   i++;
   delay(1);
   if(old_val0<500 && old_val1>500 && old_val2<500)               //010
   i++;
   delay(1);  
   if(old_val0>500 && old_val1<500 && old_val2>500)    
   i++;
   delay(1);
   }
   
  
  
 old_val0=val0;
 old_val1=val1;
 old_val2=val2;

if(i<4)
{
  line_tracer();
}
else if(3<i<5)
{
   if(val1 > 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
  }
  delay(10);
  line_tracer();
  }
else if(4<i<6)
{
 if(val1 > 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
  }
  delay(10);
  line_tracer();
  }
  else if(6<i<8)
  {
  line_tracer();
  }
  else if(7<i<9)
  {
    if(val1 > 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   {
    digitalWrite(LeftMotorForward,LOW);  //left wheel
    digitalWrite(RightMotorForward,HIGH);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   { 
    digitalWrite(LeftMotorForward,LOW);  //left wheelb
    digitalWrite(RightMotorForward,HIGH);  //right whe el
    delay(10);
   } 
   delay(10);
   line_tracer();
  }
  else if(8<i<10)
    {
    if(val1 > 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   {
    digitalWrite(LeftMotorForward,LOW);  //left wheel
    digitalWrite(RightMotorForward,HIGH);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 < 500 && val2 > 500)  // TURN LEFT
   { 
    digitalWrite(LeftMotorForward,LOW);  //left wheelb
    digitalWrite(RightMotorForward,HIGH);  //right whe el
    delay(10);
   } 
   delay(10);
   line_tracer();
  }
 else if(9<i<12)
 {
  line_tracer();
 }
 else if(i=12)
 {
  if(val1 > 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
  }
  delay(10);
  line_tracer();
 }
 else if(12<i<14)
 {
  if(val1 > 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
   }
    else if(val1 < 500 && val0 > 500 && val2 < 500)  // TURN RIGHT
   {
    digitalWrite(LeftMotorForward,HIGH);  //left wheel
    digitalWrite(RightMotorForward,LOW);  //right wheel
    delay(10);
  }
  delay(10);
  line_tracer();
 }
 else if(13<i<16)
 {
  line_tracer();
 } }
  



