#include <Masaylo.h>
Masaylo robot;
void setup(){
 Serial.begin(9600);
 
}
void loop(){
switch (Serial.read()){
  case 1:
     robot.adelante(1000);
  robot.paro(10);
    Serial.end();
  Serial.begin(9600);
  break;
    case 2:
     robot.atras(1000);
  robot.paro(10);
    Serial.end();
  Serial.begin(9600);
  break;
    case 3:
     robot.izquierda(1000);
  robot.paro(10);
    Serial.end();
  Serial.begin(9600);
  break;
    case 4:
     robot.derecha(1000);
  robot.paro(10);
    Serial.end();
  Serial.begin(9600);
  break;
  
}
  delay(10);
}
