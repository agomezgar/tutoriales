/* Masaylo.h – Descripción de la librería
Creada por Autor, Fecha
Lanzada bajo licencia…*/
#ifndef Masaylo_h
#define Masaylo_h
#include "Arduino.h"

class Masaylo{

public:
Masaylo();
void adelante(int tiempo);
void atras(int tiempo);
void izquierda(int tiempo);
void derecha(int tiempo);
void paro (int tiempo);
private:
int pin;
};
#endif