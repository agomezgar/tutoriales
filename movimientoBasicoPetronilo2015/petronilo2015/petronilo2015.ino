#include<Servo.h>
#include "pitches.h"
int melody[] = {
                NA4,NA4,NC5,0,NA4,0,NE5,NE5,NE5,0,ND5,0,
                ND5,ND5,NE5,0,0,NE5,NE5,NE5,NE5,0,0,
                NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,
                NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,0,0,
                NA4,NA4,NC5,NC5,NA4,0,0
                };


int noteDurations[] = {
                       8,8,4,8,8,4,8,8,4,8,8,4, // 12
                       8,8,4,8,4,8,8,8,4,8,4, // 11
                       8,8,8,8,8,8,8,8,8,8,8,4,4,4,4,16,16, // 17
                       16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,1,4, // 17
                       8,8,8,8,4,1,4 // 7
                       };
Servo izquierda,derecha;
int distancia=0;
int tiempo=0;
int echo=11;
int trig=12;
boolean giradoIzq=false;
void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echo, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  izquierda.attach(9);
  derecha.attach(10);
  adelante();
 
}

void loop(){

calculaDistancia();
obstDetect(distancia);
delay(100);
}

void calculaDistancia(){
    digitalWrite(trig,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
Serial.println(distancia);
  delay(10);
  
}
void obstDetect(int dist){
  if (dist<20){
    Serial.println("Obstaculo detectado...");
    alto();
    delay(2000);
    toca();
    delay(2000);
decideMovimiento();
    
  }else{
   adelante(); 
  }
  
}
void adelante(){
  izquierda.write(0);
derecha.write(180);
  
}
void atras(){
  izquierda.write(180);
derecha.write(0);
  
}
void giraIzquierda(){
  izquierda.write(90);
derecha.write(180);
  
}
void giraDerecha(){
  izquierda.write(0);
derecha.write(90);
  
}
void alto(){
 izquierda.write(90);
derecha.write(90); 
  
}
void decideMovimiento(){
 int movimiento=(int)random (2);
 Serial.print("Numero de movimiento...");
 Serial.println(movimiento);
switch (movimiento){
 case 0:
 giraIzquierda();
 delay(1000);
 adelante();
 break;
 
 case 1:
 giraDerecha();
 delay(1000);
 adelante();
 break;
 
} 
  
}
void toca(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(7, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
