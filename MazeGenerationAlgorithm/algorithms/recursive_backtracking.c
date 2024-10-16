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

	uint32_t current_y = y;
	uint32_t current_x = x;
	
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
    printf("%d %d %d %d\n", directions[0], directions[1], directions[2], directions[3]);
	// Go through each direction inside the randomly filled vector
	for (size_t i = 0; i < n; i++) {
		switch (directions[i]) {
			case 0x1:
				if ((current_y +=1) >= maze->height) 
					continue;
				
				if (maze->cells[current_y + 1][current_x] == HOLE) 
					continue;
				
				current_y += 1;
				maze->cells[current_y][current_x] = HOLE;
				break;
			case 0x2:
				if ((current_x +=1) >= maze->width) 
					continue;
				
				if (maze->cells[current_y][current_x + 1] == HOLE)
					continue;
				current_x += 1;
				maze->cells[current_y][current_x] = HOLE;
				break;
			case 0x3:
				if ((current_x -=1) < 0)
					continue;

				if ((maze->cells[current_y][current_x - 1]) == HOLE)
					continue;
				current_x -= 1;
				maze->cells[current_y][current_x] = HOLE;
				break;
			case 0x4:
				if ((current_y -=1) < 0) 
					continue;
				
				if ((maze->cells[current_y - 1][current_x]) == HOLE)
					continue;
				current_y += 1;
				maze->cells[current_y][current_x] = HOLE;
				break;
			default:
				fprintf(stderr, "Invalid direction!\n");
				break;
		}
		// TODO: Implement recursion back to starting position

	}
}
