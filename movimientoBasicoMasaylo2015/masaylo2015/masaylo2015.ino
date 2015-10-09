void setup(){
  
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT); 
}

void loop(){
  adelante(3000);
  izquierda(2000);
  derecha(1000);
  atras(3000);
 
}
void atras(int tiempo){
      digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
 delay(tiempo); 
  
}
void paro(int tiempo){
      digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
 delay(tiempo); 
  
}
void adelante(int tiempo){
      digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH); 
  delay(tiempo);
}
void izquierda(int tiempo){
      digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW); 
  delay(tiempo);
}
void derecha(int tiempo) {
        digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH); 
  delay(tiempo);
  
}
void aleatorio(){
  int var=(int)random(4);
  switch (var){
    case 0:
    adelante(random(5000));
   
    break;
    case 1:
    izquierda(random(5000));
   
    break;
    case 2:
    derecha(random(5000));
    
    break;
    case 3:
    atras(random(5000));

    break;    
  }
}
