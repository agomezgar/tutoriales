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
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("No se ha detectado GPS");
  lcd.setCursor(0,1);
  lcd.print("Compruebe conexiones");
    while(true);
  }
}

void displayInfo()
{
  lcd.clear();
  if (gps.location.isValid())
  {lcd.setCursor(0,0);
  lcd.print("Latitud: ");
  lcd.setCursor(9,0);
  lcd.print(gps.location.lat(),5);
  lcd.setCursor(0,1);
  lcd.print("Longitud: ");
  lcd.setCursor(10,1);
  lcd.print(gps.location.lng(),5);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("DATOS CORRUPTOS");
  }
lcd.setCursor(0,2);
lcd.print("Fecha: ");
lcd.setCursor(7,2);
  if (gps.date.isValid())
  {
    lcd.print(gps.date.day());
    lcd.print("/");
    lcd.print(gps.date.month());
    lcd.print("/");
    lcd.print(gps.date.year());
  }
  else
  {
    lcd.print("NO ENCONTRADA");
 
  }
  lcd.setCursor(0,3);
  lcd.print("Hora: ");
  lcd.setCursor(6,3);
  if (gps.time.isValid())
  {
    lcd.print(gps.time.hour());
    lcd.print(":");
    lcd.print(gps.time.minute());
    lcd.print(":");
    lcd.print(gps.time.second());

  }
  else
  {
   lcd.print("NO ENCONTRADA");
  }

}
