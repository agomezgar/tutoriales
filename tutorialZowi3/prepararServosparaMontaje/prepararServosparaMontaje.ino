//Para poner los cuatro servomotores a 90º
#include <Servo.h>
//Declaramos los servos
Servo servo1, servo2, servo3, servo4;
void setup() {
//Asociamos los servos a sus patillas
servo1.attach(2);  
servo2.attach(3);  
servo3.attach(4);  
servo4.attach(5);  
//Escribimos 90º en los servos
servo1.write(90);
servo1.write(90);
servo1.write(90);
servo1.write(90);

}

void loop() {
//Nothing to see around here
}
