CC = gcc
CFLAGS = -Wall -I$(INC)
OBJ = $(SRC:.c=.o)
TARGET = main
INC = include
<<<<<<< HEAD
SRC = main.c src/enlazada.c src/enlazada_doble.c main.c src/enlazada.c src/enlazada_doble.c main_stack.c src/stack.c # agregar aca el nombre de sus .c, formato: "src/nombre.c"
=======
SRC = main.c src/enlazada.c src/enlazada_doble.c main_stack.c src/stack.c# agregar aca el nombre de sus .c, formato: "src/nombre.c"
>>>>>>> feature/stack
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c main.c $(INC)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm main src/*.o main.o

