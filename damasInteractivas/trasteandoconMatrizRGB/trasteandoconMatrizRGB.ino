//A la patilla 12 del registro
int latchPin = 8;
//A la patilla 11 del registro
int clockPin = 12;
//A la patilla 14 del registro
int dataPin = 11;
int tiempo=millis();
byte datos[1];
int cuenta=0;
int currentValue = 0;
int values[] = {0,0};
int columnas[]={254,253,251,247,239,223,191,127};
int fRojas[]={128,128,128,128,128,128,128,128}; 
int fVerdes[]={0,0,0,0,0,0,0,0};

int fAzules[]={0,0,0,0,0,0,0,0};
 
 int columna=0;
int fila=0;
void setup() {
Serial.begin(19200);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);


}
void loop() {


if ((millis()-tiempo)>50){
  tiempo=millis();
  fRojas[columna]=fRojas[columna]/2;
  if (fRojas[columna]==1){
    columna++;
  }
  fila=fila++;
  if (fila>7){
    columna++;
    fila=0;
    if (columna>7){
      columna=0;
    }
  }
}
if ((millis()-tiempo)>50){
  tiempo=millis();
  fVerdes[columna]=fVerdes[columna]/2;
  if (fVerdes[columna]==1){
    columna++;
  }
  fila=fila++;
  if (fila>7){
    columna++;
    fila=0;
    if (columna>7){
      columna=0;
    }
  }
}
if ((millis()-tiempo)>50){
  tiempo=millis();
  fAzules[columna]=fAzules[columna]/2;
  if (fAzules[columna]==1){
    columna++;
  }
  fila=fila++;
  if (fila>7){
    columna++;
    fila=0;
    if (columna>7){
      columna=0;
    }
  }
}

for (int i=0;i<8;i++){
    digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
shiftOut(dataPin, clockPin, MSBFIRST,columnas[i]);  
shiftOut(dataPin, clockPin, MSBFIRST, 0); 
//Cierro el registro para que encienda los LED
shiftOut(dataPin, clockPin, MSBFIRST,0); 

shiftOut(dataPin, clockPin, MSBFIRST, fRojas[i]); 

    digitalWrite(latchPin, HIGH);
}
}



  
 

