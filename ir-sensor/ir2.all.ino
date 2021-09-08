
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int tempsensor = A0;   
float tempC;
float tempF;             
float vout; 
int tempbuzzer=9; 

const int IRSensor1=3;
const int IRSensor2=4;
const int IRSensor3=5;
const int IRSensor4=6;
int IRbuzzer=12;


int analogSensor = 0;
int redLed = 2;
int smokebuzzer = 10;
int smokesensor = A1;
int sensorThres = 250;


void setup() 
{                
   lcd.begin();
  lcd.backlight();
  lcd.clear();
  pinMode(tempsensor,INPUT); 
pinMode(tempbuzzer,OUTPUT);


 
 pinMode(redLed, OUTPUT);
  pinMode(smokebuzzer, OUTPUT);
  pinMode(smokesensor, INPUT); 
 
  
  pinMode(IRSensor1,INPUT);
  pinMode(IRSensor2,INPUT);  
  pinMode(IRSensor3,INPUT);
  pinMode(IRSensor4,INPUT); 
   pinMode(IRbuzzer, OUTPUT);  
  Serial.begin(9600);
  
}

void loop() 

{

 vout=analogRead(tempsensor);
 
  analogSensor = analogRead(smokesensor);
  vout=(vout*500)/1023;
  tempC=vout;            
  tempF=(vout*1.8)+32;    
    lcd.setCursor(0,0);
 
  


  if(tempC>=50)
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
  {
  delay(500);
  }
  if(!digitalRead(IRSensor1) || !digitalRead(IRSensor2)|| !digitalRead(IRSensor3) || !digitalRead(IRSensor4)  )    //Check the sensor output
  {
    digitalWrite(IRbuzzer, HIGH);
    
    
    
  }
  else
  {
  digitalWrite(IRbuzzer, LOW);
  
  //end IR
    

  }
  
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  
   if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
   
    tone(smokebuzzer, 500, 300);
    
  }
  else
  {
    digitalWrite(redLed, LOW);
  
    noTone(smokebuzzer);
    //endsmoke
  }

}
