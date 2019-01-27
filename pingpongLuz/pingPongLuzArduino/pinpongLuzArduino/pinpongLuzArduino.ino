int sensorPin = A0;    // select the input pin for the potentiometer
int sensorPin2=A2;
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2=0;
int valor1=0;//variable to send to Processing
int valor2=0;
int inByte=0;
void setup() {
 
  Serial.begin(9600);
  establishContact();
}

void loop() {
   if (Serial.available() > 0) {
 // get incoming byte:
 inByte = Serial.read();
 // read first analog input, divide by 4 to make the range 0-255:
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  delay(10);
  sensorValue2 = analogRead(sensorPin2); 
  valor1=map(sensorValue, 0,1023,0,255);
  valor2=map(sensorValue2, 0,1023,0,255);
  
 Serial.write(valor1);

Serial.write(valor2);


delay(10);
}
}
void establishContact() {
 while (Serial.available() <= 0) {
 Serial.print('A'); // send a capital A
 delay(300);
 }
}

