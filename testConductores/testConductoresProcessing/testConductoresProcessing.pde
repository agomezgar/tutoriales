/*
 Test Conductores Processing
Para utilizar con Arduino programada con el código
'Test Conductores Arduino'
  This example code is in the public domain.

  modificado el 10 de diciembre de 2016
  by Antonio Gómez García
 */
import processing.serial.*;


Serial miPuerto;
int[] valorSerie=new int[2];
int seriesContados=0;
boolean firstContact=false;
int valor1,valor2;

  int contador=0;
  int contador2=10;
  int ancho=80;
  int [] xPos, xPos2, yPos;
  //0 recto, 1 izquierda, 2 derecha
  int sentido, sentido2;
  int velocidadbase=2;
  int velocidad=velocidadbase;
  int velocidad2=velocidadbase;
  int xCoche1;
  int xCoche2;
void setup(){
    println(Serial.list());
  // Abre el puerto que se este usando a la velocidad deseada
  //Tener en cuenta que hay que elegir el numero correspondiente
  //al puerto COM que estemos usando en Arduino, y ponerlo
  //en Serial.list[x]
  miPuerto = new Serial(this, Serial.list()[0], 9600);

  noStroke();
  size (800,600);
    yPos=new int[height];
  xPos=new int[height];
   xPos2=new int[height];
   xCoche1=(width/4)-25;
   xCoche2=(width*3/4)-25;
inicia();
}
void draw(){
  background(0,255,255);
  leeMandos();
actualizacarretera();
actualizacoche();



}
void inicia(){
    for (int i=0;i<xPos.length;i++){
    xPos[i]=width/4;
    xPos2[i]=width*3/4;
  }
  for (int i=0;i<yPos.length;i++){
    yPos[i]=i;
  
  }
}
void actualizacarretera(){
  contador++;
  contador2++;
  if (contador==20){
    contador=0;
    sentido=(int)random(3);
  }
  
    if (contador2==20){
    contador2=0;
 
   sentido2=(int)random(3);
    }
    //println(sentido);
     if((xPos[xPos.length-1]-ancho)<0){
//  sentido=1;
  xPos[xPos.length-1]=ancho;
}
     if((xPos[xPos.length-1]+ancho)>width/2){
  //sentido=1;
xPos[xPos.length-1]=(width/2)-ancho;
}
    if (sentido==0){velocidad=-velocidadbase;
 }
    if(sentido==1){velocidad=0;}
    if (sentido==2){velocidad=velocidadbase;
}
 

    //println(sentido);
    if (sentido2==0){velocidad2=-velocidadbase;
}
    if(sentido2==1){velocidad2=0;}
    if (sentido2==2){velocidad2=velocidadbase;
}
    if(xPos2[xPos2.length-1]-ancho<width/2){
  //sentido2=1;
xPos2[xPos2.length-1]=(width/2)+ancho;
}
   if(xPos2[xPos2.length-1]+ancho>width){
  //sentido2=1;
xPos2[xPos2.length-1]=width-ancho;
}
 
 
  xPos[xPos.length-1]= xPos[xPos.length-1]-velocidad;
 xPos2[xPos2.length-1]= xPos2[xPos2.length-1]-velocidad2;
 for (int i=0;i<xPos.length-1;i++){
  xPos[i]=xPos[i+1];
}
//Este último bucle podría reducirse justamente al anterior
//(es el mismo número de puntos)
 for (int i=0;i<xPos2.length-1;i++){
  xPos2[i]=xPos2[i+1];
}
fill(255,255,255);
for (int i=0;i<yPos.length;i++){
  ellipse(xPos[i]-ancho,yPos[i],10,10);
    ellipse(xPos[i]+ancho,yPos[i],10,10);
      ellipse(xPos2[i]-ancho,yPos[i],10,10);
    ellipse(xPos2[i]+ancho,yPos[i],10,10);
  
}
}
void actualizacoche(){

  xCoche1=valor1*width/512;
  xCoche2=width/2+valor2*width/512;
  if (xCoche1<xPos[height/2]-ancho||xCoche1+20>xPos[height/2]+ancho){
    fill(255,0,0);}
    else {fill(255,255,255);}
 rect(xCoche1,(height/2)-25,20,20);
   if (xCoche2<xPos2[height/2]-ancho||xCoche2+20>xPos2[height/2]+ancho){
    fill(255,0,0);}
    else {fill(255,255,255);}
rect(xCoche2,(height/2)-25,20,20);
}
void keyPressed(){
 if (key == 'a' || key=='A'){
  xCoche1=xCoche1-5;
  if (xCoche1<0){
    xCoche1=0;
  }
 }
  if (key == 'd' || key=='D'){
  xCoche1=xCoche1+5;
  if (xCoche1>(width/2)-50){
    xCoche1=(width/2)-50;
  }
 }
  if (key == 'j' || key=='J'){
  xCoche2=xCoche2-5;
  if (xCoche2<width/2){
    xCoche2=width/2;
  }
 }
    if (key == 'l' || key=='L'){
  xCoche2=xCoche2+5;
  if (xCoche2>width-50){
    xCoche2=width-50;
  }
 }
}
void leeMandos(){
  if (miPuerto.available() > 0) {

   
  }
}
void serialEvent(Serial myPort) {
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
 if (seriesContados > 1 ) {
  valor1 = valorSerie[0];
  valor2 = valorSerie[1];
 
  // print the values (for debugging purposes only):
  println(valor1 + "\t" + valor2);
  // Send a capital A to request new sensor readings:
  myPort.write('A');
  // Reset serialCount:
  seriesContados = 0;
 }
 }
}