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
pelota Pelota1,Pelota2;
void setup(){
 size(800,600); 
 Pelota1=new pelota(300,300);
 Pelota2=new pelota(200,400);
}
void draw(){
 background(255,255,255);

 Pelota1.dibujaPelota();
Pelota1.muevePelota();
 Pelota2.dibujaPelota();
 Pelota2.muevePelota();
 
}