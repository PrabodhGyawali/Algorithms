#include <stdio.h>

void rref(double a[][10], int rows, int cols) {
    int lead = 0;
    
    for (int r = 0; r < rows; r++) {
        if (lead >= cols) {
            return;
        }
        
        int i = r;
        while (a[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    return;
                }
            }
        }
        
        // Swap rows
        for (int j = 0; j < cols; j++) {
            double temp = a[r][j];
            a[r][j] = a[i][j];
            a[i][j] = temp;
        }
        
        // Normalize the pivot row
        double div = a[r][lead];
        for (int j = 0; j < cols; j++) {
            a[r][j] /= div;
        }
        
        // Eliminate all other entries in this column
        for (int i = 0; i < rows; i++) {
            if (i != r) {
                double factor = a[i][lead];
                for (int j = 0; j < cols; j++) {
                    a[i][j] -= factor * a[r][j];
                }
            }
        }
        lead++;
    }
}

void printMatrix(double a[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%0.2f ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double a[10][10] = {
        {1, 2, -1, -4},
        {2, 3, -1, -11},
        {-2, 0, -3, 22}
    };
    
    int rows = 3;
    int cols = 4;
    
    printf("Original Matrix:\n");
    printMatrix(a, rows, cols);
    
    rref(a, rows, cols);
    
    printf("\nReduced Row Echelon Form:\n");
    printMatrix(a, rows, cols);
    
    return 0;
}