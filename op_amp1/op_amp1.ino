int analogPin0 = A5;     // Infrared Sensor (Right lead) connected to analog pin 3
int DigitalPin1 = 8;
int digitalPin2 = 13;
// outside leads to ground and +5V
int val0 = 0;                  // variable to store the value read
int val2 = 0;
void setup()
{
  Serial.begin(9600);          //  setup serial
pinMode(13,INPUT);
pinMode(8,OUTPUT);
}

void loop()
{digitalWrite(8,HIGH);
  val0 = analogRead(analogPin0);    // read the input pin
  Serial.println(val0);                           // debug value
   val2 = digitalRead(digitalPin2);
   Serial.println(val2);
}
