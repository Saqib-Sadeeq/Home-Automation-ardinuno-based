const int sensor = A0;    //Assigning analog A0 to variable sensor
float tempC;              //variable to store temp in °C
float tempF;              //variable to store temp in °F
float vout;               //variable to store values from sensor
void setup() 
{
  Serial.begin(9600);
  pinMode(sensor,INPUT);  //configuring A0 as input
}
void loop() 
{
  vout = analogRead(sensor);
  vout = (vout*500)/1023; 
          /*Atmega is powered by 5V, and the datasheet of the Atmega states that its ADC has a definition of 1024 values (i.e. 10 bits). So in the above formula, 5/1024 is representing each voltage step represented by a bit and it is multiplied with 100 because for every °C change in temperature there is a voltage change of 10mV and hence by using the rule of three we need to multiply 100 with vout*/
  
  tempC = vout;
  tempF = (vout*9)/5+32;   //conversion of °C to °F
  Serial.print("TEMP in C:");
  Serial.print("\t");
  Serial.print(tempC);     //printing values in °C on serial monitor 
  Serial.print("\t");
  Serial.print("TEMP in F:");
  Serial.print("\t");
  Serial.print(tempF);     //printing values in °F on serial monitor
  Serial.println();
  delay(2000);
}
