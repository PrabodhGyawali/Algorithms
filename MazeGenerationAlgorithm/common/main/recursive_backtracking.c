#include "recursive_backtracking.h"
#include <stdlib.h>
#include "maze_generator.h"
#include <time.h>
#include <stdio.h>

void recursive_backtracking_generate(maze_t* maze) {
	
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

void recurvise_backtracking_crave_passage(uint32_t y, uint32_t x) {
	// Directions we can go
	uint32_t directions[4] = {
		0x00, 		// North 
		0x01, 		// East
		0x10, 		// West
		0x11		// South
	};
	size_t n = sizeof(directions) / sizeof(directions[0]);

	srand((unsigned int)time(NULL));

	shuffle(directions, n);
	// Print the shuffled directions
    for (size_t i = 0; i < n; i++) {
        printf("%d ", directions[i]);
    }
    printf("\n");
	
	// Go through each direction inside the randomly filled vector

}
