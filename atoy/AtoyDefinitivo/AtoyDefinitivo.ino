
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
char dato;
void setup()
{
  
motor1.attach(11); 
motor2.attach(12); 
motor3.attach(13); 
motor4.attach(10);
motor1.write(0);
motor2.write(0);
motor3.write(0);
motor4.write(0);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
sensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor3.set_CS_AutocaL_Millis(0xFFFFFFFF);
sensor4.set_CS_AutocaL_Millis(0xFFFFFFFF);
Serial.begin(9600);

}

void loop()
{
if (Serial.available()>0){
 dato=Serial.read(); 
}

long total1 = sensor1.capacitiveSensor(30);
long total2 = sensor2.capacitiveSensor(30);
long total3 = sensor3.capacitiveSensor(30);
long total4 = sensor4.capacitiveSensor(30);
Serial.print(dato);
Serial.print("\t");
Serial.print(total1);
Serial.print("\t");
Serial.print(total2);
Serial.print("\t");
Serial.print(total3);
Serial.print("\t");
Serial.println(total4);
if (dato==1){
  if (total1>400){
    motor1.write(90);
    delay(300);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
motor1.write(0);
  }
 

if (dato==2){
  if (total2>400){
    motor2.write(90);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
  delay(300);
  motor2.write(0);
  }
  
}
  
if (dato==3){
  if (total3>400){
    motor3.write(90);
//si el dato es 1 y se tocal el primer sensor, abrimos esa caja
  delay(400);
  motor3.write(0);
  }
}
  
if (dato==4){
  if (total4>400){
    motor4.write(90);
  delay(300);
  motor4.write(0);
  }

 

}
}

}


