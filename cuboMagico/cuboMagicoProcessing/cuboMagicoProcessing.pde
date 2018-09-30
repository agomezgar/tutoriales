import processing.serial.*;
Serial miPuerto;

int newLine = 13; // new line character in ASCII
float yaw;
float pitch;
float roll;
String message;
String [] ypr = new String [3];

void setup()
{
  size(600, 500, P3D);
 println(Serial.list());
  /*Set my serial port to same as Arduino, baud rate 9600*/
  miPuerto = new Serial(this, Serial.list()[1], 9600);
  textSize(16); // set text size
  textMode(SHAPE); // set text mode to shape
  miPuerto.write("s");
}

void draw(){
  serialEvent();
  background(255);
  translate(width/2,height/2);
  pushMatrix();
  rotateX(pitch);
  rotateY(-yaw);
  rotateZ(-roll);
  drawArduino();
  popMatrix();
  print(pitch);
  print("\t");
  print(roll);
  print("\t");
    print(-yaw);
  print("\t");
  miPuerto.write("s");
  
  
}
void serialEvent(){
 message=miPuerto.readStringUntil(newLine);
 if (message!=null){
   ypr=split(message,",");
   yaw=float(ypr[0]);
   pitch=float(ypr[1]);
   roll=float(ypr[2]);
 }
}
void drawArduino(){
 stroke(0,90,90);
 fill(0,130,130);
 box(300,10,200);
 stroke(0);
 fill(80);
 translate(60,-10,90);
 box(170,20,10);
 translate(-20,0,-180);
 box(210,20,10);
 
}