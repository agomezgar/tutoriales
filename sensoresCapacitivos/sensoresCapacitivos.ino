#include <CapacitiveSensor.h>
int pinPWM=10;
CapacitiveSensor   sensor = CapacitiveSensor(4,2);     
void setup()                    
{
   Serial.begin(9600);
}

void loop()                    
{
    long total1 =  sensor.capacitiveSensor(30);
    Serial.println(total1);                  
    int valorLed=map(total1,0,2000,0,255);
    analogWrite(pinPWM,valorLed);
    delay(10);                             
}
