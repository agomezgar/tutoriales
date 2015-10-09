#include<Servo.h>
Servo servo1;

int pot1;
int val1;
void setup(){
 servo1.attach(9);

}
void loop(){
 pot1=analogRead(A0); 
 val1=map(pot1,0,1023,0,180);
 servo1.write(val1);
 
}
