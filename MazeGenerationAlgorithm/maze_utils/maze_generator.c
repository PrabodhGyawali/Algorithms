#include <stdio.h>
#include <stdint.h>
#include "maze_generator.h"

// algorithm_backtrack
cell_state_t get_cell(maze_t* maze, uint32_t y, uint32_t x) {
	return maze->cells[y][x];
}

void set_cell(maze_t* maze, uint32_t y, uint32_t x, cell_state_t state) {
	maze->cells[y][x] = state;	
} 


maze_t* maze_generator(uint32_t height, uint32_t width) {
	// Allocate memory onto
	maze_t* maze = malloc(sizeof(maze_t));
	if (maze == NULL) {
		return NULL;
	}
	
	maze->height = height;
	maze->width = width;
	
	// Row pointers malloc
	maze->cells = malloc(height * sizeof(cell_state_t*));
	if (maze->cells == NULL) {
		free(maze);
		return NULL;
	}

	// Malloc for cell_state_t in each row
	for (uint32_t i = 0; i < height; ++i ) {
		maze->cells[i] = malloc(width * sizeof(cell_state_t));
		if (maze->cells[i] == NULL) {
			// Free previously allocated rows
				for (uint32_t j = 0; j < i; j++) {
						free(maze->cells[j]);
				}	
				free(maze->cells);
				free(maze);
				return NULL;
		}
	}

	// Cell initialization
	for (uint32_t y = 0; y < height; y++) {
		for (uint32_t x = 0; x < width; x++) {
			maze->cells[y][x] = WALL;
		}
	}
		
	//// Generate Maze using one of the algorithms below
	// recursive_backtracking_generate(maze);
	// algorithm_aldous(maze);
	// algorithm_binary(maze);
	// algorithm_kruskal(maze);
	// algorithm_prims(maze);
	// algorithm_division(maze);

	return maze;
}

/* TODO: implement if applicable */
int reshape(maze_t* maze, uint32_t new_height, uint32_t new_width) {
	// Reallocate row pointers
	cell_state_t** new_cells = realloc(maze->cells, new_height * sizeof(cell_state_t*));
	if (new_cells == NULL) { return 1;}
	
	maze->cells = new_cells;
	// Reallocate each row 
	for (uint32_t i = 0; i < new_height; i++) {
		maze->cells[i] =  realloc(maze->cells[i], new_width * sizeof(cell_state_t));
		if (maze->cells[i] == NULL) {
			for (uint32_t j = 0; j < i; j++) {
				// TODO: resize to old or free whole maze
				printf("Realloc error need to reshape\n");
				return 1;
			}
		}
	}	
	
	maze->height = new_height;
	maze->width = new_width;
	
	return 0;
}


uint32_t get_width(maze_t* maze) {
	return maze->width;
}

uint32_t get_height(maze_t* maze) {
	return maze->height;
}

void free_maze(maze_t* maze) {
	for (uint32_t i = 0; i < maze->height; i++) {
		free(maze->cells[i]);
	}
	free(maze->cells);
	free(maze);
}

void print_maze(maze_t* maze) {
	cell_state_t** cells = maze->cells;
	for (uint32_t y = 0; y < maze->height; y++)
	{
		for (uint32_t x = 0; x < maze->width; x++)
		{
			switch (cells[y][x])
			{
			case WALL:
				printf("#");
				break;
			case HOLE:
				printf(" ");
			case SOL:
				printf("S");
			default:
				fprintf(stderr, "Error: invalid state!");
				break;
			} (cells[y][x]);
		}
		printf("\n");
	}
	
}

void animate_maze(maze_t* maze);