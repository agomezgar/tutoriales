#include <SoftwareSerial.h>
#include <OneWire.h>
#include "DHT.h"
#define DHTPIN 9
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);
OneWire ds(3);
char dato;
float h,t;
String readString;
// Swap RX/TX connections on bluetooth chip
//   Pin 10 --> Bluetooth TX
//   Pin 11 --> Bluetooth RX
SoftwareSerial mySerial(12, 13); // RX, TX
void setup() {
  // put your setup code here, to run once:
mySerial.begin(9600);
Serial.begin(9600);
dht.begin();
pinMode(11,OUTPUT);
digitalWrite(11,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
/*if (mySerial.available()>0){
char caracter=mySerial.read();
Serial.println(caracter);
if (caracter=='0'){
  digitalWrite(11,LOW);
}if (caracter=='1'){

  digitalWrite(11,HIGH);
}
}
*/

 LeerDato();
 //Serial.println(readString);
  if (readString.length() > 0){
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    if (readString == "Temp"){
      EnviarTemperatura();}
    if (readString == "Hum"){
      EnviarHumedad();}     
  }
      if (readString == "fuego"){
      EnviarLlama();}     
  }

 void LeerDato(){
  readString ="";
  while(mySerial.available()) {
    digitalWrite(11,HIGH);
    delay(10);
    if (mySerial.available() > 0) { //¿Hay datos en el buffer?
      dato = mySerial.read(); //Lee el dato
      readString += dato; //Lo almacena en readString
    }
  }
  digitalWrite(11,LOW);
}
 void EnviarTemperatura(){
  t = dht.readTemperature(); //Lee la temperatura
  if (isnan(t)){ //Comprueba que el dato es un número
    mySerial.print("Error");
  } else {
    mySerial.print(t); //Envía el dato por el puerto serie
  }
}

void EnviarHumedad()
{
  h = dht.readHumidity(); //Lee la humedad
  if (isnan(h)){ //Comprueba que el dato es un número
    mySerial.print("Error");
  } else {
    mySerial.print(h); //Envía el dato por el puerto serie
  }
}
void EnviarLlama(){
byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    //Serial.println("No more addresses.");
    //Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  
  //Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    //Serial.write(' ');
    //Serial.print(addr[i], HEX);
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return;
  }
  //Serial.println();
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
    //  Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      //Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
      //Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
      //Serial.println("Device is not a DS18x20 family device.");
      return;
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  //Serial.print("  Data = ");
  //Serial.print(present, HEX);
  //Serial.print(" ");
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
    //Serial.print(data[i], HEX);
    //Serial.print(" ");
  }
  //Serial.print(" CRC=");
  //Serial.print(OneWire::crc8(data, 8), HEX);
  //Serial.println();

  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;

 //Lee la temperatura
  if (isnan(celsius)){ //Comprueba que el dato es un número
    mySerial.print("Error");
  } else {
    mySerial.print(celsius); //Envía el dato por el puerto serie
  }
}

