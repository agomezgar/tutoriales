#include <Servo.h>
Servo base, brazo;
int valoresContados=0;
int posiciones[2];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
base.attach(9);
brazo.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  posiciones[valoresContados]=Serial.read();
valoresContados++;
}
if (valoresContados>1){
  Serial.print(valoresContados);
  Serial.print("\t");
    Serial.print(posiciones[0]);
  Serial.print("\t");
    Serial.println(posiciones[1]);

  valoresContados=0;
  base.write(posiciones[0]);
  brazo.write(posiciones[1]);
}

}
