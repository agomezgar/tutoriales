import processing.serial.*; 
 Serial myPort;  
muro m;
int val;
int altura;
int v=3;
int choques=0;
boolean juegoSigue;
int valorAleatorio;

boolean firstContact = false;
String texto="Nº de choques: ";
void setup() {
  size(800, 600); 
  //en Serial.list()[numero], éste será el orden en que 
  //hemos conectado nuestra Arduino al USB. Ir probando con 0,1,2...
  myPort = new Serial(this, Serial.list()[1], 9600);
  m=new muro(100,v);
  textSize(32);
}
void draw() {
  if (juegoSigue){
  background(255,255,255);
   fill (255,0,0);
  m.dibuja();
  m.mueve();
  
  if (m.dameX()>800){
    valorAleatorio=(int)random(600);
    if (valorAleatorio>500){
      valorAleatorio=550;
    }
    
    if (valorAleatorio<100){
      valorAleatorio=100;
    }
    m.hazAltura(valorAleatorio);
    m.hazX(0);
    m.hazVelocidad(v+2);
  }
  
  if((m.dameX()<400)&&(m.dameX()>350)&&((altura<m.dameAltura())||(altura>m.dameAltura()+100))){
    juegoSigue=false;
    choques++;
  }
  
if (myPort.available()>0){
 val=myPort.read(); 
}
println(val);

altura=(int)map(val,190,240,0,600);
ellipse(400,altura,50,50);
fill(0,0,255);
text(texto+choques,500,50);
  }else{
    //TODO QUEDA PARADO HASTA QUE PULSAMOS ESPACIO
   background(255,0,0);
   fill(255,255,255);
  m.dibuja(); 
  ellipse(400,altura,50,50);
  text("PULSA ESPACIO PARA CONTINUAR",200,200);
  }
}
void keyPressed(){
if (key==' '){
  juegoSigue=true;
  m.hazX(0);
  m.hazVelocidad(2);
 } 
}

//CREAMOS UNA CLASE PARA EL MURO QUE DEBE SALTAR LA PELOTA.
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
  
  rect(this.x,0,50,altura);
  rect(this.x,altura+200,50,600-altura);
 }
 void mueve(){
  this.x=this.x+this.velocidad; 
 }
 int dameX(){
  return this.x; 
 }
 int dameAltura(){
   return this.altura;
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
