#define CUBESIZE 4
#define PLANESIZE CUBESIZE*CUBESIZE
#define PLANETIME 3333 // time each plane is displayed in us -> 100 Hz refresh
#define TIMECONST 20 // multiplies DisplayTime to get ms - why not =100?
int LEDPin[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int PlanePin[] = {16,17,18,19};
void setup(){
  int pin; 
for (pin=0; pin<20; pin++) {
pinMode( pin, OUTPUT );

}


}

void loop(){
  int pin; 

digitalWrite(16,LOW);
digitalWrite(17,LOW);
digitalWrite(18,LOW);
digitalWrite(19,LOW);
for (pin=0; pin<16; pin++) {
  digitalWrite(pin,HIGH);
}

}
