#include "pitches.h"
int ledPin=13;
boolean ledState=false;
int val=0;
void setup() 
{
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  //initialize serial communications at a 9600 baud rate
  Serial.begin(9600);
  establishContact();  // send a byte to establish contact until receiver responds 
}
void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

    if(val == '1') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_C3,200);
    }
        if(val == '2') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_D3,200);
    }
        if(val == '3') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_E3,200);
    }
        if(val == '4') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_F3,200);
    }
        if(val == '5') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_G3,200);
    }
        if(val == '6') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_A3,200);
    }
        if(val == '7') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_B31,200);
    }
        if(val == '8') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
       tone(8,NOTE_C4,200);
    }
    delay(100);
  } 
    else {
    Serial.println("Hello, world!"); //send back a hello world
    delay(50);
    }
}
void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}

