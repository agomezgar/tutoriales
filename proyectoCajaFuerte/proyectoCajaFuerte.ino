int p1=8;
int p2=9;
int p3=10;
int p4=11;
int verde=7;
int rojo=6;
int valor=0;
boolean paso1=false;
boolean paso2=false;
boolean paso3=false;
boolean paso4=false;
void setup(){
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(p4,INPUT);
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
Serial.begin(9600);


}

void loop(){
leerValor(); 
if (valor==0){
  digitalWrite(rojo,HIGH);
digitalWrite(verde,LOW);
}
  if (valor==1){
   if (paso1==false){
    paso1=true;

   } else{

digitalWrite(rojo,HIGH);
digitalWrite(verde,LOW);
   }
    
  }
  if (valor==2){
    if (paso1==true){
   paso2=true; 
  }else{
    paso1=false;
    paso2=false;
 digitalWrite(rojo,HIGH);
digitalWrite(verde,LOW);
    
  }
  }
  if (valor==3){
    if (paso2==true){
     paso3=true; 
    }else{
      paso1=false;
      paso2=false;
      paso3=false;
digitalWrite(rojo,HIGH);
digitalWrite(verde,LOW);
      
    }
    
    
  }
  if (valor==4){
    if (paso3==true){
     paso4=true; 
    }else{
      paso1=false;
      paso2=false;
      paso3=false;
      paso4=false;
digitalWrite(rojo,HIGH);
digitalWrite(verde,LOW);  
    }
    
    
  }
  if (paso4==true){
   digitalWrite(rojo,LOW);
  digitalWrite(verde,HIGH); 
  }
  Serial.print(paso1);
  Serial.print("\t");
  Serial.print(paso2);
  Serial.print("\t");
  Serial.print(paso3);
  Serial.print("\t");
  Serial.print(paso4);
  Serial.print("\t");
  Serial.println(valor);  
  
 
}
void leerValor(){
   if (digitalRead(p1)==1){
   valor=1;
  }else
  if (digitalRead(p2)==1){
   valor=2;
  }
  if (digitalRead(p3)==1){
   valor=3;
  }
  if (digitalRead(p4)==1){
   valor=4;
  }   
}
