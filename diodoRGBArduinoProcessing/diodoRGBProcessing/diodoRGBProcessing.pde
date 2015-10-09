import processing.serial.*;


Serial miPuerto;
int[] valorSerie=new int[3];
int seriesContados=0;
boolean firstContact=false;
int rojo,verde,azul;
void setup(){
    println(Serial.list());
  // Abre el puerto que se este usando a la velocidad deseada
  //Tener en cuenta que hay que elegir el numero correspondiente
  //al puerto COM que estemos usando en Arduino, y ponerlo
  //en Serial.list[x]
  miPuerto = new Serial(this, Serial.list()[1], 9600);
rojo=0;
azul=0;
verde=0;

  size (800,600);

}
void draw(){
 background(rojo,verde,azul); 
  
}
void serialEvent(Serial myPort) {
  try{
 // read a byte from the serial port:
 int inByte = myPort.read();
 // if this is the first byte received, and it's an A,
 // clear the serial buffer and note that you've
 // had first contact from the microcontroller.
 // Otherwise, add the incoming byte to the array:
 if (firstContact == false) {
 if (inByte == 'A') {
  myPort.clear();   // clear the serial port buffer
  firstContact = true;  // you've had first contact from the microcontroller
  myPort.write('A');  // ask for more
 }
 }
 else {
 // Add the latest byte from the serial port to array:
 valorSerie[seriesContados] = inByte;
 seriesContados++;
 // If we have 3 bytes:
 if (seriesContados > 2 ) {
rojo= valorSerie[0];
verde = valorSerie[1];
azul = valorSerie[2];
 
  // print the values (for debugging purposes only):
  println(rojo + "\t" + verde+ "\t" + azul);
  // Send a capital A to request new sensor readings:
  myPort.write('A');
  // Reset serialCount:
  seriesContados = 0;
 }
 }
  }
   catch(RuntimeException e) {
    e.printStackTrace();
  }
}
