#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "tablero.h"
#include "juego.h"
#include "pilas.h"

int main(){
    srand(time(NULL));
    int medida=registrar_medida();
    Tablero* t = crear_tablero(medida);
    agregar_ficha(t);
    agregar_ficha(t);
    
    mostrar_tablero(t);
    char movimiento;
    int estado;

    PilaTableros* tableros_anteriores = crear_pila();

    while(1) {
        movimiento = registrar_movimiento();
        reaccion_al_movimiento(&t,movimiento,tableros_anteriores);
        if(victoria_derrota(t)==1)
            break;
   }
    
    destruir_tablero(t);
    return 0;
}