#include "recursive_backtracking.h"
#include <stdlib.h>
#include "../maze_utils/maze_generator.h"
#include <time.h>
#include <stdio.h>

void recursive_backtracking_generate(maze_t* maze) {
	// Get a random y and x using rand
	srand((unsigned int)clock());
	int random_y = rand() % maze->height;
	int random_x = rand() % maze->width;
	recursive_backtracking_crave_passage(maze, random_y, random_x);
}

void shuffle(uint32_t* array, size_t n) {
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j]; 
			array[j] = array[i];
			array[i] = t;
		}
	}
	
}

void recursive_backtracking_crave_passage(maze_t* maze, uint32_t y, uint32_t x) {
	// Directions we can go
	uint32_t directions[4] = {
		0x1, 		// North 
		0x2, 		// East
		0x3, 		// West
		0x4			// South
	};
	size_t n = sizeof(directions) / sizeof(directions[0]);

	shuffle(directions, n);
	// Print the shuffled directions
    printf("called \n");
	// Go through each direction inside the randomly filled vector
	for (size_t i = 0; i < n; i++) {
		uint32_t new_y = y;
        uint32_t new_x = x;
		 switch (directions[i]) {
            case 0x1: // North
                if (y + 1 >= maze->height) continue;
                new_y = y + 1;
                break;
            case 0x2: // East
                if (x + 1 >= maze->width) continue;
                new_x = x + 1;
                break;
            case 0x3: // West
                if (x == 0) continue;
                new_x = x - 1;
                break;
            case 0x4: // South
                if (y == 0) continue;
                new_y = y - 1;
                break;
            default:
                fprintf(stderr, "Invalid direction!\n");
                continue;
        }
		if (maze->cells[new_y][new_x] == HOLE) continue;
		maze->cells[new_y][new_x] = HOLE;
		recursive_backtracking_crave_passage(maze, new_y, new_x);
	}
}
