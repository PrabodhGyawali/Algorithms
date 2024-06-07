#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "maze.h"
#include <gtk/gtk.h>
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
// int check_arguements(int argc, char *argv[]) {
//     if (argc != 3) {
//         return 0;
//     }
//     // Check if argc[1] is an integer with a max of 3 digits
//     if (strlen(argv[1]) > 3 || strlen(argv[2]) > 3) {
//         return 0;
//     }
//     // Check if the width and height are integers
//     for (int i = 0; i < strlen(argv[1]); i++) {
//         if (!isdigit(argv[1][i])) {
//             return 0;
//         }
//     }
//     for (int i = 0; i < strlen(argv[2]); i++) {
//         if (!isdigit(argv[2][i])) {
//             return 0;
//         }
//     }
//     // Check if the width and height are within the range of 5 to 100
//     if (atoi(argv[1]) < 5 || atoi(argv[1]) > 100 || atoi(argv[2]) < 5 || atoi(argv[2]) > 100) {
//         return 0;
//     }
//     return 1;
// }

// char** create_empty_maze(int width, int height) {
//     char** map = malloc(height * sizeof(char*));
//     for (int i = 0; i < height; i++) {
//         map[i] = "#";
//     }
//     return map;
// }
// void destroy(GtkWidget *widget, gpointer data) {
//     gtk_main_quit();
// }

static void print_hello (GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_applicatio_window_new (app);
    gtk_window_set_title = (GTK_WINDOW (window), 200, 200);
    gtk_window_set_default_size(GTK_WINDOW (window), 200, 200);

    button = gtk_button_new_with_label ("Hello World!");
    g_signal_connect = (button, "clicked", G_CALLBACK(print_hello), NULL);
    gtk_window_set_child (GTK_WINDOW (window), button);

    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char *argv[]) {
    // Create a GUI window to visualize depth search algorithm
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref (app);

    return status;
}

// Archive for later:
// int width = atoi(argv[1]); int height = atoi(argv[2]);
// if (!check_arguements(argc, argv)) {
//         printf("Error: Invalid arg error!\n");
//         return 0;
//     }
// char** maze = create_empty_maze(width, height);
//    print_maze2(maze);