int val0 = 0;
int val1 = 0;
int val2 = 0;                  
void setup()
{
Serial.begin(9600);          
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}

void loop()
{ digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
   val0 = digitalRead(3);    
  
   Serial.println(val0);    //3=rightsensor
   val1 = digitalRead(4);    
   
   Serial.println(val1);    
   val2 = digitalRead(5);    
   
   Serial.println(val2); //5=leftsensro 

 
    if (val0 == 1 && val1 == 1 && val2 == 1)  // 
   {
    digitalWrite(1,LOW);  //left wheel
    digitalWrite(6,LOW);   //right wheel
    digitalWrite(2,LOW);  //left wheel
    digitalWrite(7,LOW);   //right wheel
    delay(10);
    }
  }
