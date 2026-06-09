#ifndef TABLERO_H
#define TABLERO_H


typedef struct{
    int** tablero;
    int medida;
}Tablero;


Tablero* crear_tablero(int medida);
Tablero* copiar_tablero(Tablero* t);
int ficha_aleatoria();
int hay_espacio(Tablero* t);
void vaciar_tablero(Tablero* t);
void destruir_tablero(Tablero* t);
void mostrar_tablero(Tablero* t);
void agregar_ficha(Tablero* t);

#endif
