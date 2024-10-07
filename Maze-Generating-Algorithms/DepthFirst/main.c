#include <stdio.h>
#include <stdlib.h>


int valid_path(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Create a nxn matrix
    int** sparse_matrix = malloc(sizeof(int)*n*n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sparse_matrix[i][j] = 0;   
        }
    }
    // Add edges to the sparse matrix
    for (int i = 0; i < edgesSize; i++) {
        int edgeNode1 = edges[i][0];
        int edgeNode2 = edges[i][1];
        sparse_matrix[edgeNode1][edgeNode2] = 1;
    }
    return 0;
}
// test case 1
int main() {
    int** edges = malloc(2*5*sizeof(int));
    int* edgesColSize = malloc(5*sizeof(int));
    edges[0][0] = 0; edges[0][1] = 1;   edgesColSize[0] += 1; edgesColSize[1] += 1;
    edges[1][0] = 0; edges[1][1] = 2;   edgesColSize[0] += 1; edgesColSize[2] += 1;
    edges[2][0] = 3; edges[2][1] = 5;   edgesColSize[3] += 1; edgesColSize[5] += 1;
    edges[3][0] = 5; edges[3][1] = 4;   edgesColSize[5] += 1; edgesColSize[4] += 1;
    edges[4][0] = 4; edges[4][1] = 3;   edgesColSize[4] += 1; edgesColSize[3] += 1;
    
    int valid = valid_path(6, edges, 5, edgesColSize, 0, 5);

    return 1;
}