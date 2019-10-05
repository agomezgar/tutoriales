import processing.serial.*;
Serial miPuerto;
import controlP5.*;

ControlP5 control1;
int roll,pitch,yaw;
void setup(){
println(Serial.list());
  miPuerto= new Serial(this, Serial.list()[32], 9600);

 size(800,600); 
 control1=new ControlP5(this);
 control1.addSlider("Roll")
  .setPosition(width/5,5*height/7)
 .setWidth(3*width/5)
 .setValue(90)
 .setRange(0,180);

 control1.addSlider("Pitch")
  .setPosition(width/5,4*height/7)
 .setWidth(3*width/5)
 .setValue(90)
 .setRange(0,180);

 control1.addSlider("Yaw")
  .setPosition(width/5,3*height/7)
 .setWidth(3*width/5)
 .setValue(90)
 .setRange(0,180);
}

void draw(){
  background(0,255,0);
  roll=(int)control1.getController("Roll").getValue();
  pitch=(int)control1.getController("Pitch").getValue();
  yaw=(int)control1.getController("Yaw").getValue();

  miPuerto.write(roll+','+pitch+','+yaw);

  text(roll,400,100);
  
}