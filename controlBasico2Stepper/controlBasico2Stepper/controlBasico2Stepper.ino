#include   <Stepper.h>
 //LA SECUENCIA DEBE SER AZUL,AMARILLO,ROSA, NARANJA
 //UNA VUELTA ENTERA CORRESPONDE A 2048 PASOS EN EL 
 //BJY-48
Stepper mDerecha(2048,2,4,3,5);
Stepper mIzquierda(2048,6,8,7,9);
 
void setup() {
 
  mDerecha.setSpeed(5);
  mIzquierda.setSpeed(5);
}
 
void loop() {
  for (int x=0;x<2048;x++){
 mDerecha.step(1);
 mIzquierda.step(-1);
  }
  delay(1000);
  for (int x=0;x<2048;x++){
 mDerecha.step(-1);
 mIzquierda.step(1);
  }

  delay(1000);
}
