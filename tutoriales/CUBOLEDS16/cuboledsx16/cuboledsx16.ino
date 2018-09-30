//Matriz de 4x4 para cada una de las 4 alturas del cubo
int led[4][4]={{22,23,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
//Array para definir las 4 alturas del cubo. Utilizar patillas
//PWM
int plano[4]={16,17,18,19};

void setup(){
  //Pines de 2 a 13 como salidas
  for (int i=0;i<20;i++){
    pinMode(i,OUTPUT);

  }
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  enciendeplanoxy(0,255);
  delay(2000);
    enciendeplanoxy(1,255);
  delay(2000);
    enciendeplanoxy(2,255);
  delay(2000);
    enciendeplanoxy(3,255);
  delay(2000);
}
void loop(){
  for (int i=0;i<5;i++){
for (int i=0;i<4;i++){
 enciendeplanoxy(i,255);
delay(100); 
}
    for (int i=4;i>0;i--){
 enciendeplanoxy(i,255);
delay(100); 
}
  }
  for (int i=0;i<5;i++){
 for (int i=0;i<4;i++){
 enciendeplanoxz(i,255);
delay(100); 
}
    for (int i=4;i>0;i--){
 enciendeplanoxz(i,255);
delay(100); 
    }
}

}
//Encender un led especificado por fila, columna y plano
//La intensidad depende del pin PWM
void enciendeled(int x, int y, int h, int intensidad){
//Apagamos todo el cubo
  for (int i=0;i<4;i++){

  digitalWrite(plano[i],HIGH);
}
//Encendemos el led
{
  digitalWrite(led[x][y],HIGH);
  analogWrite(plano[h],255-intensidad);
}
}
    void enciendefila(int x,  int h, int intensidad){
for (int i=0;i<4;i++){
  digitalWrite(plano[i],HIGH);
}
for (int i=0;i<4;i++){
  digitalWrite(led[x][i],HIGH);
}
  analogWrite(plano[h],255-intensidad);


}
    void enciendecolumna(int y,  int h, int intensidad){
for (int i=0;i<4;i++){
  digitalWrite(plano[i],HIGH);
}
for (int i=0;i<4;i++){
  digitalWrite(led[i][y],HIGH);
}
  analogWrite(plano[h],255-intensidad);

  
}
    void enciendepilar(int x,  int y, int intensidad){
for (int i=0;i<4;i++){
   analogWrite(plano[i],255-intensidad);
}

  digitalWrite(led[x][y],HIGH);



 


  
}
    void enciendeplanoxy(int h, int intensidad){
for (int p=0;p<4;p++){
  digitalWrite(plano[p],HIGH);
}
      for (int a=0;a<4;a++){
  for (int b=0;b<4;b++){
  digitalWrite(led[a][b],HIGH);
  }
}
   analogWrite(plano[h],255-intensidad);
;





    }
      void enciendeplanoxz(int h, int intensidad){
for (int p=0;p<4;p++){
analogWrite(plano[p],255-intensidad);
}
for (int a=0;a<4;a++){
 digitalWrite(led[0][a],HIGH);
}

      }
            void enciendeplanoyz(int h, int intensidad){
for (int p=0;p<4;p++){
analogWrite(plano[p],HIGH);
}
for (int a=0;a<4;a++){
 digitalWrite(led[a][0],HIGH);
}

      }
