coche c1,c2,c3;
coche [] fila1,fila2, fila3, fila4, fila5;


frog rana;
boolean atropellado;
int vidas;
int vCoche;
void setup(){
atropellado=false;
vidas=3;
 size(800,600);

 rana=new frog(400,550);
fila1=new coche[3];
fila2=new coche[4];
fila3=new coche[3];
fila4=new coche[4];
fila5=new coche[5];
//creamos fila 1
 vCoche=(int)random(3,7);

for (int i=0;i<3;i++){
    //pequeño ajuste para que coincidan las coordenadas de coche y rana

 fila1[i]=new coche(-300+i*150,-20+height/6,vCoche);
}
//creamos fila 2
 vCoche=(int)random(-3,-7);

for (int i=0;i<4;i++){
 fila2[i]=new coche(-300+i*200,2*height/6,vCoche);
}
//creamos fila 3
 vCoche=(int)random(3,7);

for (int i=0;i<3;i++){
 fila3[i]=new coche(-300+i*160,height/2,vCoche);
}
//creamos fila 4
 vCoche=(int)random(-3,-7);

for (int i=0;i<4;i++){
  //pequeño ajuste para que coincidan las coordenadas de coche y rana
 fila4[i]=new coche(-300+i*180,20+4*height/6,vCoche);
}
//creamos fila 
 vCoche=(int)random(3,7);
for (int i=0;i<5;i++){
  
 fila5[i]=new coche(-300+i*100,5*height/6,vCoche);
}
}

void draw(){
if (!atropellado){
  background(255,255,255);
//moviendo fila 1
for (int i=0;i<3;i++){
 fila1[i].mueveCoche();
 fila1[i].dibujaCoche();
 //Comprobamos si la posición de algún coche coincide con la rana
  if (fila1[i].compruebaAtropello(rana)){
  atropellado=true; 
  break;
 }
}
//moviendo fila 2
for (int i=0;i<4;i++){
 fila2[i].mueveCoche();
 fila2[i].dibujaCoche();
  //Comprobamos si la posición de algún coche coincide con la rana
  if (fila2[i].compruebaAtropello(rana)){
  atropellado=true; 
  break;
 }
}
//moviendo fila 3
for (int i=0;i<3;i++){
 fila3[i].mueveCoche();
 fila3[i].dibujaCoche();
  //Comprobamos si la posición de algún coche coincide con la rana
  if (fila3[i].compruebaAtropello(rana)){
  atropellado=true; 
  break;
 }
}
//moviendo fila 4
for (int i=0;i<4;i++){
 fila4[i].mueveCoche();
 fila4[i].dibujaCoche();
 if (fila4[i].compruebaAtropello(rana)){
  atropellado=true; 
  break;
 }
}
//moviendo fila 5
for (int i=0;i<5;i++){
 fila5[i].mueveCoche();
 fila5[i].dibujaCoche();
  //Comprobamos si la posición de algún coche coincide con la rana
  if (fila5[i].compruebaAtropello(rana)){
  atropellado=true; 
  break;
 }
}
 rana.dibujaFrog();
}
}

void keyPressed(){
if (keyCode==ENTER){
  if (atropellado){
 atropellado=false; 
 rana.ponCoordenadas(400,550);
  }}

 if (keyCode==UP){

   rana.mueveFrog(0,-30);

 }

  if (keyCode==DOWN){

   rana.mueveFrog(0,30);

 }

  if (keyCode==LEFT){

   rana.mueveFrog(-30,0);

 }

  if (keyCode==RIGHT){

   rana.mueveFrog(30,0);

 }

}



class coche{

 int x, y, vx,r,g,b,ancho,alto; 

  coche(int a, int b, int c){

   x=a;

   y=b;

   vx=c;

   r=(int)random(255);

   g=(int)random(255);

   b=(int)random(255);

   ancho=60;

   alto=30;

  }

  void mueveCoche(){

   x=x+vx;

   if (x>width&&vx>0){

    x=0; 

   }
   if (x<0&&vx<0){
    x=width; 
   }

  }

  void dibujaCoche(){

    fill(r,g,b);

   rect(x,y,ancho,alto);

  }
  boolean compruebaAtropello(frog rana){
  if (x<rana.dameX()&&x+ancho>rana.dameX()&&y<rana.dameY()&&y+alto>rana.dameY()){
   return true; 
  }else{
   return false; 
  }
  }

}

class frog{

 int x, y, radio, r,g,b;

 frog(int a, int b){

  x=a;

  y=b;

  radio=30;

  r=(int)random(255);

  g=(int)random(255);

  b=(int)random(255);

 }

void mueveFrog(int a, int b){

 x=x+a;

 y=y+b;

}

void dibujaFrog(){

 fill(r,g,b);

 ellipse(x,y,radio,radio);

}
int dameX(){
  
  return x;
}
int dameY(){
  return y;
}
void ponCoordenadas(int a, int b){
 x=a;
 y=b;
}

}