/**
 * @file file_reader.c
 * @author (Prabodh Gyawali)
 * @brief This C file contains the functions to read and validate the maze file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5


/** @brief Validate the arguements passed to the program 
 * 
 * @param argc the number of arguements
 * @param argv the arguements passed (2D array of characters)
 **/
int check_arguements(int argc, char* argv[]) {
    // check args
        if (argc == 1){
            printf("Usage: maze <filename>\n");
            return 0;
        }
        if (argc > 2) {
            printf("Too many arguments passed! Only <filename> is needed!\n");
            return 0;
        }
	
    // Extracting the extension of the file and checking if it is a .txt file
        int len = strlen(argv[1]);
        char* extension_string = &argv[1][len-4];
        
        if (len > 4) {
            if (!strcmp(extension_string, ".txt")) {
                return 1;	
            }
            else {
                printf("Error: Maze file has to be a .txt!\n");
                return 0;
            }
        }
        else {
            printf("Error: Maze file has to be a .txt!\n");
            return 0;
        }
}


/**
 * @brief Validate if width is between 5 and 100
 *
 * @param buffer char array to validate
 * @return 0 for error, 1 for success
 */
int validate_width(char buffer[])
{
    if (strlen(buffer) < MIN_DIM || strlen(buffer) > MAX_DIM) {
        printf("Error: Maze width has to be between 5 and 100!\n");
        return 0;
    }
    // printf("Width is valid\n");
    return 1;

}


int validate_char(char buffer[], int* s_counter, int* e_counter) {
    char valid_chars[5] = "# SE\n"; 
    
    for (int i = 0; i < strlen(buffer); i++) {
        // strchr(s, c) returns the pointer to first occurence to the character c in the string s
        if (buffer[i] == '\0') {
            continue;
        }
        if (strchr(valid_chars, buffer[i]) != NULL) {
            // Contains valid character
            if (buffer[i] == 'S') {
                (*s_counter)++;
            } else if (buffer[i] == 'E') {
                (*e_counter)++;
            } 
            // printf("Valid character\n");
            continue;
        }
        else {
            // printf("Invalid character in index %d\n", i);
            // printf("Error: Invalid character in maze!\n");
            return 0;
        }
    }
    return 1;
}

int validate_shape(char buffer[], int last_buffer_length) {
    if (strlen(buffer) != last_buffer_length) {
        printf("Error: Maze must be rectangular!\n");
        return 0;
    }
    return 1;
}

/** @brief Validate both height and width of the maze 
 * @param file the file pointer to check
 * @return int 0 for error, or a valid maze dimension
 */
int validate_maze(FILE *file, int* ptr_width, int* ptr_height) 
{
    char lineBuffer[101];
    int last_buffer_length;

    int counter = 0;
    int s_counter = 0;
    int e_counter = 0; 

    while (fgets(lineBuffer, 101, file) != NULL) {
        /* Check width between 5 and 100 */ 
        if (!validate_width(lineBuffer) ) {
            return 0;
        }

        /* Check for valid characters*/
        if (!validate_char(lineBuffer, &s_counter, &e_counter)) {
            return 0;
        }
        // Check if the height exceeds 100
        if (counter > MAX_DIM) {
            printf("Error: Maze height has to be less than 100!\n");
            return 0;
        }
        /* Irregular shape check */ 
        if (counter > 0) {
            // NOTE: that every line except last has '\n' at end
            if (lineBuffer[strlen(lineBuffer) - 1] == '\n') {
                if (!validate_shape(lineBuffer, last_buffer_length)) {
                    return 0;
                }
            }
            else {
                // Doing this to avoid counting '\n' in the length of the last_line_buffer
                if (!validate_shape(lineBuffer, last_buffer_length-1)) {
                    return 0;
                }
            }
        } 
        // Update vars for next line's iteration
        last_buffer_length = strlen(lineBuffer);
        counter++;
    }

    // Check if the height is more than 5
    if (counter < MIN_DIM) {
        printf("Error: Maze height has to be at least 5!\n");
        return 0;
    }
    // Check if there is only one start and end
    if (s_counter != 1 || e_counter != 1) {
        printf("Error: Maze must have exactly one start and end!\n");
        return 0;
    }

    // If no errors, return 1
    (*ptr_height) = counter;
    (*ptr_width) = last_buffer_length;
    return 1;

}
