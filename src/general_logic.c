#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define n 8

typedef int** Board;

void Pwin_lose(int *win, int *lose, int *number)
{
    if(*number %2 == 0)
    {
        if(*win == 1)
        {
            printf("You Win!\n");
        }
        else if(*lose == 4)
        {
            printf("You lose!\n");
        }
    }
    else if(*number %2 != 0)
    {
        if(*win == 1)
        {
            printf("You lose!\n");
        }
        else if(*lose == 4)
        {
            printf("You win!\n");
        }
    }
}

void freeMemory(Board board, int *array2, int *array3)
{
    free(array2);
    free(array3);

    for (int i = 0; i < n; ++i)
    {
        free(board[i]);
    }
    free(board);
}

Board allocateBoard()
{
    Board board = (int **)calloc(n, sizeof(int *));
    if (board == NULL)
    {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < n; ++i)
    {
        board[i] = (int *)calloc(n, sizeof(int));
        if (board[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed. Exiting...\n");
            exit(1);
        }
    }

    return board;
}


void save_game(int *array2,int *array3, int *rowW, int *colW, int *player)
{
    int choice;
    printf("Save progress 1-5, or don't 0: ");
    scanf("%d", &choice);
    if(choice == 0)
    {
        return;
    }
    FILE *file;
    char fileName[20];

    switch (choice) {
        case 1:
            sprintf(fileName, "%d.txt", choice);
            break;

        case 2:
            sprintf(fileName, "%d.txt", choice);
            break;
        case 3:
            sprintf(fileName, "%d.txt", choice);
            break;
        case 4:
            sprintf(fileName, "%d.txt", choice);
            break;
        case 5:
            sprintf(fileName, "%d.txt", choice);
            break;

        default:
            printf("Invalid choice\n");
            return;
    }

    // Open the file for writing
    file = fopen(fileName, "w");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        fprintf(file, "%d ", array2[i]);
    }
    fprintf(file,"\n");

     for (int i = 0; i < 4; ++i) 
    {
        fprintf(file, "%d ", array3[i]);
    }

    // Write the rowW to the file
    fprintf(file, "\n%d", *rowW);
    fprintf(file, "\n%d", *colW);
    fprintf(file, "\n%d", *player);

    // Close the file
    fclose(file);

    printf("Save file written %s\n", fileName);
}
void displayLastModifiedTime()
{
    // Open the current directory
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    int count = 0;

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL && count < 5) 
    {
        // Check if the entry is a regular file with the format %d.txt
        if (entry->d_type == DT_REG && sscanf(entry->d_name, "%d.txt", &count) == 1) 
        {
            // Get the last modified time
            struct stat fileStat;
            stat(entry->d_name, &fileStat);

            // Convert the last modified time to a readable format
            char timeString[20];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));

            // Display the information
            printf("File: %s, Last Modified: %s\n", entry->d_name, timeString);
        }
    }

    // Close the directory
    closedir(dir);
}
void processInput(int *save, int *array2, int *array3, int *rowW, int *colW, int *player)
{
    FILE *file;
    char fileName[5];

    switch (*save)
    {
        case 1:
            sprintf(fileName, "%d.txt", *save);

            // Open the file
            file = fopen(fileName, "r");
            if (file == NULL) 
            {
                perror("Error opening file");
                return;
            }

            // Read data into arrays and integers
            for (int i = 0; i < 4; ++i) 
            {
                fscanf(file, "%d", &array2[i]);
            }
            for (int i = 0; i < 4; ++i) 
            {
                fscanf(file, "%d", &array3[i]);
            }
            fscanf(file, "%d", &(*rowW));
            fscanf(file, "%d", &(*colW));
            fscanf(file, "%d", &(*player));

            // Close the file
            fclose(file);

            break;

        case 2:
            sprintf(fileName, "%d.txt", *save);

            // Open the file
            file = fopen(fileName, "r");
            if (file == NULL) 
            {
                perror("Error opening file");
                return;
            }

            // Read data into arrays and integers
            for (int i = 0; i < 4; ++i)
            {
                fscanf(file, "%d", &array2[i]);
            }
            for (int i = 0; i < 4; ++i) 
            {
                fscanf(file, "%d", &array3[i]);
            }
            fscanf(file, "%d", &(*rowW));
            fscanf(file, "%d", &(*colW));
            fscanf(file, "%d", &(*player));

            // Close the file
            fclose(file);


            break;
        case 3:
            sprintf(fileName, "%d.txt", *save);

            // Open the file
            file = fopen(fileName, "r");
            if (file == NULL)
            {
                perror("Error opening file");
                return;
            }

            // Read data into arrays and integers
            for (int i = 0; i < 4; ++i) 
            {
                fscanf(file, "%d", &array2[i]);
            }
            for (int i = 0; i < 4; ++i) 
            {
                fscanf(file, "%d", &array3[i]);
            }
            fscanf(file, "%d", &(*rowW));
            fscanf(file, "%d", &(*colW));
            fscanf(file, "%d", &(*player));

            // Close the file
            fclose(file);
        case 4:
            sprintf(fileName, "%d.txt", *save);

            // Open the file
            file = fopen(fileName, "r");
            if (file == NULL) 
            {
                perror("Error opening file");
                return;
            }

            // Read data into arrays and integers
            for (int i = 0; i < 4; ++i)
            {
                fscanf(file, "%d", &array2[i]);
            }
            for (int i = 0; i < 4; ++i)
            {
                fscanf(file, "%d", &array3[i]);
            }
            fscanf(file, "%d", &(*rowW));
            fscanf(file, "%d", &(*colW));
            fscanf(file, "%d", &(*player));

            // Close the file
            fclose(file);
        case 5:
            sprintf(fileName, "%d.txt", *save);

            // Open the file
            file = fopen(fileName, "r");
            if (file == NULL)
            {
                perror("Error opening file");
                return;
            }

            // Read data into arrays and integers
            for (int i = 0; i < 4; ++i)
            {
                fscanf(file, "%d", &array2[i]);
            }
            for (int i = 0; i < 4; ++i)
            {
                fscanf(file, "%d", &array3[i]);
            }
            fscanf(file, "%d", &(*rowW));
            fscanf(file, "%d", &(*colW));
            fscanf(file, "%d", &(*player));

            // Close the file
            fclose(file);

        default:
            printf("Invalid save proceed with default game\n");
    }
}


