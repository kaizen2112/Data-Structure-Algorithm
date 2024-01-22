#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> board;

bool isSafe(int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solveNQueens(int row) {
    if (row == n) {
        // All queens are placed, add the current board to the result.
        for (int i = 0; i < n; i++) {
            cout << board[i] << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';  // Place the queen
            solveNQueens(row + 1);  // Recursively solve for the next row
            board[row][col] = '.';  // Remove the queen (backtrack)
        }
    }
}

int main() {
    cin >> n;
    board = vector<string>(n, string(n, '.'));

    solveNQueens(0);

    return 0;
}
