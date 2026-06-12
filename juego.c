#include "tablero.h"
#include "juego.h"



void mover(int* linea,int medida){
    int pos=0;
    for(int i=0; i<medida; i++){
        if (linea[i]!=0){
            linea[pos]=linea[i];
            if(i!=pos)
                linea[i]=0;
            pos++;
        }
        
    } 
}

void fusionar(int* linea, int medida){
    for(int i=0; i<medida-1; i++){
        if(linea[i]==linea[i+1]){
            linea[i]=linea[i]*2;
            linea[i+1]=0;
            i++;
        }
    }
}

void mover_derecha(int* linea,int medida){
    int pos=medida-1;
    for(int i=medida-1; i>=0; i--){
        if (linea[i]!=0){
            linea[pos]=linea[i];
            if(i!=pos)
                linea[i]=0;
            pos--;
        }
        
    } 
}

void fusionar_derecha(int* linea, int medida){
    for(int i=medida-2; i>=0; i--){
        if(linea[i]==linea[i+1]){
            linea[i]=linea[i]*2;
            linea[i+1]=0;
            i++;
        }
    }
}

void mover_linea_izq(int* linea, int medida){
    mover(linea, medida);
    fusionar(linea, medida);
    mover(linea, medida);
}

void mover_linea_der(int* linea, int medida){
    mover_derecha(linea, medida);
    fusionar_derecha(linea, medida);
    mover_derecha(linea, medida);
}

void mover_tablero_izquierda(Tablero* t){
    for(int i=0; i<t->medida; i++){
        mover_linea_izq(t->tablero[i], t->medida);
    }
}


void mover_tablero_derecha(Tablero* t){
    for(int i=0; i<t->medida; i++){
        mover_linea_der(t->tablero[i], t->medida);
    }
}

void mover_tablero_arriba(Tablero* t){
    int columna_aux[t->medida];
    for(int i=0; i<t->medida; i++){
        for(int j=0; j<t->medida;j++){
            columna_aux[j] = t->tablero[j][i]; // aca cambio el j y el i para dejar fija la columna(j) y recorrer para abajo en vez de costado
        }
        mover_linea_izq(columna_aux, t->medida);
        for(int j=0; j<t->medida;j++){
            t->tablero[j][i] = columna_aux[j];
        }
    }
}

void mover_tablero_abajo(Tablero* t){
    int columna_aux[t->medida];
    for(int i=0; i<t->medida; i++){
        for(int j=0; j<t->medida;j++){
            columna_aux[j] = t->tablero[j][i];
        }
        mover_linea_der(columna_aux, t->medida);
        for(int j=0; j<t->medida;j++){
            t->tablero[j][i] = columna_aux[j];
        }
    }
}

int hay_jugadas_posibles(Tablero* t){
    for(int i = 0; i<t->medida; i++){
        for(int j = 0; j<t->medida; j++){
            if (i < t->medida-1 && t->tablero[i][j] == t->tablero[i+1][j])
                return 1;
            if (j < t->medida-1 && t->tablero[i][j] == t->tablero[i][j+1])
                return 1;
        }
    }
    return 0;
}


int juego_perdido(Tablero *t){
    if(!hay_espacio(t) && !hay_jugadas_posibles(t))
        return 1;
    else 
        return 0;
}

int juego_ganado(Tablero *t){
    for(int i = 0; i<t->medida; i++){
        for(int j = 0; j<t->medida; j++){
            if (t->tablero[i][j] == 2048)
                return 1;
        }
    }
    return 0;
}

int estado_juego(Tablero *t){
    if(juego_ganado(t))
        return 1;
    else if(juego_perdido(t))
        return -1;
    else
        return 0;
}

int victoria_derrota(Tablero* t){
    int estado = estado_juego(t);
    if(estado==1){
        printf("\n");
        printf("FELICIDADES HAZ CONSEGUIDO 2048");
        printf("\n");
        return 1;
    }
    else if(estado==-1){
        printf("\n");
        printf("HAZ PERDIDO");
        printf("\n");
        return 1;
    }
    return 0;
}

char registrar_movimiento(){
    char movimiento;
    printf("Ingrese el movimiento (w/a/s/d/u): ");
    scanf(" %c", &movimiento);
    return movimiento;
}

void reaccion_al_movimiento(Tablero** t, char movimiento,PilaTableros* tableros_anteriores){
        int es_u=0;

        if(movimiento == 'w') {
            apilar(tableros_anteriores,*t);
            mover_tablero_arriba(*t);
        } else if (movimiento == 'a') {
            apilar(tableros_anteriores,*t);
            mover_tablero_izquierda(*t);
        } else if (movimiento == 's') {
            apilar(tableros_anteriores,*t);
            mover_tablero_abajo(*t);
        } else if (movimiento == 'd') {
            apilar(tableros_anteriores,*t);
            mover_tablero_derecha(*t);
        } else if (movimiento == 'u'){
            destruir_tablero(*t);
            *t = desapilar(tableros_anteriores);
            es_u=1;
        } else {
            printf("Movimiento no válido.\n");
        }

        if(!es_u){
            agregar_ficha(*t);
        }

        printf("\n");
        mostrar_tablero(*t);
        printf("\n");
}

int registrar_medida(){
    int medida;
    printf("Ingrese la medida del tablero: ");
    scanf("%i", &medida);
    return medida;
}