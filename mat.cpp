/*#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Define a maximum size for the matrices

// Function to perform single-threaded matrix multiplication
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowA, int colA, int colB) {
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colB; ++j) {
            C[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < colA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int rowA = 3, colA = 3, colB = 2; // Dimensions of matrices
    int A[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[MAX_SIZE][MAX_SIZE] = {{1, 2}, {3, 4}, {5, 6}};
    int C[MAX_SIZE][MAX_SIZE] = {0}; // Resultant matrix

    // Perform the multiplication
    multiplyMatrices(A, B, C, rowA, colA, colB);
    
    cout << "Single-threaded matrix multiplication result:" << endl;
    printMatrix(C, rowA, colB);

    return 0;
}
*/

#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Define a maximum size for the matrices

// Function to multiply one row of A with matrix B and store in row of C
void multiplyRow(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowA, int colA, int colB, int row) {
    for (int j = 0; j < colB; ++j) {
        C[row][j] = 0; // Initialize the result cell
        for (int k = 0; k < colA; ++k) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int rowA = 3, colA = 3, colB = 2; // Dimensions of matrices
    int A[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[MAX_SIZE][MAX_SIZE] = {{1, 2}, {3, 4}, {5, 6}};
    int C[MAX_SIZE][MAX_SIZE] = {0}; // Resultant matrix

    // Simulate multithreaded behavior by calling multiplyRow for each row in a loop
    for (int i = 0; i < rowA; ++i) {
        multiplyRow(A, B, C, rowA, colA, colB, i);
    }

    cout << "Simulated multithreaded matrix multiplication result:" << endl;
    printMatrix(C, rowA, colB);

    return 0;
}
