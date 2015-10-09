/*
  Masaylo.cpp - Descripción libreria
Creada por Autor, Fecha
Lanzado bajo licencia...
*/
#include "Arduino.h"

#include "Masaylo.h"
Masaylo::Masaylo()
{
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}
 
void Masaylo::adelante(int tiempo)
{
 digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
delay(tiempo);
 }
void Masaylo::atras(int tiempo)
{
 digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
delay(tiempo);
 }
void Masaylo::paro(int tiempo)
{
 digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
 delay(tiempo);
}
void Masaylo::derecha(int tiempo)
{
 digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
 delay(tiempo);
}
void Masaylo::izquierda(int tiempo)
{
 digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
 delay(tiempo);
}