#include "Keyboard.h"
int sIzquierda,sDerecha;
int lIzquierda=8;
int lDerecha=9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Keyboard.begin();
pinMode(lIzquierda,OUTPUT);
pinMode(lDerecha,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sIzquierda=analogRead(A0);
sDerecha=analogRead(A1);
//Next 3 lines are only to debugging purposes
//Serial.print(sIzquierda);
//Serial.print("\t");
//Serial.println(sDerecha);
if (sIzquierda>800){
  digitalWrite(lIzquierda,HIGH);
  Keyboard.write(216);
  delay(1000);
}else{
  digitalWrite(lIzquierda,LOW);
}
if (sDerecha>800){
  digitalWrite(lDerecha,HIGH);
  Keyboard.write(215);
  delay(1000);
}else{
  digitalWrite(lDerecha,LOW);
}

delay(100);
}