void check_lose(Board board, int *row, int *col, int *win, int *lose, int *player)
{
    if (*player == 1)
    {
        if(*row == 0)
        {
            *win = 1;
        }
    }
    else if(*player == 2)
    {
        if(*row == 7)
        {
            *win = 1;
        }
    }
    else
    {
        if (*col + 1 > n - 1 || *row - 1 < 0 || board[*row - 1][*col + 1] == 'H') {
            (*lose)++;
        }

        if (board[*row - 1][*col - 1] == 'H' || *row - 1 < 0 || *col - 1 < 0) {
            (*lose)++;
        }

        if (*row + 1 > n - 1 || *col + 1 > n - 1 || board[*row + 1][*col + 1] == 'H') {
            (*lose)++;
        }

        if (*row + 1 > n - 1 || *col - 1 < 0 || board[*row + 1][*col - 1] == 'H') {
            (*lose)++;
        }

        if (*lose >= 4) {
            *lose = 4; // To ensure *lose does not exceed 4
        } else if (*lose != 4) {
            *lose = 0;
        }
    }
}

void generateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3)
{
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

void NewgenerateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3)
{
   switch (choice) {
        case 1:
            array2[0] = *rowValue;
            array3[0] = *colValue;
            // which pawn logic for case 1
            break;
        case 2:
            array2[1] = *rowValue;
            array3[1] = *colValue;
            // which pawn logic for case 2
            break;
        case 3:
            array2[2] = *rowValue;
            array3[2] = *colValue;
            // which pawn logic for case 3
            break;
        case 4:
            array2[3] = *rowValue;
            array3[3] = *colValue;
            // which pawn logic for case 4
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
   }
}

int getUserInput()
{
    int userNumber;

    // Check if the entered number is within the specified range
    do {
        printf("Enter a number between 1 and 4 or to save 0: ");

        scanf("%d", &userNumber);

        // Check if the entered number is within the specified range
        if (userNumber >= 0 && userNumber <= 4)
        {
            // If the number is within the range, break out of the loop
            break;
        }
        else
        {
            // If the number is outside the range, display an error message
            printf("Error to move need 1 and 4.\n");
        }

    } while (1); // Infinite loop until a valid input is provided

    // Return the entered number
    return userNumber;

}

