#include <LiquidCrystal_I2C.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h> 


LiquidCrystal_I2C lcd(0x27,20,4); 
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
int lectura;
void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Segundo PMAR");
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();lectura=0;
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
    lectura++;
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("No se ha detectado GPS");
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(lectura);
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {lcd.setCursor(0,0);
  lcd.print("Latitud: ");
  lcd.setCursor(10,0);
  lcd.print(gps.location.lat(),5);
  lcd.setCursor(0,1);
  lcd.print("Longitud: ");
  lcd.setCursor(11,1);
  lcd.print(gps.location.lng(),5);
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DATOS CORRUPTOS");
  }
lcd.setCursor(0,2);
lcd.print("Fecha: ");
lcd.setCursor(8,3);
  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    lcd.print(gps.date.day());
    lcd.print(":");
    lcd.print(gps.date.month());
    lcd.print(":");
    lcd.print(gps.date.year());
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    lcd.print("INVALIDO");
    Serial.print(F("INVALID"));
  }
  lcd.setCursor(0,3);
  lcd.print("Hora: ");
  lcd.setCursor(6,4);
  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    lcd.print(gps.time.hour());
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
