#include <stdio.h>
#include <stdlib.h>

#define N 4

// Function to perform LU decomposition
void luDecomposition(float mat[N][N], float lower[N][N], float upper[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper Triangular
        for (int k = i; k < N; k++) {
            float sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
            upper[i][k] = mat[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < N; k++) {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else {
                float sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }
}

// Function to calculate the determinant
float determinant(float mat[N][N]) {
    float lower[N][N], upper[N][N];
    luDecomposition(mat, lower, upper);

    float det = 1;
    for (int i = 0; i < N; i++) {
        det *= upper[i][i];
    }
    return det;
}

int main() {
    float matrix[N][N] = {
        {3.14, 7.89, -5.67, 2.45},
        {-1.23, 4.56, 8.90, -7.34},
        {6.78, -9.01, 3.21, 5.43},
        {-4.56, 2.34, -8.76, 1.98}
    };

    float det = determinant(matrix);

    printf("Determinant of the matrix is: %lf\n", det);

    return 0;
}