void mover(Board board, int *row, int *col, int direction, int *player)
{
    int valid = 0;
    do
    {
        if(valid == 1)
        {
            printf("the move doesn't fit in the board: ");
            scanf("%d", &direction);
        }

        switch (direction)
        {
            case 1: // Up right or if flipped down left
                if(*player == 1)
                {
                    board[*row][*col] = '0';
                    (*row)--;
                    (*col)++;
                    if( *col>n-1 || *row<0 || board[*row][*col] == 'H')
                    {

                        (*row)++;
                        (*col)--;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                else
                {
                    board[*row][*col] = '0';
                    (*row)++;
                    (*col)--;
                    if(*row>n-1 || *col<0 || board[*row][*col] == 'H')
                    {

                        (*row)--;
                        (*col)++;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                break;
            case 2: // Up left flipped down right
                if(*player == 1)
                {
                    board[*row][*col] = '0';
                    (*row)--;
                    (*col)--;
                    if(board[*row][*col] == 'H' || *row<0 || *col<0)
                    {

                        (*row)++;
                        (*col)++;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                else
                {
                     board[*row][*col] = '0';
                    (*row)++;
                    (*col)++;
                    if(*row>n-1 || *col>n-1 || board[*row][*col] == 'H')
                    {

                        (*row)--;
                        (*col)--;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                break;
            case 3: // Down right flipped up left
                if(*player == 1)
                {
                    board[*row][*col] = '0';
                    (*row)++;
                    (*col)++;
                    if(*row>n-1 || *col>n-1 || board[*row][*col] == 'H')
                    {

                        (*row)--;
                        (*col)--;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                else
                {
                     board[*row][*col] = '0';
                    (*row)++;
                    (*col)++;
                    if(*row>n-1 || *col>n-1 || board[*row][*col] == 'H')
                    {

                        (*row)--;
                        (*col)--;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }

                break;
            case 4: // Down left flipped up right
                if(*player == 1)
                {
                    board[*row][*col] = '0';
                    (*row)++;
                    (*col)--;
                    if(*row>n-1 || *col<0 || board[*row][*col] == 'H')
                    {

                        (*row)--;
                        (*col)++;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }
                else
                {
                    board[*row][*col] = '0';
                    (*row)--;
                    (*col)++;
                    if( *col>n-1 || *row<0 || board[*row][*col] == 'H')
                    {

                        (*row)++;
                        (*col)--;
                        valid = 1;

                    }
                    else
                    {
                        valid = 0;
                    }
                    board[*row][*col] = 'F';
                }

                break;
            default:
                printf("Invalid move. Please enter a number from 1 to 4.\n");
        }
    }while(valid == 1);
}

void printBoard(Board board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void pawnsMove(Board board, int *row, int *col, int direction, int *player)
{
    int valid = 1;

    int suge = 0;

    do
    {
        if(suge == 1)
        {
            printf("Doesn't fit the board: " );
            scanf(" %d", &direction);
        }
        switch (direction) {
        case 1: // Down right flipped up left
            if(*player == 1)
            {
                board[*row][*col] = '0';
                (*row)++;
                (*col)++;
                if (*row == n || *col == n || board[*row][*col] == 'H' || board[*row][*col] == 'F')
                {
                    (*row)--;
                    (*col)--;
                    suge = 1;
                }
                else
                {
                    valid = 0;
                    suge = 0;
                }
                board[*row][*col] = 'H';
            }
            else
            {
                board[*row][*col] = '0';
                (*row)--;
                (*col)--;
                if (*row <0 || *col < n || board[*row][*col] == 'H' || board[*row][*col] == 'F')
                {
                    (*row)++;
                    (*col)++;
                    suge = 1;
                }
                else
                {
                    valid = 0;
                    suge = 0;
                }
                board[*row][*col] = 'H';

            }
            break;
        case 2: // Down left flipped up right
            if(*player == 1)
            {
                board[*row][*col] = '0';
                (*row)++;
                (*col)--;
                if (*row == n || *col == -1 || board[*row][*col] == 'H' || board[*row][*col] == 'F')
                {
                    (*row)--;
                    (*col)++;
                    suge = 1;
                }
                else
                {
                    valid = 0;
                    suge = 0;
                }
                board[*row][*col] = 'H';
            }
            else
            {
                board[*row][*col] = '0';
                (*row)--;
                (*col)++;
                if (*row < 0 || *col == n || board[*row][*col] == 'H' || board[*row][*col] == 'F')
                {
                    (*row)++;
                    (*col)--;
                    suge = 1;
                }
                else
                {
                    valid = 0;
                    suge = 0;
                }
                board[*row][*col] = 'H';

            }
            break;
        default:
            printf("Invalid move. Please enter a number from 1 to 2.\n");
        }
    }while(valid == 1);
}

int main()
{
    int rowW, colW, col1,col2,col3,col4,row1,row2,row3,row4;

    Board board = allocateBoard();

    int rowValue = 0;
    int colValue = 0;

    int userChoice;
    int player = 0;

    int number = 2; //priority value

    int *array2 = (int*)calloc(4, sizeof(int));
    int *array3 = (int*)calloc(4, sizeof(int));

    int save = 0;

    printf("Continue from save 1 no 0: \n");
    scanf("%d", &save);

    if(save == 1)
    {
        displayLastModifiedTime();
        printf("\n Which save you want to open \n");
        scanf("%d", &save);
        processInput(&save, array2, array3, &rowW, &colW, &player);
    }

    if(player == 0)
    {
        printf("Fox 1 or Haund 2: ");
        scanf("%d", &player);
    }

    if(save == 0)
    {
        if(player == 1)
        {
            rowW = 7;
            colW = 4;
            col1 = 7;
            col2 = 5;
            col3 = 3;
            col4 = 1;
            row1 = 0;
            row2 = 0;
            row3 = 0;
            row4 = 0;
        }
        else
        {
            rowW = 0;
            colW = 3;
            col1 = 0;
            col2 = 2;
            col3 = 4;
            col4 = 6;
            row1 = 7;
            row2 = 7;
            row3 = 7;
            row4 = 7;
        }
    }

     if(array2 == NULL )
    {
        fprintf(stderr, "didnt work arr2");
    }
    else
    {
        if(save == 0)
        {
            array2[0] = row1;
            array2[1] = row2;
            array2[2] = row3;
            array2[3] = row4;
        }
        else
        {
            row1 = array2[0];
            row2 = array2[1];
            row3 = array2[2];
            row4 = array2[3];
        }
    }


    if(array3 == NULL )
    {
        fprintf(stderr, "didnt work arr2");
    }
    else
    {
        if(save == 0)
        {
            array3[0] = col1;
            array3[1] = col2;
            array3[2] = col3;
            array3[3] = col4;
        }
        else
        {
            col1 = array3[0];
            col2 = array3[1];
            col3 = array3[2];
            col4 = array3[3];
        }
    }

    // Initialize the board with '0'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '0';
        }
    }


    board[rowW][colW] = 'F';
    board[row1][col1] = 'H';
    board[row2][col2] = 'H';
    board[row3][col3] = 'H';
    board[row4][col4] = 'H';

    int win = 0;
    int lose = 0;

    int move;

    if (player == 1)
    {
        number = 2;
    }
    else
    {
        number = 3;
    }

    do {

        if(number % 2 == 0)
        {
            printBoard(board);
            check_lose(board, &rowW, &colW, &win, &lose, &player);

            if(win == 1 || lose == 4)
            {
                break;
            }

            int enteredNumber = getUserInput();

            if(enteredNumber == 0)
            {
                save_game(array2, array3, &rowW, &colW, &player);
                break;
            }
            move = enteredNumber;
            mover(board, &rowW, &colW, move, &player);
            number++;
        }
        else
        {
            printBoard(board);
            check_lose(board, &rowW, &colW, &win, &lose, &player);
            if(win == 1 || lose == 1)
            {
                break;
            }
            printf("which pawn to move(1-4): ");
            scanf("%d", &userChoice);
            if(userChoice == 0)
            {
                save_game(array2, array3, &rowW, &colW, &player);
                break;
            }
            generateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);
            printf("Enter a number to move the 'H' (1-2): ");
            scanf("%d", &move);

            pawnsMove(board, &rowValue, &colValue, move, &player);
            NewgenerateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);
            number = 2;

        }

        // Print the current state of the board after 'H' or 'F' moves

    } while (1);


   freeMemory(board, array2, array3);

    Pwin_lose(int *win, int *lose, int *number);

    return 0;
}
