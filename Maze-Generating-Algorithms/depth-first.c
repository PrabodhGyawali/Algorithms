#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "maze.h"
/**
 * @brief The maze graph is a connected graph with 1 node for each open movable space in the maze
 * @param nodes An array of coord representing the node's (x, y)
 */

struct __Graph {
    coord* nodes;
} typedef graph;

// *graph create_graph(maze* this) {
//     // Create a graph with the number of nodes equal to the number of open spaces in the maze
// }
int check_arguements(int argc, char *argv[]) {
    if (argc != 3) {
        return 0;
    }
    // Check if argc[1] is an integer with a max of 3 digits
    if (strlen(argv[1]) > 3 || strlen(argv[2]) > 3) {
        return 0;
    }
    // Check if the width and height are integers
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            return 0;
        }
    }
    for (int i = 0; i < strlen(argv[2]); i++) {
        if (!isdigit(argv[2][i])) {
            return 0;
        }
    }
    // Check if the width and height are within the range of 5 to 100
    if (atoi(argv[1]) < 5 || atoi(argv[1]) > 100 || atoi(argv[2]) < 5 || atoi(argv[2]) > 100) {
        return 0;
    }
    return 1;
}

char** create_empty_maze(int width, int height) {
    char** map = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        map[i] = "#";
    }
    return map;
}

int main(int argc, char *argv[]) {
    // make sure only 2 arguements are passed with width and height of the maze
    if (!check_arguements(argc, argv)) {
        printf("Error: Invalid arg error!\n");
        return 0;
    }
    int width = atoi(argv[1]); int height = atoi(argv[2]);

    // create a maze with the given width and height
    char** maze = create_empty_maze(width, height);
    print_maze2(maze);
    return 0;
}