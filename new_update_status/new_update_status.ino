#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
 
//Pin assignments
#define switch_1 2 // D4 Pin of NodeMcu
#define switch_2 12 // D6 Pin of NodeMcu
 
#define relay_1 0 //D3 Pin of NodeMcu
#define relay_2 15 //D6 Pin of NodeMcu
 
#define LED1 13 //D7 Pin of NodeMcu
#define LED2 15 //D8 Pin of NodeMcu
 
int MODE = 0;
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Rapid Fiber 4";
char pass[] = "123123123";
 

char auth[] = "nTBMPJoW_gOwfe0RBXJm4P2VrkI5v3MM";
 
int switch_1_ON = 0;
int switch_2_ON = 0;
 
BLYNK_WRITE(V1)
{
int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
digitalWrite(relay_1, pinValue); // process received value
}
 
BLYNK_WRITE(V2)
{
int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
digitalWrite(relay_2, pinValue); // process received value
}
 
void internet() //When this device connects with internet
{
//**************************************
//Switch 1 configuration
//**************************************
if (digitalRead(switch_1) == LOW)
{
if (switch_1_ON == 0 )
{
digitalWrite(relay_1, LOW);
Blynk.virtualWrite(V1, 0);
switch_1_ON = 1;
}
}
 
if (digitalRead(switch_1) == HIGH )
{
if (switch_1_ON == 1)
{
digitalWrite(relay_1, HIGH);
Blynk.virtualWrite(V1, 1);
delay(5000);
switch_1_ON = 0;
}
}
//**************************************
//Switch 2 configuration
//**************************************
if (digitalRead(switch_2) == LOW)
{
if (switch_2_ON == 0 )
{
digitalWrite(relay_2, LOW);
Blynk.virtualWrite(V2, 0);
switch_2_ON = 1;
}
}
 
if (digitalRead(switch_2) == HIGH )
{
if (switch_2_ON == 1)
{
digitalWrite(relay_2, HIGH);
Blynk.virtualWrite(V2, 1);
delay(10000);
switch_2_ON = 0;
}
}
}
//********************************************
 
void no_internet() //When this device doesn't gets internet
{
digitalWrite(relay_1, digitalRead(switch_1));
digitalWrite(relay_2, digitalRead(switch_2));
}
 
void Blynk_status() // called every 3 seconds by SimpleTimer
{
bool isconnected = Blynk.connected();
if (isconnected == false)
{
MODE = 1;
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);
}
if (isconnected == true)
{
MODE = 0;
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
Blynk.syncAll();
}
}
 
void setup()
{
Serial.begin(9600);
pinMode(switch_1, INPUT);
pinMode(relay_1, OUTPUT);
 
pinMode(switch_2, INPUT);
pinMode(relay_2, OUTPUT);
 
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
 
//*****************************************
 
digitalWrite(LED1, HIGH);
delay(200);
digitalWrite(LED1, LOW);
delay(200);
digitalWrite(LED2, HIGH);
delay(200);
digitalWrite(LED2, LOW);
delay(200);
digitalWrite(LED1, HIGH);
delay(200);
digitalWrite(LED1, LOW);
delay(200);
digitalWrite(LED2, HIGH);
delay(200);
digitalWrite(LED2, LOW);
delay(200);
digitalWrite(LED1, HIGH);
delay(200);
digitalWrite(LED1, LOW);
delay(200);
digitalWrite(LED2, HIGH);
delay(200);
digitalWrite(LED2, LOW);
delay(200);
digitalWrite(LED1, HIGH);
delay(200);
digitalWrite(LED2, LOW);
delay(200);
digitalWrite(LED2, HIGH);
delay(200);
digitalWrite(LED1, LOW);
delay(200);
 
WiFi.begin(ssid, pass);
timer.setInterval(3000L, Blynk_status); // check if connected to Blynk server every 3 seconds
Blynk.config(auth);
}
 
void loop()
{
if (WiFi.status() == WL_CONNECTED)
{
Blynk.run();
}
 
timer.run(); // Initiates SimpleTimer
if (MODE == 0)
internet();
else
no_internet();
}
