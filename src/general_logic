#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define n 8

void mover(char board[n][n], int *row, int *col, int direction) {
    switch (direction) {
        case 1: // Up right
            if (*row > 0 && *col < n - 1) {
                board[*row][*col] = '0';
                (*row)--;
                (*col)++;
                board[*row][*col] = 'W';
            }
            break;
        case 2: // Up left
            if (*row > 0 && *col > 0) {
                board[*row][*col] = '0';
                (*row)--;
                (*col)--;
                board[*row][*col] = 'W';
            }
            break;
        case 3: // Down right
            if (*row < n - 1 && *col < n - 1) {
                board[*row][*col] = '0';
                (*row)++;
                (*col)++;
                board[*row][*col] = 'W';
            }
            break;
        case 4: // Down left
            if (*row < n - 1 && *col > 0) {
                board[*row][*col] = '0';
                (*row)++;
                (*col)--;
                board[*row][*col] = 'W';
            }
            break;
        default:
            printf("Invalid move. Please enter a number from 1 to 4.\n");
    }
}

void printBoard(char board[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void pawnsMove(char board[n][n], int *row2, int *col2, int direction) {
    switch (direction) {
        case 1: // Down right
            if (*row2 < n - 1 && *col2 < n - 1) {
                board[*row2][*col2] = '0';
                (*row2)++;
                (*col2)++;
                board[*row2][*col2] = 'P';
            }
            break;
        case 2: // Down left
            if (*row2 < n - 1 && *col2 > 0) {
                board[*row2][*col2] = '0';
                (*row2)++;
                (*col2)--;
                board[*row2][*col2] = 'P';
            }
            break;
        default:
            printf("Invalid move. Please enter a number from 1 to 2.\n");
    }
}

int main() {
    char board[n][n];
    int rowW = 7; // Initial position for 'W'
    int colW = 4;
    int row2 = 0;
    int col2 = 4;
    int number = 2;

    // Initialize the board with '0'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '0';
        }
    }

    board[rowW][colW] = 'W';
    board[row2][col2] = 'P';

    int move;

    do {

        if(number % 2 == 0)
        {
            printBoard(board);
            printf("Enter a number to move the 'W' (1-4): ");
            scanf("%d", &move);
            mover(board, &rowW, &colW, move);
            number++;
        }else
        {
            printBoard(board);
            printf("Enter a number to move the 'P' (1-2): ");
            scanf("%d", &move);
            pawnsMove(board, &row2, &col2, move);
            number++;
        }

        // Print the current state of the board after 'P' moves

    } while (move >= 1 && move <= 4);

    return 0;
}
