#include<Servo.h>

int pot1,pot2;
int val1,val2;
void setup(){
Serial.begin(9600);
}
void loop(){
 pot1=analogRead(A0); 
 val1=map(pot1,0,1023,0,255);
Serial.write(val1);
Serial.write(",");
  pot2=analogRead(A1); 
 val2=map(pot2,0,1023,0,255);
 Serial.write(val2);
 Serial.write("\n");

}
