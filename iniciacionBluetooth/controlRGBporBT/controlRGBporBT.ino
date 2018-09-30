#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
//Patilla 6 a TX del Bluetooth y viceversa
SoftwareSerial BT(6,7); //6 RX, 7 TX.
 int rojo=8;
 int verde=9;
 int azul=10;
 boolean rEncendido=false;
 boolean vEncendido=false;
 boolean aEncendido=false;

void setup() {
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
Serial.begin(9600);
pinMode(rojo,OUTPUT);
pinMode(verde,OUTPUT);
pinMode(azul,OUTPUT);
digitalWrite(rojo,LOW);
digitalWrite(verde,LOW);
digitalWrite(azul,LOW);


}

void loop() {
  if(BT.available())
  {char lectura=BT.read();
    Serial.write(BT.read());
    
    if (lectura=='r'){
if (rEncendido){
  Serial.write("Rojo encendido. Apagando");
  digitalWrite(rojo,LOW);
  rEncendido=false;
    }else{
digitalWrite(rojo,HIGH);
rEncendido=true;

    }
    }
        if (lectura=='v'){
if (vEncendido){
  digitalWrite(verde,LOW);
  vEncendido=false;
    }else{
digitalWrite(verde,HIGH);
vEncendido=true;
    }
    }
            if (lectura=='a'){
if (aEncendido){
  digitalWrite(azul,LOW);
  aEncendido=false;
    }else{
digitalWrite(azul,HIGH);
aEncendido=true;
    }
    }
    }
  
 
  if(Serial.available())
  {
     BT.write(Serial.read());
  }
}
