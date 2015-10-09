int azul=2;
int rosa=3;
int amarillo=4;
int naranja=5;
void setup(){
 pinMode(azul,OUTPUT); 
 pinMode(rosa,OUTPUT); 
 pinMode(amarillo,OUTPUT); 
 pinMode(naranja,OUTPUT); 
 digitalWrite(azul,LOW);
 digitalWrite(rosa,LOW);
 digitalWrite(amarillo,LOW);
 digitalWrite(naranja,LOW);
 
}
void loop(){
	//PASO 1
  digitalWrite(azul,LOW);
  digitalWrite(rosa,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(naranja,HIGH);
  delayMicroseconds(2000);


//PASO 2
  digitalWrite(azul,LOW);
  digitalWrite(rosa,LOW);
  digitalWrite(amarillo,HIGH);
  digitalWrite(naranja,HIGH);
  delayMicroseconds(2000);
//PASO 3
  digitalWrite(azul,LOW);
  digitalWrite(rosa,LOW);
  digitalWrite(amarillo,HIGH);
  digitalWrite(naranja,LOW);
  delayMicroseconds(2000);
//PASO 4
  digitalWrite(azul,LOW);
  digitalWrite(rosa,HIGH);
  digitalWrite(amarillo,HIGH);
  digitalWrite(naranja,LOW);
  delayMicroseconds(2000);
//PASO 5
  digitalWrite(azul,LOW);
  digitalWrite(rosa,HIGH);
  digitalWrite(amarillo,LOW);
  digitalWrite(naranja,LOW);
  delayMicroseconds(2000);
//PASO 6
  digitalWrite(azul,HIGH);
  digitalWrite(rosa,HIGH);
  digitalWrite(amarillo,LOW);
  digitalWrite(naranja,LOW);
  delayMicroseconds(2000);

//PASO 7
  digitalWrite(azul,HIGH);
  digitalWrite(rosa,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(naranja,LOW);
  delayMicroseconds(2000);
//PASO 8
  digitalWrite(azul,HIGH);
  digitalWrite(rosa,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(naranja,HIGH);
  delayMicroseconds(2000);
}
