import processing.serial.*; 
 Serial myPort;
 int val;
 int posicion=-50;
 int velocidad=0;
 boolean moviendose=false;
 void setup(){
 //IMPRIME POR CONSOLA LA LISTA DE PUERTOS SERIE DETECTADOS
   print (Serial.list());
   //SI NO CONECTA A TU ARDUINO, VE CAMBIANDO EL VALOR 0 POR 1,2,3...
   myPort = new Serial(this, Serial.list()[0], 9600);
   size(800,600);
   fill (0,0,125);

 }
 void draw(){
   if (myPort.available()>0){
 val=myPort.read(); 
 println(val);
 if (val==1){
   if (!moviendose){
posicion=-50;
velocidad=10;
moviendose=true;
   }
myPort.clear();
 }
if (val==2){
   if (!moviendose){
posicion=width+50;
velocidad=-10;
moviendose=true;
   }
  myPort.clear();
 }
   }
   background (255,255,255);
   ellipse(posicion,width/2,50,50);
   if ((posicion>(width+50))||(posicion<(-50))){
     velocidad=0;
     moviendose=false;
 }
 posicion=posicion+velocidad;
 }