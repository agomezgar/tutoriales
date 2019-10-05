#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

// create array
int incoming[2];

void setup(){
  Serial.begin(9600);

  servo0.attach(9);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
}

void loop(){
  while(Serial.available() >= 3){
    // fill array
    for (int i = 0; i < 3; i++){
      incoming[i] = Serial.read();
    }
    // use the values
    servo0.write(incoming[0]);
    servo1.write(incoming[1]);
    servo2.write(incoming[2]);
    if (incoming[2]>90){
      servo3.write(90);
    }else{
      servo3.write(180);
    }
  }
}
