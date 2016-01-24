//BIBLIOTECAS EN https://github.com/bq/Zowi carpeta Zowi_3Dprintable/code/zum/libraries
#include <Servo.h>
#include <Oscillator.h>
#include <Zowi.h>

//Declaramos Zowi
Zowi z;


void setup()
{
//Inicializamos zowi
    z.init(2,3,4,5);
    
  //Ajustamos posiciones de servos
    z.setTrims(0,0,0,0);
}

void loop()
{
  z.home();
 z.updown(2,1000,BIG);
 z.walk(4,500,FORWARD);
 z.home();
 delay(2000);
 z.moonwalker(3,2000,45,LEFT);
 z.walk(2,2000,BACKWARD);
 z.home();
  }





