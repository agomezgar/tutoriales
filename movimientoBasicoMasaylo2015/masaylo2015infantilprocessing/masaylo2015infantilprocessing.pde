import processing.serial.*;
PImage flechas;


Serial miPuerto;
String texto="Esperando datos...";
void setup(){
    println(Serial.list());
  miPuerto = new Serial(this, Serial.list()[1], 9600);
  size (626,469);
  fill(255,255,255);
  textSize(42);
  flechas=loadImage("flechasteclado.jpg");
}
void draw(){
  background(255,255,255);
  image(flechas,0,0);
  text(texto,width*2/3,height/4);
}
void mouseReleased(){

  if ((mouseX>width/3)&&(mouseX<2*width/3)&&(mouseY<height/2)){
    texto="Adelante";
       miPuerto.clear();
   miPuerto.write(1); 
   miPuerto.clear();
 
  }else if ((mouseX<width/3)&&(mouseY>height/2)){
    texto="Izquierda";
       miPuerto.clear();
   miPuerto.write(3); 
  miPuerto.clear();
  } else if ((mouseX>2*width/3)&&(mouseY>height/2)){
    texto="Derecha";
       miPuerto.clear();
   miPuerto.write(4); 
  miPuerto.clear();
  } else if ((mouseX>width/3)&&(mouseX<2*width/3)&&(mouseY>height/2)){
    texto="Atras";
       miPuerto.clear();
   miPuerto.write(2); 
  miPuerto.clear();
  } 

}



