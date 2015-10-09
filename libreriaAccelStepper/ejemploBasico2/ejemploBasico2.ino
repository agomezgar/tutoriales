#include<AccelStepper.h>
AccelStepper motorDerecha(4,2,4,3,5);
AccelStepper motorIzquierda(4,6,8,7,9);
int movimiento=0;

void setup(){

motorDerecha.setSpeed(800);
motorDerecha.setAcceleration(50);
motorDerecha.setMaxSpeed(1000);
motorIzquierda.setSpeed(600);
motorIzquierda.setAcceleration(50);
motorIzquierda.setMaxSpeed(1000);
//2048 pasos equivale a media vuelta
motorDerecha.move(2048);
motorIzquierda.move(-2048);

}

void loop(){

if (motorDerecha.distanceToGo()==0){
  movimiento++;
decideMovimiento();
}
motorDerecha.run();
motorIzquierda.run();

}
void adelante(){

motorDerecha.move(2048);
motorIzquierda.move(-2048);

}
void izquierda(){

motorDerecha.move(1024);
motorIzquierda.move(1024);

}

void decideMovimiento(){
 if (movimiento>2){
    movimiento=1;
  }
  switch (movimiento){
   case 1:

 izquierda();

break;
case 2:

adelante();
break;

  }
}
