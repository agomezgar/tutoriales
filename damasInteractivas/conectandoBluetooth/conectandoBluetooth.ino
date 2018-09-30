
int  columnas[]={2,3,4,5,6,7,9,10};
int lectura=0;
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i=0;i<8;i++){
    pinMode(columnas[i],OUTPUT);
  
  digitalWrite (columnas[i],LOW);
  }
}

void loop() {
  if (Serial.available()>0){
    lectura=Serial.read();
  
  // put your main code here, to run repeatedly:
     digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, lectura);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
  }
    delay(500);

}
