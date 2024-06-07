CC=gcc
CFLAGS=-I.

DEPS = file-reader.h
OBJ = maze-game.o file-reader.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

maze: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) maze
debug:
	$(CC) -g -o maze maze-game.c file-reader.c -I.