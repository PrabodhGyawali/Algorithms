#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "maze.h"

// Implementation of the functions in maze.h
/**
 * @brief initializes a 2D char array from a file
 * @param total : # of cols
 * @param width : # elements in a row
 **/
char** return_2D_char_array(FILE *fptr, int width, int total) {
    // Reset pointer
    rewind(fptr);

    char **strings;
    strings = malloc(total * width * sizeof(char *));

    char buffer[101];
    int length = 0;

    for (int i = 0; i < total; i++) {
        fgets(buffer, 101, fptr);
        length = strlen(buffer);
        // Move the null terminator by 1 to remove the \n char
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }

        strings[i] = malloc(length * sizeof(char *));
        strcpy(strings[i], buffer);
    }
    return strings;
}

void create_maze(maze* this, FILE* fptr, int width, int height) {
    printf("Creating a %dx%d maze...\n", width, height);
    // Reset pointer to file
    rewind(fptr);
    // initialize this.start, this.end coords
    char filecontent[width + 1];
    int i = 0;
    while (fgets(filecontent, width + 1, fptr) != NULL) {
        for (int j = 0; j < width; j++) {
            if (filecontent[j] == '\n') {
                i++;
                break;
            }
            
            // Initialize start and end coordinates
            if (filecontent[j] == 'S') {
                (*this).start.x = j;
                (*this).start.y = i;
            }
            if (filecontent[j] == 'E') {
                (*this).end.x = j;
                (*this).end.y = i;
            }
        }
        
    }
    // Set the width and height
    (*this).height = height;
    (*this).width = width;
    // Initialize the map
    (*this).map = return_2D_char_array(fptr, width, height);
}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(maze *this)
{
    free(this->map);
    free(this);
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(maze* this, coord* player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]); // char is empty for some reason
                // printf("(%d, %d)", i, j);
            }
        }
        printf("\n"); 
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(maze *this, coord *player, char direction)
{                   
    int vector[2]; // {x, y} // down and right is (1, 1)
    
    switch (tolower(direction))
    {
        case 'w':
            vector[0] = -1;
            vector[1] = 0;
            break;
        case 'a':
            vector[0] = 0;
            vector[1] = -1;
            break;
        case 's':
            vector[0] = 1;
            vector[1] = 0;
            break;
        case 'd':
            vector[0] = 0;
            vector[1] = 1;
            break;
        default:
            printf("Error: Invalid direction\n");
            break;
    }
    // Check if direction has a wall

    if (this->map[(*player).y + vector[0]][(*player).x + vector[1]] == '#') {
        printf("You have bounced on a wall!\n");
    }
    else {
        // printf("\nchar:%c\n", this->map[(*player).y + vector[1]][(*player).x + vector[0]]);
        player->x += vector[1];
        player->y += vector[0];
    }

}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(maze *this, coord *player)
{
    if (this->map[(*player).y][(*player).x] == 'E') {
        printf("You Win!\n");
        return 1;
    }
    return 0;
}