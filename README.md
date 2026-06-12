# Juego 2048 en C

Implementación del juego 2048 en C con tablero de medida configurable y función de undo.


## Compilación
make -> Compila el código.

## Uso
./juego2048

## Limpieza 
make clean -> Borra los archivos que se crearon de manera temporal.


## Controles
- w: mover arriba
- a: mover izquierda
- s: mover abajo
- d: mover derecha
- u: deshacer último movimiento

## Estructura
- tablero.c/h: estructura del tablero y operaciones básicas
- juego.c/h: lógica del juego y movimientos
- pilas.c/h: pila para el undo
- main.c: loop principal
