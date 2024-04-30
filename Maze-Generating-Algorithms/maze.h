#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __Coord
{
    int x; // 4 bytes
    int y; // 4 bytes
} coord;

typedef struct __Maze
{
    char **map; // (width x height) bytes
    int height; // 4 bytes
    int width; // 4 bytes
    coord start; // 8 bytes
    coord end; // 8 bytes
} maze;

char** return_2D_char_array(FILE *fptr, int width, int total);
void create_maze(maze* this, FILE* fptr, int width, int height);
void free_maze(maze *this);
void print_maze(maze* this, coord* player);
void move(maze *this, coord *player, char direction);
int has_won(maze *this, coord *player);

#endif 