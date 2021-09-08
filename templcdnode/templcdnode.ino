#include<LiquidCrystal.h>  //Header file for LCD Module
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //lcd connected pins
const int sensor = A0;    //Assigning analog A0 to variable sensor
float tempC;              //variable to store temp in °C
float tempF;              //variable to store temp in °F
float vout;               //variable to store values from sensor
void setup()
{
  pinMode(sensor,INPUT); // Configuring A0 as input
  lcd.begin(16,2);
  pinMode(A0,INPUT);     
  pinMode(6,OUTPUT);     //For buzzer
  pinMode(9,OUTPUT);     //For LED
  Serial.begin(9600);
}
void loop() 
{
  vout=analogRead(sensor);  
  vout=(vout*500)/1023;
  tempC=vout;             // Storing value in °C
  tempF=(vout*1.8)+32;    //conversion of °C to °F 
  lcd.setCursor(0,0);
  Serial.println(tempC);
  if(tempC>=32) //For easiness I have taken 32°C as alert temperature
  {
    lcd.print("HIGH TEMP!!     ");
    lcd.setCursor(0,1);
    lcd.print("C=");
    lcd.print(tempC);
    lcd.print(" F=");
    lcd.print(tempF);
    beep(200); //beeps for 200ms
  }
  else
  {
    lcd.print("Temp is Normal.");
    lcd.setCursor(0,1);
    lcd.print("C=");
    lcd.print(tempC);
    lcd.print(" F=");
    lcd.print(tempF);
    digitalWrite(9,0);
  }
  delay(1000);
}
void beep(unsigned char delayms){
  analogWrite(6, 20);      // Any value can be used except 0 & 255
  digitalWrite(9,1);
  delay(delayms);          // wait for a delayms ms
  analogWrite(6, 0);       // 0 turns it off
  digitalWrite(9,0);
  delay(delayms);          // wait for a delayms ms   
}
