/***   Included libraries  ***/
#include <BitbloqZowi.h>
#include <BitbloqUS.h>
#include <BitbloqBatteryReader.h>
#include <BitbloqLedMatrix.h>
#include <Servo.h>
#include <BitbloqOscillator.h>
#include <EEPROM.h>


/***   Global variables and function definition  ***/
Zowi zowi;

/***   Setup  ***/
void setup() {
    zowi.init();
    zowi.home();
}

/***   Loop  ***/
void loop() {
    if (zowi.getDistance() < 15) {
        zowi.playGesture(ZowiConfused);
        zowi.turn(6,500,RIGHT);
        zowi.walk(4,2000,BACKWARD);
    }else{
    zowi.walk(1,2000,FORWARD);
    }
}
