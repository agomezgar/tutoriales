import processing.serial.*; //import the Serial library
 Serial myPort;  //the Serial port object
muro m;
int val;
int altura;
int v=1;
int valorAleatorio;
// since we're doing serial handshaking, 
// we need to check if we've heard from the microcontroller
boolean firstContact = false;
void setup() {
  size(800, 600); //make our canvas 200 x 200 pixels big
  //  initialize your serial port and set the baud rate to 9600
  myPort = new Serial(this, Serial.list()[0], 9600);
  m=new muro(100,1);
}
void draw() {
  background(255,255,255);
   
  m.dibuja();
  m.mueve();
  if (m.dameX()>800){
    valorAleatorio=(int)random(600);
    if (valorAleatorio>550){
      valorAleatorio=550;
    }
    m.hazAltura(valorAleatorio);
    m.hazX(0);
    m.hazVelocidad(v+5);
  }
  //we can leave the draw method empty, 
  //because all our programming happens in the serialEvent (see below)
if (myPort.available()>0){
 val=myPort.read(); 
}
println(val);
altura=(int)map(val,140,220,0,600);
ellipse(400,altura,50,50);
}
class muro{
 int x,rojo,verde,azul;
 int altura;
 int velocidad;
   muro (int alt, int vel){
   altura=alt;
   velocidad=vel;
   x=0;
   rojo=(int)random(255);
   verde=(int)random(255);
   azul=(int)random(255);
   
 }
 void dibuja(){
  rect(this.x,600-altura,50,altura); 
  rect(this.x,0,50,400-altura);
 }
 void mueve(){
  this.x=this.x+this.velocidad; 
 }
 int dameX(){
  return this.x; 
 }
 void hazX(int a){
  this.x=a; 
 }
 void hazAltura(int a){
   this.altura=a;
 }
 void hazVelocidad(int a){
  this.velocidad=a; 
 }
}