#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <stdio.h>
#include <stdint.h>

typedef enum {
        WALL,
        HOLE,
        SOL
} cell_state_t;

typedef struct maze_t {
 	cell_state_t** cells;
	uint32_t height;
	uint32_t width;
} maze_t;


maze_t* maze_generator(uint32_t height, uint32_t width);

void set_cell(maze_t* maze, uint32_t y, uint32_t x, cell_state_t state);
cell_state_t get_cell(maze_t* maze, uint32_t y, uint32_t x);


int reshape(maze_t* maze, uint32_t new_height, uint32_t new_width);

uint32_t get_height(maze_t* maze);
uint32_t get_width(maze_t* maze);

// TODO: Look into what random device and private C++ functions mean means

#endif /* MAZE_GENERATOR_H */

