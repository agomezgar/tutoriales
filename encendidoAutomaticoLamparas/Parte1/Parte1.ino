void setup(){
Serial.begin(9600);
}
void loop(){
int valor=analogRead(A0);
Serial.println(valor);
delay(100);
}
