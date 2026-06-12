# Nombre del ejecutable final
TARGET = juego2048

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -I.

# Archivos objeto (creados a partir de los .c)
OBJ = main.o juego.o pilas.o tablero.o

# Regla principal
all: $(TARGET)

# Cómo compilar el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Reglas para compilar cada archivo fuente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean