/*
Mesa de mezclas

Codigo para Processing
Antonio Gomez Garcia
IES Eduardo Valencia
Calzada de Calatrava
 */
//Importamos las librerias minim y serial
import ddf.minim.*;
import processing.serial.*;
//Creamos un objeto minim que controlara la reproduccion de
//canciones, y tantos objetos AudioPlayer como MP3 a reproducir
//Tambien creamos un objeto Serial para leer el codigo
Minim minim;
AudioPlayer cancion1,cancion2,cancion3,cancion4,cancion5,grabacion,chas;
AudioPlayer arcade,gong,gun;
Serial miPuerto;
AudioInput in;
AudioRecorder recorder;
int c1,c2,c3,c4,c5;
boolean grabando;
void setup()
{
size(800, 600);
c1=3;
c2=3;
c3=3;
c4=3;
c5=4;

minim = new Minim(this);
  println(Serial.list());
  // Abre el puerto que se este usando a la velocidad deseada
  //Tener en cuenta que hay que elegir el numero correspondiente
  //al puerto COM que estemos usando en Arduino, y ponerlo
  //en Serial.list[x]
  miPuerto = new Serial(this, Serial.list()[1], 9600);
cancion1 = minim.loadFile("cancion11.mp3");
cancion2= minim.loadFile("cancion21.MP3");
cancion3= minim.loadFile("cancion31.mp3");
cancion4= minim.loadFile("cancion41.mp3");
cancion5=minim.loadFile("cancion51.MP3");
chas = minim.loadFile("chas.WAV");
arcade = minim.loadFile("arcade.wav");
gong = minim.loadFile("gong.wav");
gun = minim.loadFile("gun.wav");
grabacion=minim.loadFile("grabacion.wav");
in = minim.getLineIn(Minim.STEREO, 512);
recorder = minim.createRecorder(in, "/data/grabacion.wav", true);
}

