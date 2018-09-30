class pelota{
 int tamanyo,x,y;
 pelota(int a, int b){
  tamanyo=(int)random(100);
  x=a;
  y=b;
 }

  void dibujaPelota(){
   ellipse(x,y,tamanyo,tamanyo); 
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

 Pelota2.dibujaPelota();
 
}