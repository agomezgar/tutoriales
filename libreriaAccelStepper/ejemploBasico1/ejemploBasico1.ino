#include<AccelStepper.h>
AccelStepper motorDerecha(4,2,4,3,5);
AccelStepper motorIzquierda(4,6,8,7,9);

void setup(){
motorDerecha.setSpeed(100);
motorDerecha.setMaxSpeed(100);
motorDerecha.setAcceleration(100);
motorIzquierda.setSpeed(100);
motorIzquierda.setMaxSpeed(100);
motorIzquierda.setAcceleration(100);
motorDerecha.moveTo(2048);
motorIzquierda.moveTo(-2048);

}
void loop(){
motorDerecha.run();
motorIzquierda.run();

}
