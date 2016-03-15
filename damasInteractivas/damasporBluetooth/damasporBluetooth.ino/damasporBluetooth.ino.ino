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
int columnas[]={2,3,4,5,6,7,9,10};
int fRojas[8]={0,255,0,0,0,0,0,0};  

void setup() {
Serial.begin(19200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i=0;i<8;i++){
    pinMode(columnas[i],OUTPUT);
    digitalWrite(columnas[i],LOW);
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

for (int i=0;i<8;i++){
   
digitalWrite(columnas[i],LOW);
    digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
shiftOut(dataPin, clockPin, MSBFIRST, fRojas[i]);  



//Cierro el registro para que encienda los LED
    digitalWrite(latchPin, HIGH);

    digitalWrite(columnas[i],HIGH);
 
        }
    
  /*
 Serial.println(values[0]);
 Serial.println(values[1]);
 */
}

  
 

