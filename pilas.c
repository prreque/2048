#include<stdlib.h>

#include "pilas.h"





PilaTableros* crear_pila(){
    PilaTableros* tableros_anteriores=malloc(sizeof(PilaTableros));
    tableros_anteriores->tope=NULL;
    return tableros_anteriores;
}

PilaTableros* apilar(PilaTableros* tableros_anteriores, Tablero* t){
    Nodo* nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->tablero=copiar_tablero(t);
    nuevo_nodo->siguiente=tableros_anteriores->tope;
    tableros_anteriores->tope=nuevo_nodo;
    return tableros_anteriores;
} 

Tablero* desapilar(PilaTableros* tableros_anteriores){
    Nodo* nodo_viejo = tableros_anteriores->tope;
    Tablero* tablero_desapilado = nodo_viejo->tablero;
    tableros_anteriores->tope = nodo_viejo->siguiente;
    free(nodo_viejo);
    return tablero_desapilado;
}

