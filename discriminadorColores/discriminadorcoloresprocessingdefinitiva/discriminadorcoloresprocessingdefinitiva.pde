import ddf.minim.*;
import processing.serial.*;
//Para la comparativa de colores: 0-negro 1-blanco 2-rojo 3-verde
int colorAnterior;
int colorActual=0;
int repiteColor=0;
boolean firstContact=false;
boolean seRepite=false;
Minim minim;
AudioPlayer preparado,detecta,colorDetectado,cansino;
Serial miPuerto;
//AudioInput input;

void setup()
{
size(800, 600);
minim = new Minim(this);
textSize(64);
  println(Serial.list());
  // Open the port you are using at the rate you want:
  miPuerto = new Serial(this, Serial.list()[1], 9600);
preparado=minim.loadFile("preparado.mp3");
detecta=minim.loadFile("empezamos.mp3");
colorDetectado=minim.loadFile("vamosalla.mp3");
preparado.play();
cansino=minim.loadFile("cansino.mp3");
delay(10000);

  }

void draw()
{
  detecta.play();
  delay(3000);
  colorDetectado.play();
  delay(3000);
  if (seRepite){
    cansino.play();
    delay(5000);
    seRepite=false;
  }

  if (miPuerto.available() > 0) {
    int inByte = miPuerto.read();
      if (firstContact == false) {
    if (inByte=='A') {
      miPuerto.clear();
      firstContact = true;
      miPuerto.write("A");
      println("contacto!");
    }
      }
    if(inByte == 'b') {
   
      background(255,255,255);
      fill(0,0,0);
      text("Color: blanco",width/3,height/4);
    
   
      colorAnterior=colorActual;
      colorActual=1;
      if (colorAnterior==colorActual){
       repiteColor++; 
      }
      String archivo="detecta"+dameNumero()+".mp3";
      detecta=minim.loadFile(archivo);
  
      colorDetectado=minim.loadFile("blanco"+dameNumero()+".mp3");
  
        miPuerto.clear();
 

 
    }
        if(inByte == 'n') {
    

background(0,0,0);
      fill(255,255,255);
      text("Color: negro",width/3,height/4);
    
      colorAnterior=colorActual;
      colorActual=0;
      if (colorAnterior==colorActual){
       repiteColor++; 
      }

   
         String archivo="detecta"+dameNumero()+".mp3";
      detecta=minim.loadFile(archivo);
 
   
      colorDetectado=minim.loadFile("negro"+dameNumero()+".mp3");

       miPuerto.clear();
    }
        if(inByte == 'v') {
background(0,255,0);
fill(255,0,0);

      text("Color: verde",width/3,height/4);
  

      colorAnterior=colorActual;
      colorActual=3;
      if (colorAnterior==colorActual){
       repiteColor++; 
      }

            String archivo="detecta"+dameNumero()+".mp3";
      detecta=minim.loadFile(archivo);


      colorDetectado=minim.loadFile("verde"+dameNumero()+".mp3");

       miPuerto.clear();
    }
        if(inByte == 'r') {
     background(255,0,0);
           fill(0,255,255);
      text("Color: rojo",width/3,height/4);
    

      colorAnterior=colorActual;
      colorActual=2;
      if (colorAnterior==colorActual){
       repiteColor++; 
      }
      
                 String archivo="detecta"+dameNumero()+".mp3";
      detecta=minim.loadFile(archivo);

 
      colorDetectado=minim.loadFile("rojo"+dameNumero()+".mp3");
  
        miPuerto.clear();
    }
if (repiteColor>2){
  repiteColor=0;
  seRepite=true;
  miPuerto.clear();
}
// do what you do
}
}
String dameNumero(){
  String cadena=str(1+(int)random(2));
  return cadena;
}
void mousePressed(){
  miPuerto.write('1');
  print("Ordenando...");
}
