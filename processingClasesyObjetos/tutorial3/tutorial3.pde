class pelota{
 int tamanyo,x,y,vx,vy;
 pelota(int a, int b){
  tamanyo=(int)random(100);
  x=a;
  y=b;
  vx=(int)random(-10,10);
  vy=(int)random(-10,10);
 }

  void dibujaPelota(){
   ellipse(x,y,tamanyo,tamanyo); 
  }
  void muevePelota(){
   x=x+vx;
   y=y+vy;
   if ((x>800)||(x<0)){
     vx=-vx;
   }  
   if ((y>600)||(y<0)){
    vy=-vy; 
   }
}
}
pelota [] Pelotas=new pelota[9];
void setup(){
 size(800,600); 
for (int i=0;i<9;i++){
 Pelotas[i]=new pelota((int)random(800),(int)random(600)); 
}
}
void draw(){
 background(255,255,255);
for (int i=0;i<9;i++){

Pelotas[i].muevePelota();
 Pelotas[i].dibujaPelota();
}
 
}