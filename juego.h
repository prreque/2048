#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"

void mover(int* linea, int medida);
void fusionar(int* linea, int medida);
void mover_linea_izq(int* linea, int medida);
void invertir(int* linea, int medida);
void mover_tablero_izquierda(Tablero* t);
void mover_tablero_derecha(Tablero* t);
void mover_tablero_arriba(Tablero* t);
void mover_tablero_abajo(Tablero* t);
int hay_jugadas_posibles(Tablero* t);
int juego_perdido(Tablero* t);
int juego_ganado(Tablero *t);
int estado_juego(Tablero *t);
#endif