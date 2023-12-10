#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define n 8

void generateRowAndColNames(int choice, int *rowValue, int *colValue, int array2[5], int array3[5]) {
   switch (choice) {
        case 1:
            *rowValue = array2[0];
            *colValue = array3[0];
            // which pawn logic for case 1
            break;
        case 2:
            *rowValue = array2[1];
            *colValue = array3[1];
            // which pawn logic for case 2
            break;
        case 3:
            *rowValue = array2[2];
            *colValue = array3[2];
            // which pawn logic for case 3
            break;
        case 4:
            *rowValue = array2[3];
            *colValue = array3[3];
            // which pawn logic for case 4
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
   }
}

int getUserInput() {
    int userNumber;

    // Check if the entered number is within the specified range
    do {
        // Prompt the user for input
        printf("Enter a number between 1 and 4 or to pause 0: ");

        // Read the user input
        scanf("%d", &userNumber);

        // Check if the entered number is within the specified range
        if (userNumber >= 0 && userNumber <= 4) {
            // If the number is within the range, break out of the loop
            break;
        } else {
            // If the number is outside the range, display an error message
            printf("Error: Please enter a number between 1 and 4.\n");
        }
    } while (1); // Infinite loop until a valid input is provided

    // Return the entered number
    return userNumber;

}

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

void pawnsMove(char board[n][n], int *rowValue, int *colValue, int direction) {
    switch (direction) {
        case 1: // Down right
            if (*rowValue < n - 1 && *colValue < n - 1) {
                board[*rowValue][*colValue] = '0';
                (*rowValue)++;
                (*colValue)++;
                board[*rowValue][*colValue] = 'P';
            }
            break;
        case 2: // Down left
            if (*rowValue < n - 1 && *colValue > 0) {
                board[*rowValue][*colValue] = '0';
                (*rowValue)++;
                (*colValue)--;
                board[*rowValue][*colValue] = 'P';
            }
            break;
        default:
            printf("Invalid move. Please enter a number from 1 to 2.\n");
    }
}

int main() {
    char board[n][n];

    int rowValue = 0;
    int colValue = 0;

    int userChoice;
    int row1=0;
    int row2=0;
    int row3=0;
    int row4=0;
    int array2[4] = {row1,row2, row3, row4}; // Adjust the array size as needed
    int rowW = 7; // Initial position for 'W'
    int colW = 4;
    int col1 = 7;
    int col2 = 5;
    int col3 = 3;
    int col4 = 1;
    int number = 2;
    int array3[4] = {col1,col2,col3,col4};

    // Initialize the board with '0'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '0';
        }
    }

    board[rowW][colW] = 'W';
    board[row1][col1] = 'P';
    board[row2][col2] = 'P';
    board[row3][col3] = 'P';
    board[row4][col4] = 'P';

    int move;

    do {

        if(number % 2 == 0)
        {
            printBoard(board);
            int enteredNumber = getUserInput();
            if(enteredNumber == 0)
            {
                return 0;
            }
            move = enteredNumber;
            mover(board, &rowW, &colW, move);
            number++;
        }else
        {
            printBoard(board);
            printf("which pawn to move(1-4): ");
            scanf("%d", &userChoice);
            generateRowAndColNames(userChoice, &rowValue, &colValue, array2,array3);
            printf("Enter a number to move the 'P' (1-2): ");
            scanf("%d", &move);
            pawnsMove(board, &rowValue, &colValue, move);
            number++;
        }

        // Print the current state of the board after 'P' or 'W' moves

    } while (move >= 1 && move <= 4);

    return 0;
}
