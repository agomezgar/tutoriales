/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
Servo manos[12];
int estados[12];

//m para meñique, a para anular, M para medio, i 
//para índice y p para pulgar
Servo mi,ai,Mi,ii,pi;  // mano izquierda
Servo md,ad,Md,id,pd; //mano derecha
Servo ov,oh; //ojos vertical y horizontal

//Matriz de dedos empezando por
//ojos horizontal, vertical y manos de derecha a izquierda
//y de meñique a pulgar

void setup() {

  Serial.begin(19200);
  for (int i=0;i<12;i++){
manos[i].attach(i+2);
estados[i]=0;
abre(manos[i]);
  }
 horizontal('c');
 vertical('c');

  }


void loop() {
if (Serial.available()>0){
char lectura=Serial.read();
int valor=traduce(lectura);
valor=valor+2;
comprueba(valor);
}
}
int traduce(char valor){
  int resultado;
  switch(valor){
    case 'a':
    resultado=0;
    break;
        case 'b':
    resultado=1;
    break;
        case 'c':
    resultado=2;
    break;
        case 'd':
    resultado=3;
    break;
        case 'e':
    resultado=4;
    break;
        case 'f':
    resultado=5;
    break;
        case 'g':
    resultado=6;
    break;
        case 'h':
    resultado=7;
    break;
        case 'i':
    resultado=8;
    break;
        case 'j':
    resultado=9;
    break;
  }
  return resultado;
}
void comprueba(int valor){
  if (estados[valor]==0){
    cierra(manos[valor]);
    estados[valor]=1;
}else{
  abre(manos[valor]);
  estados[valor]=0;
}
}
void abre(Servo motor){
motor.write(0);

}
void cierra (Servo motor){
  motor.write(180);

}
void horizontal(char valor){
  //c centrado, i izquierda, d derecha
  if (valor=='c'){
    manos[0].write(90);
  }
  if (valor=='i'){
    manos[0].write(0);
  }
  if (valor=='d'){
    manos[0].write(180);
  }
}
void vertical(char valor){
  //c centrado, a alto, b bajo
  if (valor=='c'){
    manos[1].write(90);
  }
  if (valor=='a'){
     manos[1].write(15);
  }
  if (valor=='b'){
     manos[1].write(165);
  }
}
