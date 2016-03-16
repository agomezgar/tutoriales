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
int columnas[]={127,191,223,239,247,251,253,254,253,251,247,239,223,191,127};
int fRojas[8]={0,0,0,0,0,0,0,0};  

void setup() {
Serial.begin(19200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i=0;i<8;i++){
    pinMode(columnas[i],OUTPUT);
    digitalWrite(columnas[i],HIGH);
}
}
void loop() {
  /*
  if(Serial.available()>0){
    int incomingValue = Serial.read();
    
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue > 1){
      currentValue = 0;
    }
    
    // after this point values[]
    // has the most recent set of
    // all values sent in from Processing
  } 
*/

//for (int i=0;i<8;i++){


if (Serial.available()>0){
  for (int i=0;i<8;i++){
    fRojas[i]=Serial.parseInt();
  }
if (Serial.read()=='\n'){
  for (int i=0;i<8;i++){
    digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
shiftOut(dataPin, clockPin, MSBFIRST,columnas[i]);  

shiftOut(dataPin, clockPin, MSBFIRST, fRojas[i]);  


//Cierro el registro para que encienda los LED
    digitalWrite(latchPin, HIGH);
  }
}
}   
}

  
 

