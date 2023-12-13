#include <stdio.h>
#include <stdlib.h>
#include "boardDisplay.h"

//all H values will be interpreted as 1, F as 2
#define H 1
#define F 2

// Function that converts integers to chars
char getPieceSymbol (int value)
{
    switch (value)
    {
    case 0:
        return '.'; // An empty space
    case H:
        return 'H'; // Hounds symobl
    case F:
        return 'F'; // Fox symbol
    default:
        return '?'; // unexpected value
    }
}

// The Main function that displays the board
void displayBoard (int board[8][8])
{
    unsigned short int sidePannelState = 1;
    unsigned short int count = 0;

    system("cls"); //clears console

    ///Printing

    //Prints the top row of the board
    printRow (cornerChar[0], lineChar[0], TnBChar[0], cornerChar[1]);
    printf ("\n");

    //prints sides and the game pieces symbols
    for (int row = 0; row < 8; ++row)
    {
        printf ("%c", lineChar[1]);
        //Prints the inside of boxes, the symbols of play pieces
        for (int col = 0; col < 8; ++col)
        {
            printf (" %c ", getPieceSymbol(board[row][col])); //displays piece symbol on the board
            if (col != 7)
            {
                printf ("%c", lineCharV2[1]);
            }
            else
            {
                printf ("%c", lineChar[1]);
            }
        }

        ///List printing pt1
        if(sidePannelState)
        {
            printf ("\t\t\t%c", lineCharV2[1]);
            sidePannel (count);
            count++;
        }
        ///-----------------
        printf ("\n");

        if (row != 7)
        {
            printRow (sideChar[1], lineCharV2[0], conAllCharV2, sideChar[0]); //Prints the inside rows
        }
        else
            printRow (cornerChar[2], lineChar[0], TnBChar[1], cornerChar[3]); //Prints the bottom row


        ///List printing pt2
        if(sidePannelState)
        {
            printf ("\t\t\t%c", lineCharV2[1]);
            sidePannel (count);
            count++;
        }
        ///-----------------

        printf("\n");
    }
}

void infoBox (char text[])
{
    //Title of the box
    printf ("\nMoves: \n");

    //Prints top part of the box
    printRow( cornerChar[0],  lineCharV2[0],  lineCharV2[0],  cornerChar[1]);
    printf("\n");

    //Prints inside of box
    printf("%c", lineCharV2[1]);
    for(int i = 0; i < 31; i++)
    {
        if(i < 31)
        {
            printf("%c", text[i]);
        }
        else printf(" ");

        if(i >= 31)
            break;
    }
    printf("%c", lineCharV2[1]);
    printf("\n");

    //bottom part of info box
    printRow( cornerChar[2],  lineCharV2[0],  lineCharV2[0],  cornerChar[3]);
    printf("\n");
}

void printRow (char Lchar, char rowChar, char conChar, char RChar)
{
    printf ("%c", Lchar);
    for (int row = 1; row < 8*4; ++row)
    {
        if(row%4 != 0)
        {
            printf ("%c", rowChar);
        }
        else
            printf ("%c", conChar);
    }
    printf ("%c", RChar);
}

void sidePannel (int counter)
{
    switch (counter)
    {
    case 0:
        printf ("Instructions: ");
        break;
    case 1:
        printf ("Enter x and y to make a move ");
        break;
    case 4:
        printf ("Information: ");
        break;
    case 5:
        printf ("Board: 8x8 checkerboard");
        break;
    case 6:
        printf ("Playing as: FOX");
        break;
    case 7:
        printf ("Playing against: BOT's");
        break;
    case 8:
        printf ("Difficulty: Easy");
        break;
    default:
        printf ("");
        break;
    }
}


int main ()
{
    char text[50] = "Illegal moves are being made     ...";
    int initial_board [8][8] = {{0, H, 0, H, 0, H, 0, H},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {F, 0, 0, 0, 0, 0, 0, 0}
    };

    /// Displaying the initial board
    displayBoard (initial_board);

    ///Info BOX
    infoBox (text);

    return 0;
}
