#include   <Stepper.h>
 //LA SECUENCIA DEBE SER AZUL,AMARILLO,ROSA, NARANJA
 //UNA VUELTA ENTERA CORRESPONDE A 2048 PASOS EN EL 
 //BJY-48
Stepper mDerecha(2048,2,4,3,5);
Stepper mIzquierda(2048,6,8,7,9);
 int trig=11;
int echo=12;
int tiempo=0;
float distancia=0;
boolean derechaTomada=false;
void setup() {
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  mDerecha.setSpeed(5);
  mIzquierda.setSpeed(5);
}
 
void loop() {
mide();
//unos 91,8 pasos por cm para el escornabot de rueda 7,1 cm
if (distancia>10){
 adelante(920); 
 derechaTomada=false;
}else if (derechaTomada){
 izquierda(1900);
derechaTomada=false; 
}else {
 derecha(850);
 derechaTomada=true;
}
delay(100);
}
//La rutina mide da el valor de la distancia medida en cm
//Y la envia al puerto serie para funciones de monitorizacion
void mide(){
  digitalWrite(trig,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH); /* medimos el tiempo que tarda en volver el pulso*/
  distancia= 0.017*tiempo; /*Tengase en cuenta que el pulso va y vuelve, es decir, la distancia es la mitad que la medida*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(100);
}
void adelante(int pasos){
    for (int x=0;x<pasos;x++){
 mDerecha.step(1);
 mIzquierda.step(-1);
  }
}
void atras(int pasos){
    for (int x=0;x<pasos;x++){
 mDerecha.step(-1);
 mIzquierda.step(1);
  }
}
void izquierda(int pasos){
      for (int x=0;x<pasos;x++){
 mDerecha.step(1);
 mIzquierda.step(1);
  }
}
void derecha(int pasos){
      for (int x=0;x<pasos;x++){
 mDerecha.step(-1);
 mIzquierda.step(-1);
  }
}
