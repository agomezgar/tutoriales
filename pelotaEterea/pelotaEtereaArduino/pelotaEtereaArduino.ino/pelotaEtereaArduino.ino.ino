int lectura;
int val;
void setup() 
{

  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

    if(val == '1') //if we get a 1
    {
   //espero a que deje de escribir 1
    }
    delay(100);
  } 
    else {
      lectura=analogRead(A0);
    Serial.write(lectura/4); //send back a hello world
    delay(50);
    }
}

