#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <stdio.h>

// defines for max and min permitted dimensions
#define MAX_DIM 
#define MIN_DIM 

int check_arguements(int argc, char *argv[]);
int validate_width(char buffer[]);
int validate_maze(FILE *file, int* width, int* height);
int is_empty(FILE *file);

#endif