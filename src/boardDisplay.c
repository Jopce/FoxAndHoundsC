#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boardDisplay.h"

#define H 17
#define F 18

//Corner symbols
static char cornerChar[4] = {201, 187, 200, 188};
static char cornerCharV2[4] = {218, 191, 192, 217};

//Row and column symbols
static char lineChar[2] = {205, 186}; // 0 - row and 1 - column
static char lineCharV2[2] = {196, 179}; // 0 - row and 1 - column

//Side connection symbols
static char sideChar[2] = {185, 204}; //other values - 180, 195

//Top and bottom connection symbols
static char TnBChar[2] = {203, 202}; //0 - connection from top to bottom, 1 - connection from bottom to top
//other values - 194, 193

//All connection symbol
//static char conAllChar = 206;
static char conAllCharV2 = 197;


//when win
void BOTwinScreen(int points)
{
    printRow (8*4 -1, cornerCharV2[0], lineCharV2[0], lineCharV2[0], cornerCharV2[1]);
    printf ("\n");
    printf ("%c __ __            _ _ _ _     %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|  |  |___ _ _   | | | |_|___ %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|_   _| . | | |  | | | | |   |%c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c  |_| |___|___|  |_____|_|_|_|%c\n", lineCharV2[1], lineCharV2[1]);
    printRow (8*4 -1, cornerCharV2[2], lineCharV2[0], lineCharV2[0], cornerCharV2[3]);

    printf ("\nPoints scored: %d", points);
}

//when loose
void BOTloseScreen(int points)
{
    printRow (8*4 + 5, cornerCharV2[0], lineCharV2[0], lineCharV2[0], cornerCharV2[1]);
    printf ("\n");
    printf ("%c __ __            __                %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|  |  |___ _ _   |  |   ___ ___ ___ %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|_   _| . | | |  |  |__| . |_ -| -_|%c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c  |_| |___|___|  |_____|___|___|___|%c\n", lineCharV2[1], lineCharV2[1]);
    printRow (8*4 + 5, cornerCharV2[2], lineCharV2[0], lineCharV2[0], cornerCharV2[3]);

    printf ("\nPoints scored: %d", points);
}

void houndsWinScreen(int points)
{
    printRow (8*4 + 15, cornerCharV2[0], lineCharV2[0], lineCharV2[0], cornerCharV2[1]);
    printf ("\n");
    printf ("%c _____               _        _ _ _ _         %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|  |  |___ _ _ ___ _| |___   | | | |_|___ ___ %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|     | . | | |   | . |_ -|  | | | | |   |_ -|%c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|__|__|___|___|_|_|___|___|  |_____|_|_|_|___|%c\n", lineCharV2[1], lineCharV2[1]);
    printRow (8*4 + 15, cornerCharV2[2], lineCharV2[0], lineCharV2[0], cornerCharV2[3]);

    printf ("\nPoints scored: %d", points);
}


void foxWinScreen(int points)
{
    printRow (8*4 + 3, cornerCharV2[0], lineCharV2[0], lineCharV2[0], cornerCharV2[1]);
    printf ("\n");
    printf ("%c _____            _ _ _ _         %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|   __|___ _ _   | | | |_|___ ___ %c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|   __| . |_'_|  | | | | |   |_ -|%c\n", lineCharV2[1], lineCharV2[1]);
    printf ("%c|__|  |___|_,_|  |_____|_|_|_|___|%c\n", lineCharV2[1], lineCharV2[1]);
    printRow (8*4 + 3, cornerCharV2[2], lineCharV2[0], lineCharV2[0], cornerCharV2[3]);

    printf ("\nPoints scored: %d", points);
}

// Function that converts integers to chars
char* getPieceSymbol (int value)
{
    switch (value)
    {
    case 0:
        return " . "; // An empty space
    case 1:
        return "[1]";
    case 2:
        return "[2]";
    case 3:
        return "[3]";
    case 4:
        return "[4]";
    case H:
        return " H "; // Hounds symbol
    case F:
        return " F "; // Fox symbol
    default:
        return " ? "; // unexpected value
    }
}

