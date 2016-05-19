#include <Servo.h>

Servo servos[13];

/***   Global variables   ***/
int obs_Left=0;
int obs_Center=0;
int obs_Right=0;
int angle_Left=110;
int angle_Right=50;
int angle_Center=80;

/***   Function declaration   ***/
void go_Fordward ();
void turn_Left ();
void turn_Right ();
void Stop ();
void go_Backward ();
//bqBAT
long TP_init(int trigger_pin, int echo_pin);
long Distance(int trigger_pin, int echo_pin);
int search_Obstacle (int angle);

void setup()
{




  servos[8].attach(9);

  servos[9].attach(10);

  servos[11].attach(11);

  pinMode( 4 , INPUT );

  pinMode( 5 , OUTPUT );

}


void loop()
{
  Stop();
  obs_Left=search_Obstacle(angle_Left);
  delay(300);
  obs_Right=search_Obstacle(angle_Right);
  delay(300);
  obs_Center=search_Obstacle(angle_Center);
  delay(300);
  if (obs_Center == 0) {
    go_Fordward();
   }else if (obs_Left == 0) {
    turn_Left();
   }else if (obs_Right == 0) {
    turn_Right();
   }else {
    go_Backward();
    delay(800);
    Stop();
    delay(500);
    turn_Left();
   }
  delay(800);

}

/***   Function definition   ***/
void go_Fordward () {
  tone(12,329,100);
  delay(100);
  tone(12,392,100);
  delay(100);
  tone(12,494,100);
  delay(100);
  servos[8].write(0);
  delay(20);
  servos[9].write(180);
  delay(20);
 }
void turn_Left () {
  servos[8].write(90);
  delay(20);
  servos[9].write(180);
  delay(20);
 }
void turn_Right () {
  servos[8].write(0);
  delay(20);
  servos[9].write(90);
  delay(20);
 }
void Stop () {
  servos[8].write(90);
  delay(20);
  servos[9].write(90);
  delay(20);
 }
void go_Backward () {
  tone(12,261,100);
  delay(100);
  delay(200);
  tone(12,293,100);
  delay(100);
  delay(200);
  tone(12,261,300);
  delay(300);
  delay(200);
  // Miniservo
  servos[11].write(angle_Right);
  delay(300);
  // Miniservo
  servos[11].write(angle_Left);
  delay(300);
  // Miniservo
  servos[11].write(angle_Right);
  delay(300);
  // Miniservo
  servos[11].write(angle_Left);
  delay(300);
  // Miniservo
  servos[11].write(angle_Center);
  delay(300);
  servos[8].write(180);
  delay(20);
  servos[9].write(0);
  delay(20);
 }
//bqBAT
long TP_init(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long microseconds = pulseIn(echo_pin ,HIGH);
  return microseconds;
}
long Distance(int trigger_pin, int echo_pin)
{
  long microseconds = TP_init(trigger_pin, echo_pin);
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
int search_Obstacle (int angle) {
  // Miniservo
  servos[11].write(angle);
  delay(300);
  int distance=Distance(5,4);
  if (distance < 25) {
    tone(12,261,300);
    delay(300);
      return (1);
   }else {
    tone(12,329,100);
    delay(100);
   }

  return 0;
 }
