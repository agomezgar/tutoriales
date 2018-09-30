//Definimos las variables que delimitarán el mínimo y el máximo
//correspondiente a cada color
int menorBlanco=875;
int mayorBlanco=950;
int menorNegro=39;
int mayorNegro=70;
int menorRojo=433;
int mayorRojo=483;
int menorVerde=650;
int mayorVerde=687;
int menorAzul=1000;
int mayorAzul;
int sensor1 = A0;  
int sensor2=A1;
int sensor3=A2;
int sensor4=A3;
int sensorValue1 = 0;
int sensorValue2=0;
int sensorValue3=0;
int sensorValue4=0;
//He puesto el pulsador en la patilla 7
int pulsador=7;
//Al configurar, cuentaPulsaciones lleva la cuenta del color
//que estamos midiendo (de momento, 0 para blanco, 1 para negro,
//2 para verde, 3 para rojo... se pueden añadir más colores
int cuentaPulsaciones=0;
//La variable promedio recoge la media de la lectura de 
//las cuatro lecturas analógicas de cada CNY70
int promedio=0;
char val;
void setup() {

 
  Serial.begin(9600);
  pinMode(pulsador,INPUT);

 // configuraSensor();
   establishContact();
}

void loop() {
 while(!digitalRead(pulsador)){
 //Leemos un valor entre 0 y 1023 de cada sensor CNY70
 //y hacemos la cuenta.
  sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
  if (Serial.available() > 0) {
                // read the incoming byte:
               val= Serial.read();
  if (val='1'){
    detectaColor(promedio);
  }
                
              
        }
//la función detectaColor recoge el valor promedio y detecta
//a qué color corresponde

 }
// configuraSensor();
      
}

void detectaColor(int promedio){
if((menorBlanco*0.9<promedio)&&(promedio<mayorBlanco*1.1)){
//Serial.println("Color detectado: blanco");
Serial.write("b");
 
}
if((menorNegro*0.9<promedio)&&(promedio<mayorNegro*1.1)){
//Serial.println("Color detectado: negro");
  Serial.write("n");

}
if((menorVerde*0.9<promedio)&&(promedio<mayorVerde*1.1)){
//Serial.println("Color detectado: verde");
  Serial.write("v");
 
}
if((menorRojo*0.9<promedio)&&(promedio<mayorRojo*1.1)){
Serial.write("r");
  //Serial.println("Color detectado: rojo");
 
}
/*
if((menorAzul*0.9<promedio)&&(promedio<mayorAzul*1.1)){
Serial.println("Color detectado: azul");
  delay(100);
  
}
*/
delay(100);
}

//La función configuraSensor va recogiendo valores mínimo y máximo para
//cada color durante el tiempo que estemos pulsando...
 void configuraSensor(){
  switch (cuentaPulsaciones){
   case 0:
     while(!digitalRead(pulsador)){
 Serial.println("Pulse boton para blanco...");
delay(100);
  }
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color blanco...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menorBlanco){
  menorBlanco=promedio;
}
if (promedio>mayorBlanco){
 mayorBlanco=promedio;
}
   
  }
   
 
  cuentaPulsaciones++;
  configuraSensor();
  break;
   case 1:
     while(!digitalRead(pulsador)){
 Serial.println("Pulse boton para negro...");
delay(100);
  }
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color negro...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menorNegro){
  menorNegro=promedio;
}
if (promedio>mayorNegro){
 mayorNegro=promedio;
}
   
  };
   
 
  cuentaPulsaciones++;
  configuraSensor();
  break;
     case 2:
     while(!digitalRead(pulsador)){
 Serial.println("Pulse boton para verde...");
delay(100);
  }
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color verde...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menorVerde){
  menorVerde=promedio;
}
if (promedio>mayorVerde){
 mayorVerde=promedio;
}
   
  };
   
 
  cuentaPulsaciones++;
  configuraSensor();
  break;
   
   /*   case 3:
     while(!digitalRead(pulsador)){
 Serial.println("Pulse boton para azul...");
delay(100);
  }
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color azul...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menorAzul){
  menorAzul=promedio;
}
if (promedio>mayorAzul){
 mayorAzul=promedio;
}
   
  };
   
 
  cuentaPulsaciones++;
  configuraSensor();
  break;
  */
     case 3:
     while(!digitalRead(pulsador)){
 Serial.println("Pulse boton para rojo...");
delay(100);
  }
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color rojo...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menorRojo){
  menorRojo=promedio;
}
if (promedio>mayorRojo){
 mayorRojo=promedio;
}
   
  }
   
 
  cuentaPulsaciones++;
  Serial.println("Valores para: blanco");
  Serial.print(menorBlanco);
  Serial.print("\t");
  Serial.println(mayorBlanco);
  delay(2000);
  Serial.println("Valores para: negro");
  Serial.print(menorNegro);
  Serial.print("\t");
  Serial.println(mayorNegro);
  delay(2000);
    Serial.println("Valores para: verde");
  Serial.print(menorVerde);
  Serial.print("\t");
  Serial.println(mayorVerde);
  delay(2000);
  /*
    Serial.println("Valores para: azul");
  Serial.print(menorAzul);
  Serial.print("\t");
  Serial.println(mayorAzul);
  delay(2000); 
  */
  Serial.println("Valores para: rojo");
  Serial.print(menorRojo);
  Serial.print("\t");
  Serial.println(mayorRojo);
  delay(2000); 
  Serial.flush();
  break;
}
 }
 void asignaValores(int menor,int mayor){
     while(digitalRead(pulsador)){
  Serial.println("Escaneando color...");
    sensorValue1 = analogRead(sensor1);  
    sensorValue2 = analogRead(sensor2);  
      sensorValue3 = analogRead(sensor3);  
        sensorValue4 = analogRead(sensor4);  
Serial.print(sensorValue1);              
Serial.print("\t");
Serial.print(sensorValue2);              
Serial.print("\t");
Serial.print(sensorValue3);              
Serial.print("\t");
Serial.print(sensorValue4);              
promedio=(sensorValue1+sensorValue2+sensorValue3+sensorValue4)/4;
Serial.print("\t");
Serial.print(promedio);
Serial.print("\n");
if (promedio<menor){
  menor=promedio;
}
if (promedio>mayor){
 mayor=promedio;
}
   
  }
 }
 void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}
