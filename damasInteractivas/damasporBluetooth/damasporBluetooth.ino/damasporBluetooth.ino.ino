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
int columnas[]={10,9,7,6,5,4,3,2};
int fRojas,cRojas;  

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
while (Serial.available()>0){
 fRojas=Serial.parseInt();
 cRojas=Serial.parseInt();
if (Serial.read() == '\n')
        {
   

    digitalWrite(latchPin, LOW);
// Escribo los datos con la función shiftOut
shiftOut(dataPin, clockPin, MSBFIRST, fRojas);  



//Cierro el registro para que encienda los LED
    digitalWrite(latchPin, HIGH);
        }
        ponColumnas(cRojas);
  /*
 Serial.println(values[0]);
 Serial.println(values[1]);
 */
}
    delay(500);
  }
  void ponColumnas (int valor){
    
    for (int i=0;i<8;i++){
      if (valor%2==1){
        digitalWrite(columnas[i],LOW);
      }else{
        digitalWrite(columnas[i],HIGH);
      }
      valor=valor/2;
    }
  }

