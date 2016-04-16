int sensorPin = A0;    // select the input pin for the potentiometer
int sensorPin2=A1;
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2=0;
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
 Serial.write(sensorValue/4);

Serial.write(sensorValue2/4);

  // turn the ledPin on
  /*
  Serial.write('a');
  delay(10);
    byte         sendAnalog=sensorValue*0.24926697;
        Serial.write(sendAnalog);
        delay(10);
        Serial.write('b');
    byte         sendAnalog2=sensorValue2*0.24926697;
        Serial.write(sendAnalog2);       
*/
delay(10);
}
}
void establishContact() {
 while (Serial.available() <= 0) {
 Serial.print('A'); // send a capital A
 delay(300);
 }
}


