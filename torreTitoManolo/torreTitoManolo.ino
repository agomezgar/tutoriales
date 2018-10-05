#include <Servo.h>
int ax,ay;
int px,py;
Servo mh,mv;

void setup() {
  // put your setup code here, to run once:
mh.attach(11);
mv.attach(12);
px=90;
py=90;
mh.write(px);
mv.write(py);
}

void loop() {
  // put your main code here, to run repeatedly:
ax=analogRead(A0);
ay=analogRead(A1);
if (ax<512){
  px=px-5;
}else{
  px=px+5;
}
if (ay<512){
  py=py-5;
}else{
  py=py+5;
}
}
