#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            // Print the board after placing a queen
            cout << "Placed queen at (" << i << ", " << col << "):\n";
            printBoard(board);

            if (solveNQueensUtil(board, col + 1, N))
                return true;

            board[i][col] = 0; // Backtrack
            cout << "Backtracking from (" << i << ", " << col << "):\n";
            printBoard(board);
        }
    }

    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    if (solveNQueensUtil(board, 0, N)) {
        cout << "Solution found:\n";
        printBoard(board);
    } else {
        cout << "No solution exists\n";
    }
}

int main() {
    int N = 4; 
    solveNQueens(N);
    return 0;
}
