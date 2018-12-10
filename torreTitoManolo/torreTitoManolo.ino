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
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ax=analogRead(A0);
ay=analogRead(A1);
if (ax<200){
  px=px-5;
  if (px<0){
    px=0;
  }
}
if (ax>650){
  px=px+5;
  if (px>180){
    px=180;
  }
}
if (ay>700){
  py=py-5;
  if (py<0){
    py=0;
  }
}
if (ay<100){
  py=py+5;
  if (py>180){
    py=180;
  }
}
Serial.print(ax);
Serial.print("\t");
Serial.print(ay);
Serial.print("\t");
Serial.print(px);
Serial.print("\t");
Serial.println(py);
mh.write(px);
mv.write(py);
}
