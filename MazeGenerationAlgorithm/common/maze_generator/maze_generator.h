#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <stdio.h>
#include <stdint.h>

enum cell_state_t {
	WALL;
	HOLE;
	SOLUTION;
} state;

void maze_generator(uint32_t height, uint32_t width);

void set_cell(uint32_t x, uint32_t);
cell_state_t get_cell(uint32_t x, uint32_t);

uint32_t** get_maze(void);

void set_maze(uint32_t** maze);

void reshape(uint32_t new_height, uint32_t new_width);

uint32_t get_height(void);
uint32_t get_width(void);

// TODO: Look into what random device and private C++ functions mean means

#endif /* MAZE_GENERATOR_H */

