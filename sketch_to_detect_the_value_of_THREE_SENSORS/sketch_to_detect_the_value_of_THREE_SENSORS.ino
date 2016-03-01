
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

}

void loop()
{ digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  val0 = digitalRead(3);    
 
  int sensor1=val0; 
  Serial.println(sensor1);    

  val1 = digitalRead(4);    
  
   int sensor2=val1;
  Serial.println(sensor2);    

   val2 = digitalRead(5);    
   
    int sensor3=val2;  

   Serial.println(sensor3);  
}
