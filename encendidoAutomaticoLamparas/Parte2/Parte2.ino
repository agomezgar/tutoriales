void setup(){
//Mantenemos el puerto serie con fines de depuración
Serial.begin(9600);
//Preparamos la entrada 8 para que funcione como salida
pinMode(8,OUTPUT);
}
void loop(){
int valor=analogRead(A0);
Serial.println(valor);
if (valor>750){
digitalWrite(8,HIGH);
}else{
digitalWrite(8,LOW);
}
delay(100);
}
