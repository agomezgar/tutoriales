//A la patilla 12 del registro
int latchPin = 8;
//A la patilla 11 del registro
int clockPin = 12;
//A la patilla 14 del registro
int dataPin = 11;
int columnas[]={B11111110,B11111101,B11111011,B11110111,B11101111,B11011111,B10111111,B01111111};
int fRojas[]={B00000001,B00100010,B00000001,B00001000,B00000001,B00000000,B00000001,B00000010};
int fVerdes[]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
int fAzules[]={B01000000,B10000000,B01000000,B10000000,B01000000,B10000000,B01000000,B10000000};
void setup() {
 pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);


}

void loop() {
  for (int i=0;i<8;i++){
digitalWrite(latchPin, LOW);


//COLUMNAS A 0 PARA QUE SE ENCIENDAN TODOS LOS LED EN UNA FILA
shiftOut(dataPin, clockPin, MSBFIRST,columnas[i]);  
//ENCIENDO AZULES EN LAS DOS ÚLTIMAS FILAS
shiftOut(dataPin, clockPin, MSBFIRST,fAzules[i]); 

//ENCIENDO VERDES EN LAS DOS FILAS INTERMEDIAS
shiftOut(dataPin, clockPin, MSBFIRST,fVerdes[i]); 

//ENCIENDO ROJOS EN LAS DOS PRIMERAS FILAS 
shiftOut(dataPin, clockPin, MSBFIRST, fRojas[i]); 
//Cierro el registro para que encienda los LED

    digitalWrite(latchPin, HIGH);
  }
}