// The Main function that displays the board
void displayBoard (int board[8][8], int isPlayer, int difficulty, int sidePannelOn, int foxOrHoundsTurn)
{
    unsigned short int count = 0;

    system("cls"); //clears console

    ///Printing:

    //Prints the top row of the board
    printRow (8*4, cornerChar[0], lineChar[0], TnBChar[0], cornerChar[1]);
    printf ("\n");

    //prints sides and the game pieces symbols
    for (int row = 0; row < 8; ++row)
    {
        printf ("%c", lineChar[1]);
        //Prints the inside of boxes, the symbols of play pieces
        for (int col = 0; col < 8; ++col)
        {
            printf ("%s", getPieceSymbol(board[row][col])); //displays piece symbol on the board
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
        if(sidePannelOn)
        {
            printf ("\t\t\t%c", lineCharV2[1]);
            sidePannel (count, isPlayer, difficulty, foxOrHoundsTurn);
            count++;
        }
        ///-----------------
        printf ("\n");


        if (row != 7)
        {
            printRow (8*4, sideChar[1], lineCharV2[0], conAllCharV2, sideChar[0]); //Prints the inside rows
        }
        else
            printRow (8*4, cornerChar[2], lineChar[0], TnBChar[1], cornerChar[3]); //Prints the bottom row


        ///List printing pt2
        if(sidePannelOn)
        {
            printf ("\t\t\t%c", lineCharV2[1]);
            sidePannel (count, isPlayer, difficulty, foxOrHoundsTurn);
            count++;
        }
        ///-----------------

        printf("\n");
    }
}

void infoBox (char text[])
{
    //check if empty char, if so set it to somethings
    if(text[0] == '\0')
        strcpy(text, "Pick a digit in \"[x]\" to move");

    int temp = 0;
    //Title of the box
    printf ("\nControls: \n");

    //Prints top part of the box
    printRow (8*4, cornerChar[0],  lineCharV2[0],  lineCharV2[0],  cornerChar[1]);
    printf ("\n");

    //Prints inside of box
    printf ("%c", lineCharV2[1]);
    for (int i = 0; i < 31; i++)
    {
        if (i < 31 && temp != 1)
        {
            if (text[i] == '\0')
            {
                temp = 1; //check if there is text
            }
            printf("%c", text[i]);
        }
        else printf (" ");

    }
    if (temp) printf (" ");
    printf ("%c", lineCharV2[1]);
    printf ("\n");

    //bottom part of info box
    printRow (8*4, cornerChar[2],  lineCharV2[0],  lineCharV2[0],  cornerChar[3]);
    printf ("\n");
}

void printRow (int lenght, char Lchar, char rowChar, char conChar, char RChar)
{
    printf ("%c", Lchar);
    for (int row = 1; row < lenght; ++row)
    {
        if (row%4 != 0)
        {
            printf ("%c", rowChar);
        }
        else
            printf ("%c", conChar);
    }
    printf ("%c", RChar);
}

void sidePannel (int counter, int isPlayer, int difficulty, int foxOrHoundsTurn)
{
    char difficultyChar[10] = "";
    char isPlayerChar[10] = "";
    char playingAs[10] = "";

    //checks if there is 1 or 2 players
    if (isPlayer == 1)
    {
        strcpy (isPlayerChar, "Player");
    }
    else strcpy (isPlayerChar, "BOT");

    //check whos turn
    if (foxOrHoundsTurn == 1) //fox = 1, hounds = 0
        strcpy (playingAs, "FOX");
    else
        strcpy (playingAs, "HOUNDS");

        //checks difficulty
    switch (difficulty)
    {
    case 0:
        strcpy (difficultyChar, "Player VS Player");
        break;
    case 5:
        strcpy (difficultyChar, "Easy");
        break;
    case 10:
        strcpy (difficultyChar, "Medium");
        break;
    case 15:
        strcpy (difficultyChar, "Hard");
        break;
    default:
        strcpy (difficultyChar, "Custom");
        break;
    }


    //Text that will be displayed
    switch (counter)
    {
    case 0:
        printf ("Game Rules: ");
        break;
    case 1:
        printf ("The Fox (F) moves diagonally to empty adjacent cell.");
        break;
    case 2:
        printf ("Hounds (H) move diagonally forward to empty adjacent cell.");
        break;
    case 3:
        printf ("Only one Hound (H) can move per turn.");
        break;
    case 4:
        printf ("The Fox (F) gets trapped when surrounded by Hounds (H).");
        break;
    //-------------------
    case 6:
        printf ("Information: ");
        break;
    case 7:
        printf ("Board: 8x8 checkerboard");
        break;
    case 8:
        printf ("Playing against: %s", isPlayerChar);
        break;
    case 9:
            if(isPlayer) printf ("Turn: %s", playingAs);
            else printf ("Playing as: %s", playingAs);
        break;
    case 10:
        printf ("Difficulty: %s", difficultyChar);
        break;
    default:
        printf (" ");
        break;
    }
}


