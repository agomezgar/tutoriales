import ddf.minim.*;
import processing.serial.*;
import ddf.minim.ugens.*;
Minim minim;
Serial miPuerto;
AudioOutput out;
pelota balon;
raqueta r1,r2;
int golesVerde, golesAzul;
boolean activo=false;
int [] valorSerie=new int[2];
int seriesContados=0;
int valor1,valor2,altura1,altura2;//valores que medirán el valor leido y la altura de cada raqueta
int vMaximo1,vMinimo1,vMaximo2,vMinimo2;//valores que guardarán el máximo y el mínimo registrados por los LDR 
boolean firstContact=false;
boolean juegoenCurso=false;
boolean juegoFinalizado=false;
void setup(){
  valor1=height/2;
  valor2=height/2;
  vMaximo1=vMaximo2=0;
  vMinimo1=vMinimo2=255;
  golesVerde=golesAzul=0;
  
  println(Serial.list());
    miPuerto = new Serial(this, Serial.list()[32], 9600);

  minim=new Minim(this);
  out=minim.getLineOut();
 size(800,600); 
   balon=new pelota(300,200,40,5);
   r1=new raqueta(width/8,height/3,20,100);
   r2=new raqueta(7*width/8,height/3,20,100);
 balon.dibujaPelota();
 r1.dibujaRaqueta();
 r2.dibujaRaqueta();
 textSize(32);
}

void draw(){
  if(!juegoFinalizado){
  background(255,255,0);
  noStroke();
  fill(0,255,0);
  text(golesVerde,width/6,height/6);
  fill(0,0,255);
  text(golesAzul,5*width/6,height/6);
  fill(255,255,255);
 balon.dibujaPelota();

 altura1=(int)map(valor1,vMinimo1,vMaximo1,-300,height+100);
 altura2=(int)map(valor2,vMinimo2,vMaximo2,-300,height+100);
 r1.mueveRaqueta(altura1);
 r2.mueveRaqueta(altura2);
 fill(0,255,0);
  r1.dibujaRaqueta();
  fill(0,0,255);
 r2.dibujaRaqueta();
 if (balon.dameX()>r1.dameX()&&balon.dameX()<r1.dameX()+50&&balon.dameY()>altura1&&balon.dameY()<(altura1+200)){
balon.vx=balon.vx*(-1);
 }
  if (balon.dameX()>r2.dameX()&&balon.dameX()<r2.dameX()+50&&balon.dameY()>altura2&&balon.dameY()<(altura2+200)){
balon.vx=balon.vx*(-1);
 }
 if (juegoenCurso){
 balon.muevePelota();
 }
  if (balon.damePosicion()==1){
    fill(0,0,255);
    text("Azul anota",width/3,height/3);
        golesAzul++;
balon.colocaPelota();
    juegoenCurso=false;
    if (golesAzul>4){
      juegoFinalizado=true;
    }
  }
 if (balon.damePosicion()==2){
   fill(0,255,0);
       text("Verde anota",2*width/3,height/3);

golesVerde++;
juegoenCurso=false;
balon.colocaPelota();
    if (golesVerde>4){
      juegoFinalizado=true;
    }
}
  }else{
   background(255,255,0);
   text("Juego finalizado",width/4,height/4);
   if (golesAzul>golesVerde){
     text("Gana el jugador azul",width/4,2*height/4);
  }else{
         text("Gana el jugador verde",width/4,2*height/4);

  }
    text("Pulse la tecla N para nuevo juego",width/4,3*height/4);

  } 
}
void keyPressed(){
  if ((key=='n')||(key=='N')){
   if (juegoFinalizado==true){
     juegoFinalizado=false;
     juegoenCurso=false; 
     golesAzul=golesVerde=0;
     balon.colocaPelota();
  
   }
 }else{
    
  juegoenCurso=true;
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
 // If we have 2 bytes:
 if (seriesContados > 1 ) {
  valor1 = valorSerie[0];
  valor2 = valorSerie[1];
 
 if (valor1>vMaximo1)vMaximo1=valor1;
 if (valor1<vMinimo1)vMinimo1=valor1;
 if (valor2>vMaximo2)vMaximo2=valor2;
 if (valor2<vMinimo2)vMinimo2=valor2;
  // print the values (for debugging purposes only):
  println(valor1 + "\t" + valor2+"\t"+vMinimo1+"\t"+vMaximo1+"\t"+vMinimo2+"\t"+vMaximo2);
  // Send a capital A to request new sensor readings:
  myPort.write('A');
  // Reset serialCount:
  seriesContados=0;
 }
 }
}
class pelota{

 int x, y, radio,vx,vy;
 int posicion;//1 significa que se ha colado por la izquierda y 2 por la derecha
  pelota(int a, int b, int c, int d){
   x=a;
   y=b;
   radio=c;
   vx=d;
   vy=d;
   posicion=0;
 }
 void dibujaPelota(){
  ellipse(x,y,radio,radio); 
 }
 void colocaPelota(){
  x=(int)random(width/3,2*width/3);
  y=(int)random(height/3,2*height/3);
  posicion=0;
   
 }
 int dameX(){
  return x; 
 }
 int dameY(){
  return y; 
 }
 int damePosicion(){
   return posicion;
 }
 void muevePelota(){
  x=x+vx;
  y=y+vy;
  
  if (x>width){
     juegoenCurso=false;
     posicion=2;
   vx=-vx;
     out.playNote( 0, 3, "F3" );

  }
    if (x<0){
      juegoenCurso=false;
      posicion=1;
      vx=-vx;
     out.playNote( 0, 3, "A3" );
  }
  if (y>height||y<0) {
    vy=-vy;
      out.playNote( 0, 1, "B3" );
  }
 
 }
}
class raqueta{
 int x, y,ancho,alto;
 raqueta(int a, int b, int c, int d){
   x=a;
   y=b;
   ancho=c;
   alto=d;
 }
  void dibujaRaqueta(){
   rect(x,y,ancho,alto); 
    
  }
  void mueveRaqueta(int columna){
    y=columna;
  }
   int dameX(){
  return x; 
 }
 int dameY(){
  return y; 
 }
}