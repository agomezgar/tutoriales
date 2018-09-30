//A la patilla 12 del registro
int latchPin = 8;
//A la patilla 11 del registro
int clockPin = 12;
//A la patilla 14 del registro
int dataPin = 11;
void setup() {
 pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
//Abro el registro enviar los datos a cada registro

//COLUMNAS A 0 PARA QUE SE ENCIENDAN TODOS LOS LED EN UNA FILA
shiftOut(dataPin, clockPin, MSBFIRST,B00000000);  
//ENCIENDO AZULES EN LAS DOS ÚLTIMAS FILAS
shiftOut(dataPin, clockPin, MSBFIRST,B11000000); 

//ENCIENDO VERDES EN LAS DOS FILAS INTERMEDIAS
shiftOut(dataPin, clockPin, MSBFIRST,B00011000); 

//ENCIENDO ROJOS EN LAS DOS PRIMERAS FILAS 
shiftOut(dataPin, clockPin, MSBFIRST, B00000011); 
//Cierro el registro para que encienda los LED

    digitalWrite(latchPin, HIGH);

}

void loop() {

}
