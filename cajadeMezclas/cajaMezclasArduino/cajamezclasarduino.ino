int b1,b2,b3,b4,b5;
void setup(){
  b1=2;
  b2=3;
  b3=4;
  b4=5;
  b5=6;
  Serial.begin(9600);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
     
  
  
}

void loop(){
  if (digitalRead(b1)==HIGH){
    Serial.write("a");
    delay(1000);
  }
  if (digitalRead(b2)==HIGH){
    Serial.write("b");
    delay(1000);
  }
  if (digitalRead(b3)==HIGH){
    Serial.write("c");
    delay(1000);
  }
  if (digitalRead(b4)==HIGH){
    Serial.write("d");
    delay(1000);
  }
  if (digitalRead(b5)==HIGH){
    Serial.write("g");
    delay(1000);
  }

}
