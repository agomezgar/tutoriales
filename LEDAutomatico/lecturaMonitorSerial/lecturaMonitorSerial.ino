int lectura;

void setup() {
Serial.begin(9600);

}

void loop() {
lectura=analogRead(A0);
Serial.println(lectura);

delay(100);
}
