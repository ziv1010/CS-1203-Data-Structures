#include <stdio.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check if there is a queen in the same row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check if there is a queen in the upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check if there is a queen in the lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1))
                return 1;

            board[i][col] = 0;
        }
    }

    return 0;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0) == 0) {
        printf("No solution exists.\n");
        return;
    }

    printSolution(board);
}

int main() {
    solveNQueens();
    return 0;
}