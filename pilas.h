#ifndef PILAS_H
#define PILAS_H

#include "tablero.h"
#include "juego.h"

typedef struct Nodo {
    Tablero* tablero;     
    struct Nodo* siguiente; 
} Nodo;

typedef struct {
    Nodo* tope;           
} PilaTableros;


PilaTableros* crear_pila();
PilaTableros* apilar(PilaTableros* tableros_anteriores, Tablero* t);
Tablero* desapilar(PilaTableros* tableros_anteriores);

#endif