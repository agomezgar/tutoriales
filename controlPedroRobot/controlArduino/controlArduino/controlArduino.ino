#include<Servo.h>
Servo m1,m2,m3,m4;
int v[2];
void setup() {
Serial.begin(9600);
m1.attach(4);
m2.attach(5);
m3.attach(6);
m4.attach(7);
m1.write(90);
m2.write(90);
m3.write(90);
m4.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  for (int i=0;i<3;i++){
v[i]=Serial.read();

}
}
m1.write(v[0]);
m2.write(v[1]);
m3.write(v[2]);
delay(100);
}
