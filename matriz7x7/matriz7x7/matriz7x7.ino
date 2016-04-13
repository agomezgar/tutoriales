//A la patilla 12 del registro
int latchPin = 8;
//A la patilla 11 del registro
int clockPin = 12;
//A la patilla 14 del registro
int dataPin = 11;

byte datos[1];
int cuenta=0;
int currentValue = 0;
int values[] = {0,0};
int columnas[]={254,253,251,247,239,223,191,127};
int filas[]={65,34,20,8,20,34,64,0};  
int x[]={65,34,20,8,20,34,64,0}; 

void setup() {

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);


}
void loop() {
 



for (int i=0;i<8;i++){
    digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
shiftOut(dataPin, clockPin, MSBFIRST,filas[i]); 
 shiftOut(dataPin, clockPin, MSBFIRST,columnas[i]); 
; 
//Cierro el registro para que encienda los LED
    digitalWrite(latchPin, HIGH);
}
}







  
 

