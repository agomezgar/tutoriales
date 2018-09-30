/* Ping))) Sensor
  
   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
     
   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping
   
   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
 
   This example code is in the public domain.

 */
#include <Castilla.h>

//We need this library for playing sound
#include <SoundWave.h>

//Declare the sound player
SoundWave player;

float multiplier=0.8;
// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin = 7;
const int boton=8;
const int led=13;
  long duration, cm;
  int centenas,decenas,unidades;
boolean pulsado;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  player.begin();
  pinMode(boton,INPUT);
  pinMode(led,OUTPUT);
  pulsado=false;
  player.play("saludos.wav");
    player.setSampleRate(player.dwSamplesPerSec*multiplier);
}

void loop()

{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
 
  cm = microsecondsToCentimeters(duration);
  centenas=cm/100;
  decenas=(cm%100)/10;
  unidades=((cm%10)%10);
 
  Serial.print(centenas);
  Serial.print(",");
  Serial.print(decenas);
  Serial.print(" ,");
  Serial.print(unidades);
  Serial.print(" cm");
  Serial.println();
  
  if (digitalRead(boton)==HIGH){
    pulsado=true;}
    if (pulsado){
         cantadistancia();
	cantacentenas(centenas);
        cantadecenas(decenas);
        cantaunidades(unidades);


player.play("cm.wav");
  player.setSampleRate(player.dwSamplesPerSec*multiplier);
  while(player.isplaying){
	}  
pulsado=false;
    }
  
  if (cm<30){
    player.play("obstacul.wav");
  }   
   player.setSampleRate(player.dwSamplesPerSec*multiplier);
  while(player.isplaying){
	
    //setSampleRate(SampleRate)
    //  SampleRate: how fast the sound is played. Normally
    //    	it's based on original sample rate, 
    //		thus "player.dwSamplesPerSec*multiplier."
    //
    //		"multiplier" is a float point number, 
    //          typically between 0.5 and 2
    //
    //Change the sample rate during playback. Make it sounds
    //funny. It's not necessary for playing a sound.
    player.setSampleRate(player.dwSamplesPerSec*multiplier);

    delay(30);
  }
  delay(100);
}
void cantadistancia(){
      player.play("distanci.wav");
        player.setSampleRate(player.dwSamplesPerSec*multiplier);
 while(player.isplaying){
   
 }
}
void cantacentenas(int centenas){
  switch(centenas){
  case 1:
  player.play("ciento.wav");
  break;
    case 2:
  player.play("doscient.wav");
  break;
    case 3:
  player.play("trescien.wav");
  break;
}
  player.setSampleRate(player.dwSamplesPerSec*multiplier);
while(player.isplaying){
	}
}
  void cantadecenas(int decenas){
   switch(decenas){
  case 1:
  player.play("diez.wav");

  break;
  case 2:
  player.play("veinte.wav");
  break;
    case 3:
  player.play("treinta.wav");
  break;
    case 4:
  player.play("cuarenta.wav");
  break;
    case 5:
  player.play("cincuent.wav");
  break;
    case 6:
  player.play("sesenta.wav");
  break;
    case 7:
  player.play("setenta.wav");
  break;
    case 8:
  player.play("ochenta.wav");
  break;
    case 9:
  player.play("noventa.wav");
  break;
} 
  player.setSampleRate(player.dwSamplesPerSec*multiplier);
  while(player.isplaying){
	}  
  }
void cantaunidades(int unidades){
 switch(unidades){
  case 1:
  player.play("uno.wav");
  break;
  case 2:
  player.play("dos.wav");
  break;
    case 3:
  player.play("tres.wav");
  break;
    case 4:
  player.play("cuatro.wav");
  break;
    case 5:
  player.play("cinco.wav");
  break;
    case 6:
  player.play("seis.wav");
  break;
    case 7:
  player.play("siete.wav");
  break;
    case 8:
  player.play("ocho.wav");
  break;
    case 9:
  player.play("nueve.wav");
  break;
} 
  player.setSampleRate(player.dwSamplesPerSec*multiplier);
    while(player.isplaying){
	}  
}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
