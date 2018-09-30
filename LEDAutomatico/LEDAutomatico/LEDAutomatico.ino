int lectura;
int led=8;
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
lectura=analogRead(A0);
if (lectura>700){
  digitalWrite(led,HIGH);
}else{
digitalWrite(led,LOW);
}

delay(100);
}
