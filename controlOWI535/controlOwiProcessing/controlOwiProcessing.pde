import processing.serial.*;
PImage izquierda,derecha,arriba1,arriba2,abajo1,abajo2;
PImage coger;
boolean cogido=false;
Serial miPuerto;
String texto="Esperando datos...";
void setup(){
    println(Serial.list());
 miPuerto = new Serial(this, Serial.list()[0], 9600);
  size (800,400);
  fill(255,255,255);
  textSize(42);

  izquierda=loadImage("izquierda.png");
   derecha=loadImage("derecha.png");
    arriba1=loadImage("arriba.png");
     abajo1=loadImage("abajo.png");
      arriba2=loadImage("arriba.png");
       abajo2=loadImage("abajo.png");
       coger=loadImage("cogersoltar.png");
}
void draw(){
  background(255,255,255);
  image(izquierda,0,0);
  image(derecha,0,200);
  image(arriba1,200,0);
  image(abajo1,200,200);
  image(arriba2,400,0);
  image(abajo2,400,200);
  image(coger,600,200);
  text(texto,600,50);
}

void mouseReleased(){

  if ((mouseX>0)&&(mouseX<200)&&(mouseY<200)){
    texto="Izquierda";
       miPuerto.clear();
 
   miPuerto.write('a'); 
   miPuerto.clear();
  }
    if ((mouseX>0)&&(mouseX<200)&&(mouseY>200)){
    texto="Derecha";
       miPuerto.clear();
   miPuerto.write('d'); 
   miPuerto.clear();
  }
    if ((mouseX>200)&&(mouseX<400)&&(mouseY<200)){
    texto="Sube Brazo 1";
       miPuerto.clear();

   miPuerto.write('w'); 
   miPuerto.clear();
  }
    if ((mouseX>200)&&(mouseX<400)&&(mouseY>200)){
    texto="Baja Brazo 1";
       miPuerto.clear();

   miPuerto.write('s'); 
   miPuerto.clear();
  }
    if ((mouseX>400)&&(mouseX<600)&&(mouseY<200)){
    texto="Sube Brazo 2";
       miPuerto.clear();

   miPuerto.write('o'); 
   miPuerto.clear();
  }
    if ((mouseX>400)&&(mouseX<600)&&(mouseY>200)){
    texto="Baja brazo 2";

       miPuerto.clear();

   miPuerto.write('k'); 
   miPuerto.clear();
  }
    if (mouseX>600){
      if (cogido){
    texto="Soltando";
       miPuerto.clear();

   miPuerto.write('p'); 
   miPuerto.clear();
      cogido=false;}else{
        texto="Agarrando";
       miPuerto.clear();
   miPuerto.write('l'); 
   miPuerto.clear(); 

   cogido=true;
  }
  
    }
}