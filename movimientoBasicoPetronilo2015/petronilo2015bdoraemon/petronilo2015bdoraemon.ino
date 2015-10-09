#include<Servo.h>
#include "pitches.h"
int melody[] = {
   NG3,NC4,NC4,NE4,NA4,NE4,NG4,0,
   NG4,NA4,NG4,NE4,NF4,NE4,ND4,0,
   NA3,ND4,ND4,NF4,NB4,NB4,NA4,NG4,NF4,NF4,NE4,ND4,NA3,0,NA3,NB3,NC4,ND4,0,0,
   NG3,NC4,NC4,NE4,NA4,NE4,NG4,0,
   NG4,NA4,NG4,NE4,NF4,NE4,ND4,0,
   NA3,ND4,ND4,NF4,NB4,NB4,NA4,NG4,NF4,NF4,NE4,ND4,NA3,0,NA3,NB3,ND4,NC4,0,0,
   NA4,0,NA4,NG4,NF4,NG4,NA4,NG4,0,ND4,NE4,NFS4,ND4,NG4,0,
   NA4,0,NG4,0,NF4,0,ND4,0,
   NB4,NA4,NG4,NA4,NG4,NF4,0,0,
   NG4,NA4,NE4,0,ND4,NC4,0,0,
   NA4,0,NA4,NG4,NF4,NG4,NA4,NG4,0,ND4,NE4,NFS4,ND4,NG4,0,
   NA4,0,NG4,0,NF4,0,ND4,0,
   NB4,NA4,NG4,NA4,NG4,NF4,0,0,
   NG4,NA4,NE4,0,ND4,NC4
   };

int noteDurations[] = {
               2,4,2,4,2,4,2,4,
               2,4,2,4,2,4,2,4,
               2,4,2,4,2,4,2,4,2,4,2,4,2,4,4,4,4,2,1,1,
               2,4,2,4,2,4,2,4,
               2,4,2,4,2,4,2,4,
               2,4,2,4,2,4,2,4,2,4,2,4,2,4,4,4,4,2,1,1,
               2,4,2,4,4,4,4,2,4,2,4,2,4,1,2,
               2,4,2,4,2,1,2,4,
               2,4,2,4,2,4,2,4,
               2,4,1,4,4,1,1,1,
               2,4,2,4,4,4,4,2,4,2,4,2,4,1,2,
               2,4,2,4,2,1,2,4,
               2,4,2,4,2,4,2,4,
               2,4,1,4,4,1
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
atras();
delay(3000);
giraDerecha();
    delay(2000);
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
 izquierda.write(92);
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
