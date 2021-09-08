
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int tempsensor = A0;   
float tempC;
float tempF;             
float vout; 
int tempbuzzer=9;              
void setup()
{
    lcd.begin();
  lcd.backlight();
  lcd.clear();
  pinMode(tempsensor,INPUT); 




    

  pinMode(tempbuzzer,OUTPUT);     
  Serial.begin(9600);
}
void loop() 
{
  vout=analogRead(tempsensor);  
  vout=(vout*500)/1023;
  tempC=vout;            
  tempF=(vout*1.8)+32;    
  lcd.setCursor(0,0);
  Serial.println(tempC);
  if(tempC>=32)
  {
    lcd.print("HIGH TEMP!!     ");
    lcd.setCursor(0,1);
    lcd.print("C=");
    lcd.print(tempC);
    lcd.print(" F=");
    lcd.print(tempF);
    digitalWrite(9,1);
   
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
