#include   <Stepper.h>
 //LA SECUENCIA DEBE SER AZUL,AMARILLO,ROSA, NARANJA
 //UNA VUELTA ENTERA CORRESPONDE A 2048 PASOS EN EL 
 //BJY-48
Stepper mDerecha(2048,2,4,3,5);
 
void setup() {
 
  mDerecha.setSpeed(5);

}
 
void loop() {
 mDerecha.step(2048);
  delay(1000);

  mDerecha.step(-2048);
  delay(1000);
}
