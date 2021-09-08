const int ProxSensor=3;
int inputVal = 0;

void setup() 
{                
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:  
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensorz
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(13, LOW);
    
    // set the LED on
  }
  else
  {
  digitalWrite(13, HIGH);
   delay(2000); 
    
  // set the LED off
  }
inputVal = digitalRead(ProxSensor);
Serial.println(inputVal);

            // wait for a second
}
