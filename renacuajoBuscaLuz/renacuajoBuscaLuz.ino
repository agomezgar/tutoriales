#include<Servo.h>
Servo izquierda, derecha;
int sDerecha,sIzquierda;
int vDerecha,vIzquierda;
void setup(){
Serial.begin(9600);  
izquierda.attach(9);
derecha.attach(10);
}
void loop(){
  sDerecha=analogRead(A1);
  sIzquierda=analogRead(A0);
  vDerecha=map(sDerecha,0,1023,0,90);
  vIzquierda=map(sIzquierda,0,1023,0,90);
  Serial.print(sDerecha);
  Serial.print("\t");
  Serial.println(sIzquierda);
  izquierda.write(0+vIzquierda);
  derecha.write(180-vDerecha);
}
