//Empezamos en tres angulos de 90 º
int a1=90;
int a2=90;
int a3=90;
//Declaramos tres ángulos de lectura actual
int l1,l2,l3;
void setup(){
   pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT); 
 pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT);  
 pinMode(8,OUTPUT); 
  pinMode(9,OUTPUT); 
 pinMode(10,OUTPUT); 
 pinMode(11,OUTPUT); 
 pinMode(12,OUTPUT); 
  pinMode(13,OUTPUT); 

Serial.begin(9600);
}

void loop(){
  l1=map(analogRead(A0),0,1023,0,180);
    l2=map(analogRead(A1),0,1023,0,180);
      l3=map(analogRead(A2),0,1023,0,180);
  if (a1>l1){
giraIzquierda((a1-l1)*100);

a1=l1;
  }
    if (a1<l1){
giraDerecha((l1-a1)*100);

a1=l1;
  }
    if (a2>l2){
subeBrazo1((a2-l2)*100);

a2=l2;
  }
    if (a2<l2){
bajaBrazo1((l2-a2)*100);

a2=l2;
  }
      if (a3>l3){
subeBrazo2((a3-l3)*100);

a3=l3;
  }
    if (a3<l3){
bajaBrazo2((l3-a3)*100);

a3=l3;
  }
  Serial.println(l1);
if (Serial.available()){
char dato=Serial.read();
Serial.println(dato); 
if (dato=='p'){
  abrePinza();
}else if (dato=='l'){
  cierraPinza();
}
else if (dato=='d'){
  gd();
}
else if (dato=='a'){
  gi();
}
else if (dato=='w'){
  sb1();
}
else if (dato=='s'){
  bb1();
}
else if (dato=='o'){
  sb2();
}
else if (dato=='k'){
  bb2();
}
}
}
void gd(){
    digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(1500);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);  
}
void giraDerecha(int tiempo){
    digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(tiempo);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH); 
}

  void gi(){
    digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(1500);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);  
}
    void giraIzquierda(int tiempo){
    digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(tiempo);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);  
}

void sb1(){
    digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);  
}
void subeBrazo1(int tiempo){
    digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(tiempo);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);  
}
void bb1(){
    digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);  
}
void bajaBrazo1(int tiempo){
    digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(tiempo);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);  
}
void bb2(){
    digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);  
}
void bajaBrazo2(int tiempo){
    digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(tiempo);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);  
}
void sb2(){
    digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(1000);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);  
}
void subeBrazo2(int tiempo){
    digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(tiempo);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);  
}
void sb3(){
    digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);  
}
void bb3(){
    digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);  
}
void abrePinza(){
    digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);  
}
void cierraPinza(){
    digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);  
}


