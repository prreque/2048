#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "tablero.h"
#include "juego.h"
#include "pilas.h"

int main(){
    srand(time(NULL));
    int medida;
    printf("Ingrese la medida del tablero: ");
    scanf("%i", &medida);
    Tablero* t = crear_tablero(medida);
    agregar_ficha(t);
    agregar_ficha(t);
    
    mostrar_tablero(t);
    char movimiento;
    int estado;

    PilaTableros* tableros_anteriores = crear_pila();

   while(1) {
        printf("Ingrese el movimiento (w/a/s/d/u): ");
        scanf(" %c", &movimiento);
        int es_u=0;

        if(movimiento == 'w') {
            apilar(tableros_anteriores,t);
            mover_tablero_arriba(t);
        } else if (movimiento == 'a') {
            apilar(tableros_anteriores,t);
            mover_tablero_izquierda(t);
        } else if (movimiento == 's') {
            apilar(tableros_anteriores,t);
            mover_tablero_abajo(t);
        } else if (movimiento == 'd') {
            apilar(tableros_anteriores,t);
            mover_tablero_derecha(t);
        } else if (movimiento == 'u'){
            destruir_tablero(t);
            t = desapilar(tableros_anteriores);
            es_u=1;
        } else {
            printf("Movimiento no válido.\n");
        }

        if(!es_u){
            agregar_ficha(t);
        }

        printf("\n");
        mostrar_tablero(t);
        printf("\n");
        estado = estado_juego(t);

        if(estado == 1) {
            printf("¡Has ganado!\n");
            break;
        } else if (estado == -1) {
            printf("¡Has perdido!\n");
            break;
        }
   }
    
    
    destruir_tablero(t);
    return 0;
}