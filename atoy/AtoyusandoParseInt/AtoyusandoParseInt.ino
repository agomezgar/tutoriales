
#include <Servo.h>

Servo motor1;
#include <Servo.h>

Servo motor2;
#include <Servo.h>

Servo motor3;
#include <Servo.h>

Servo motor4;
#include <CapacitiveSensor.h>
boolean encendido=false;
CapacitiveSensor sensor1= CapacitiveSensor(7,9);
CapacitiveSensor sensor2= CapacitiveSensor(2,8);
CapacitiveSensor sensor3= CapacitiveSensor(4,6);
CapacitiveSensor sensor4= CapacitiveSensor(3,5);
int dato;
boolean leyendo;
void setup()
{
  leyendo=true;
motor1.attach(11); 
motor2.attach(12); 
motor3.attach(13); 
motor4.attach(10);
    
motor1.write(0);
motor2.write(0);
motor3.write(0);
motor4.write(45);

sensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor3.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor4.set_CS_AutocaL_Millis(0xFFFFFFFF);
Serial.begin(19200);
dato=5;
}

void loop()
{
while (Serial.available()>0){
 dato=Serial.parseInt(); 
 leyendo=true;
if (Serial.read()=='\n'){
while(leyendo){
long total1 = sensor1.capacitiveSensor(30);
long total2 = sensor2.capacitiveSensor(30);
long total3 = sensor3.capacitiveSensor(30);
long total4 = sensor4.capacitiveSensor(30);

if (dato==1){
  if (total1>500){
    leyendo=false;
  
    motor1.write(90);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
delay(2000);
motor1.write(0);
  }
  }
 

if (dato==2){
  if (total2>500){
    leyendo=false;
    motor2.write(90);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
  delay(2000);
motor2.write(0);
  }
  
}
  
if (dato==3){
  if (total3>500){
    leyendo=false;
    motor3.write(90);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
  delay(2000);
motor3.write(0);
  }
}
  
if (dato==4){
  if (total4>500){
    leyendo=false;
    motor4.write(120);
    delay(2000);
motor4.write(45);
  }

 
}
}
}
}
}


