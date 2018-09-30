int sIzquierda,sDerecha;
int lIzquierda=8;
int lDerecha=9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lIzquierda,OUTPUT);
pinMode(lDerecha,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sIzquierda=analogRead(A0);
sDerecha=analogRead(A1);
if (sIzquierda>800){
  digitalWrite(lIzquierda,HIGH);
  Serial.write(1);
}else{
  digitalWrite(lIzquierda,LOW);
}
if (sDerecha>800){
  digitalWrite(lDerecha,HIGH);
  Serial.write(2);
}else{
  digitalWrite(lDerecha,LOW);
}

delay(100);
}
