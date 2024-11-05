#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

    auto start = high_resolution_clock::now();
    multiplyMatrices(A, B, C, rowA, colA, colB);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Single-threaded matrix multiplication took " << duration.count() << " milliseconds." << endl;
    printMatrix(C, rowA, colB);

    return 0;
}


#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

    auto start = high_resolution_clock::now();

    thread threads[MAX_SIZE]; // Create an array of threads
    for (int i = 0; i < rowA; ++i) {
        threads[i] = thread(multiplyRow, A, B, C, rowA, colA, colB, i);
    }

    for (int i = 0; i < rowA; ++i) {
        threads[i].join(); // Wait for all threads to finish
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Multithreaded matrix multiplication (one thread per row) took " << duration.count() << " milliseconds." << endl;
    printMatrix(C, rowA, colB);

    return 0;
}





// g++ -o matrix_multiplication matrix_multiplication.cpp -pthread
// ./matrix_multiplication



/*

Time Complexity Analysis
Single-Threaded Time Complexity: 𝑂(𝑚⋅𝑛⋅𝑝)

Multithreaded Time Complexity: O(m⋅n⋅p)

However, the effective runtime may be reduced due to parallel execution. In an ideal scenario, where there are enough cores to handle each row of the result matrix, the time complexity can approach:
O(m⋅n⋅p)/𝑘

k is the number of threads (or available cores). This means that as k increases, the time taken may decrease proportionately, up to a limit.


Single-Threaded Space Complexity: O(m⋅n⋅p)

The space complexity is determined by the space needed for the input matrices and the output matrix. Thus, the space complexity is:
𝑂(𝑚⋅𝑛+𝑛⋅𝑝+𝑚⋅𝑝)
Here, 
𝑂(𝑚⋅𝑛)
O(m⋅n) is for matrix A, 
O(n⋅p) is for matrix B, and 
O(m⋅p) is for the result matrix C.


Multithreaded Space Complexity:O(m⋅n+n⋅p+m⋅p)
Additional space may be needed for the thread stack space, but this is typically negligible compared to the size of the matrices being multiplied.*/