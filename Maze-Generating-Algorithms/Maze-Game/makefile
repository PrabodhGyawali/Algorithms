CC=gcc
CFLAGS=-I.

DEPS = file_reader.h
OBJ = maze.o file_reader.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

maze: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) maze
debug:
	$(CC) -g -o maze maze.c file_reader.c -I.