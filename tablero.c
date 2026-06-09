#include "tablero.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

Tablero* crear_tablero(int medida){
    Tablero *t = malloc(sizeof(Tablero));
    t -> medida = medida;
    t -> tablero= malloc(sizeof(int*) * medida);
    for(int i = 0; i<medida; i++){
        t -> tablero[i] = malloc(sizeof(int) * medida);
    }

    for(int i=0; i<medida; i++){
        for(int j=0; j<medida; j ++){
            t -> tablero[i][j]=0;
        }
    }
    return t;
}

Tablero* copiar_tablero(Tablero* t){
    Tablero* copia = crear_tablero(t->medida);
    for(int i=0; i<t->medida; i++){
        for(int j=0; j<t->medida; j ++){
           copia -> tablero[i][j] = t -> tablero[i][j];
        }
    }
    return copia;
}

void vaciar_tablero(Tablero* t){
    for(int i=0; i<(t->medida); i++){
        for(int j=0; j<(t->medida); j ++){
            t -> tablero[i][j]=0;
        }
    }
}

void destruir_tablero(Tablero* t){
    for(int i=0; i<(t->medida); i++){
        free(t->tablero[i]);
    }
    free(t->tablero);
    free(t);
}

void mostrar_tablero(Tablero* t){
    for(int i=0; i<(t->medida); i++){
        for(int j=0; j<(t->medida); j ++){
            printf("%i  ",t -> tablero[i][j]);
            if(j==(t->medida-1))
                printf("\n");
        }
    }
}

int ficha_aleatoria(){
    int nro = rand() % 4;
    if(nro<3)
        nro = 2;
    else
        nro = 4;
    return nro;
}

int hay_espacio(Tablero* t){
int vacias = 0;
for(int i=0; i<t->medida; i++)
    for(int j=0; j<t->medida; j++)
        if(t->tablero[i][j] == 0)
            vacias++;

if(vacias == 0)
    return 0;
else
    return 1;
}

void agregar_ficha(Tablero* t){
    if (!hay_espacio(t))
        return;
    int fila = rand() % t->medida;
    int cola = rand() % t->medida;

    if((t->tablero[fila][cola])==0)
        (t->tablero[fila][cola]) = ficha_aleatoria();
    else
        agregar_ficha(t);
}

