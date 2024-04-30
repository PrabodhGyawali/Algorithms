# Compiler to use
CC = gcc

# Compiler flags, -I. adds current directory to include path
CFLAGS = -I.

# Dependencies
DEPS = maze.h

# Object files
OBJ = maze.o depth-first.o

%.o: %.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

depth-first: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

clean:
    rm -f $(OBJ) depth-first