void draw()
{
  background(255,255,0);
  stroke(255,0,0);
        for(int i = 0; i < (width/2)-10; i++){
  line(i, height/12 + cancion1.left.get(i)*50, i+1, height/12 + cancion1.left.get(i+1)*50);
  line(i, (height/12)*2 + cancion1.right.get(i)*50, i+1, (height/12)*2+ cancion1.right.get(i+1)*50);
  
}
stroke(0,0,255);
        for(int i = 0; i < (width/2)-10; i++){
  line(i, (height/12)*3 + cancion2.left.get(i)*50, i+1, (height/12)*3+ cancion2.left.get(i+1)*50);
  line(i, (height/12)*4 + cancion2.right.get(i)*50, i+1,(height/12)*4 + cancion2.right.get(i+1)*50);
  
}
  stroke(0,255,0);
        for(int i = 0; i < width; i++){
  line(i, (height/12)*5 + cancion3.left.get(i)*50, i+1, (height/12)*5 + cancion3.left.get(i+1)*50);
  line(i, (height/12)*6+ cancion3.right.get(i)*50, i+1, (height/12)*6 + cancion3.right.get(i+1)*50);
  
}
stroke(0,255,255);
        for(int i = (width/2)+10; i < width; i++){
  line(i, height/12+ cancion4.left.get(i)*50, i+1,height/12+ cancion4.left.get(i+1)*50);
  line(i, (height/12)*2 + cancion4.right.get(i)*50, i+1, (height/12)*2 + cancion4.right.get(i+1)*50);
  
}
stroke(255,0,255);
        for(int i = (width/2)+10; i < width; i++){
  line(i, (height/12)*3+ cancion5.left.get(i)*50, i+1, (height/12)*3 + cancion5.left.get(i+1)*50);
  line(i, (height/12)*4+ cancion5.right.get(i)*50, i+1, (height/12)*4+ cancion5.right.get(i+1)*50);
  
}
stroke(0);

      for(int i =0; i <in.left.size()-1; i++){
  line(i, 450 + in.left.get(i)*50, i+1, 450 + in.left.get(i+1)*50);
  line(i, 550 + in.right.get(i)*50, i+1, 550 + in.right.get(i+1)*50);
  
}

  if (miPuerto.available() > 0) {
    int inByte = miPuerto.read();
    if(inByte == 'a') {
      print ("Cantando cancion 1");
      c1++;
      if (c1==4){
        c1=1;
      }
    switch(c1) {
  case 1:
  if (cancion1.isPlaying()){
 cancion1.close(); 
  }
  cancion1 = minim.loadFile("cancion11.mp3");
cancion1.play();
    break;
    case 2:
  if (cancion1.isPlaying()){
 cancion1.close(); 
  } 
  cancion1 = minim.loadFile("cancion12.mp3");
cancion1.play();
    break;
    case 3:
  if (cancion1.isPlaying()){
 cancion1.close(); 
  }
  cancion1 = minim.loadFile("cancion13.MP3");
cancion1.play();
    break;
}


     
    }
        if(inByte == 'b') {
      print ("Cantando cancion 2");
     c2++;
      if (c2==4){
        c2=1;
      }
    switch(c2) {
  case 1:
  if (cancion2.isPlaying()){
 cancion2.close(); 
  }
  cancion2 = minim.loadFile("cancion21.MP3");
cancion2.play();
    break;
    case 2:
  if (cancion2.isPlaying()){
 cancion2.close(); 
  }
  cancion2 = minim.loadFile("cancion22.mp3");
cancion2.play();
    break;
    case 3:
  if (cancion2.isPlaying()){
 cancion2.close(); 
  }
  cancion2 = minim.loadFile("cancion23.mp3");
cancion2.play();
    break;
}

    }
    if(inByte == 'c') {
      print ("Cantando cancion 3");
     c3++;
      if (c3==4){
        c3=1;
      }
    switch(c3) {
  case 1:
  if (cancion3.isPlaying()){
 cancion3.close(); 
  }
  cancion3 = minim.loadFile("cancion31.mp3");
cancion3.play();
    break;
    case 2:
  if (cancion3.isPlaying()){
 cancion3.close(); 
  }

cancion3.play();
    break;
    case 3:
  if (cancion3.isPlaying()){
 cancion3.close(); 
  }
  cancion3 = minim.loadFile("cancion33.mp3");
cancion3.play();
    break;
}
     
    }
        if(inByte == 'd') {
      print ("Cantando cancion 4");
     c4++;
      if (c4==4){
        c4=1;
      }
    switch(c4) {
  case 1:
  if (cancion4.isPlaying()){
 cancion4.close(); 
  }
  cancion4 = minim.loadFile("cancion41.mp3");
cancion4.play();
    break;
    case 2:
  if (cancion4.isPlaying()){
 cancion4.close(); 
  }
  cancion4 = minim.loadFile("cancion42.mp3");
cancion4.play();
    break;
    case 3:
  if (cancion4.isPlaying()){
 cancion4.close(); 
  }
  cancion4 = minim.loadFile("cancion43.mp3");
cancion4.play();
    break;
}
     
    }
        if(inByte == 'e') {
      print ("Cantando cancion 5");
     c5++;
      if (c5==5){
        c5=1;
      }
    switch(c5) {
  case 1:
  if (cancion5.isPlaying()){
 cancion5.close(); 
  }
  cancion5 = minim.loadFile("grabacion.wav");
cancion5.play();
    break;
    case 2:
  if (cancion5.isPlaying()){
 cancion5.close(); 
  } 
  cancion5 = minim.loadFile("cancion52.mp3");
cancion5.play();
    break;
    case 3:
  if (cancion5.isPlaying()){
 cancion5.close(); 
  }
  cancion5 = minim.loadFile("cancion53.mp3");
cancion5.play();
    break;
        case 4:
  if (cancion5.isPlaying()){
 cancion5.close(); 
  }
  cancion5 = minim.loadFile("cancion51.MP3");
cancion5.play();
    break;
}
     
    }
    
        if(inByte == 'k') {

      print ("metalhit");
  arcade= minim.loadFile("metalhit.wav");
     
arcade.play();

     
    }
        if(inByte == 'l') {

      print ("gong.wav");
  gong= minim.loadFile("gong.wav");
     
gong.play();

     
    }
            if(inByte == 'm') {

      print ("metalhit");
  gun= minim.loadFile("bell.wav");
     
gun.play();

     
    }
      
    if (inByte=='g'){
     if (recorder.isRecording()){
     print("Parando grabación...");
      if (cancion1.isPlaying()){
       cancion1.close();
  cancion1 = minim.loadFile("cancion11.mp3");
     }
          if (cancion2.isPlaying()){
       cancion2.close();
  cancion2 = minim.loadFile("cancion21.MP3");
     }
          if (cancion3.isPlaying()){
       cancion3.close();
         cancion3 = minim.loadFile("cancion31.mp3");
     }
          if (cancion4.isPlaying()){
       cancion4.close();
         cancion4 = minim.loadFile("cancion41.mp3");
     }
          if (cancion5.isPlaying()){
       cancion5.close();
         cancion5 = minim.loadFile("grabacion.wav");
     }
     recorder.endRecord();
   
     c5=4;
     recorder.save();
     print ("Guardando grabación");
     
     }
    else {
      recorder = minim.createRecorder(in, "/data/grabacion.wav", true);
     print ("Grabando..");
     stroke(0);
     if (cancion1.isPlaying()){
       cancion1.close();
  cancion1 = minim.loadFile("cancion11.mp3");
     }
          if (cancion2.isPlaying()){
       cancion2.close();
  cancion2 = minim.loadFile("cancion21.MP3");
     }
          if (cancion3.isPlaying()){
       cancion3.close();
         cancion3 = minim.loadFile("cancion31.mp3");
     }
          if (cancion4.isPlaying()){
       cancion4.close();
         cancion4 = minim.loadFile("cancion41.mp3");
     }
          if (cancion5.isPlaying()){
       cancion5.close();
         cancion5 = minim.loadFile("grabacion.wav");
     }
     recorder.beginRecord();
     c5=4;

    } 
      
    }
}
}

void stop()
{

cancion1.close();
cancion2.close();
cancion3.close();
cancion4.close();
cancion5.close();
minim.stop();


super.stop();
}
