int rojo=9;
int verde=10;
int azul=11;
int lRojo,lVerde,lAzul,eRojo,eVerde,eAzul;

void setup(){
}

void loop(){

  lRojo=analogRead(A0);
  lVerde=analogRead(A1);
  lAzul=analogRead(A2);
  eRojo=map(lRojo,0,1023,0,255);
  eVerde=map(lVerde,0,1023,0,255);
  eAzul=map(lAzul,0,1023,0,255);
 analogWrite(rojo,eRojo); 
 analogWrite(azul,eAzul);
 analogWrite(verde,eVerde);

  }


