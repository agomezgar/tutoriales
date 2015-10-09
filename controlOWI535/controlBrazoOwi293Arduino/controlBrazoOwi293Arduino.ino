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
  void gi(){
    digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(1500);
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
void bb1(){
    digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(1000);
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
void sb2(){
    digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(1000);
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


