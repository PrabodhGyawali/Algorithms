#include "maze_utils/maze_generator.h"

int main() {
	maze_t* maze = maze_generator(30, 30);
	print_maze(maze);
}
