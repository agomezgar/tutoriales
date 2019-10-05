/*Brazo Robot controlado por Bluetooth
 * Este programa facilita la comunicación de Arduino por Bluetooth 
 * con un dispositivo Android para el control de un brazo robot
 * (base giratoria, dos brazos articulados y una pinza) mediante
 * dispositivos táctiles.
 * Creado por Antonio Gómez García
 * IES Eduardo Valencia
 * Calzada de Calatrava, Ciudad Real
 * Spain
 * 28 Aug 2016
 */
#include<Servo.h>
Servo mH,mV;

int datos[2];

void setup() {
  // You should know and modify, in case, the value
  //in Serial.begin according to the Bluetooth module
  // you are using. I.E., Zum Card from BQ Electronics
  //uses 19200, whereas JY-MCU module is usually 9600
Serial.begin(9600);
mH.attach(11);
mV.attach(12);
mH.write(90);
mV.write(90);


}

void loop() {
  // put your main code here, to run repeatedly:
   while (Serial.available() > 0) {

    // do it again:
    int valorX = Serial.parseInt();
    // do it again:
    int valorY = Serial.parseInt();

    // look for the newline. That's the end of the
    // sentence:
    if (Serial.read() == '\n') {

     mH.write(180-valorX);
     mV.write(90-valorY);
    }

      // print the two numbers in one string as decimal:
 
  
   
    }

}
