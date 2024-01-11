#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boardDisplay.h"

#define F 5
#define H1 6
#define H2 7
#define H3 8
#define H4 9


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

//prints the rows
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

//infobox
void infoBox (int foxOrHoundsTurn)
{

    char text[50] = "Pick a digit in \"[x]\" to move";

    if (foxOrHoundsTurn == 1) //hounds turn
    {
        strcpy(text, "Pick a hounds number to choose it");
    }
    else strcpy(text, "Pick a digit in \"[x]\" to move");

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

void printAlighned(char text[], int spaces)
{
    ///example: [][][][][] [][][][][] -  10 spaces are awailable and I want to print the word in the middle
    //for the code to run: should be more space then than the word and spaces should be an equal number

    unsigned short int temp = spaces - strlen(text); //get how much empty space is awilable

    for(int i = 0; i< temp/2 -1; i++)
    {
        printf(" ");
    }
    printf("%s", text);

    for(int i = 0; i< temp/2 -1; i++)
    {
        printf(" ");

    }
    if(temp%2 != 0) printf(" "); //if the word is odd anothe " " is required.
}

void determineField(char difficultyChar[], char isPlayerChar[], char playingAs[], int isPlayer, int difficulty, int foxOrHoundsTurn)
{
    //checks if there is 1 or 2 players
    if (isPlayer == 1)
    {
        strcpy (isPlayerChar,   "Player");
    }
    else strcpy (isPlayerChar,  "BOT");

    //check whos turn
    if (foxOrHoundsTurn == 0) //fox = 0, hounds = 1
        strcpy (playingAs,      "FOX");
    else
        strcpy (playingAs,      "HOUNDS");

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
}


void sidePannel (int counter, int isPlayer, int difficulty, int foxOrHoundsTurn)
{
    unsigned short int alighment = 18; //based on the largest string

    char difficultyChar[30] = "";
    char isPlayerChar[30] = "";
    char playingAs[30] = "";

    //3 options on the pannel will change
    determineField(difficultyChar, isPlayerChar, playingAs, isPlayer, difficulty, foxOrHoundsTurn);

    //Text that will be displayed
    switch (counter)
    {
    case 0:
        printf ("Game Rules: ");
        break;
    case 1:
        printf (" - The Fox (F) moves diagonally to any empty adjacent cell.");
        break;
    case 2:
        printf (" - Hounds (H) move diagonally to any empty adjacent cell.");
        break;
    case 3:
        printf (" - Hounds (H) can only move forward.");
        break;
    case 4:
        printf (" - Only one Hound (H) moves per turn.");
        break;
    //-------------------
    case 5:
        printf (" - Hounds (H) win by surrounding the Fox (F).");
        break;
    case 6:
        printf (" - The Fox (F) wins by reaching the other side of the board.");
        break;
    //-------------------
    case 8:
        printf ("Information: ");
        break;
    case 9:
        printf ("+-------------------------------------+");
        break;
    case 10:
        printf      ("| Board:           |");
        printAlighned("8x8", alighment);
        printf("| |");
        break;
    case 11:
        printf ("| Playing against: |");
        printAlighned(isPlayerChar, alighment);
        printf("| |");
        break;
    case 12:
        if(isPlayer)
        {
            printf ("| Turn:            |");
            printAlighned(playingAs, alighment);
            printf("| |");
        }
        else
        {
            printf  ("|Playing as:      |");
            printAlighned(playingAs, alighment);
            printf("| |");
        }
        break;
    case 13:
        printf      ("| Difficulty:      |");
        printAlighned(difficultyChar, alighment);
        printf("| |");
        break;
    case 14:
        printf ("+-------------------------------------+");
        break;
    case 15:
        printf ("To pause the game, press the number \"0\".");
        break;
    default:
        printf (" ");
        break;
    }
}

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

int checkMove(char move_char[])
{
    if(strlen(move_char) > 1)
        return 49379;

    switch (move_char[0])
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    default:
        return 49379;
    }
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
    case F:
        return " F "; // Fox symbol
    case H1:
        return "1H1"; // Hounds symbol
    case H2:
        return "2H2"; // Hounds symbol
    case H3:
        return "3H3"; // Hounds symbol
    case H4:
        return "4H4"; // Hounds symbol
    default:
        return " ? "; // unexpected value
    }
}

// The Main function that displays the board
int displayBoard (int board[8][8], int isPlayer, int difficulty, int foxOrHoundsTurn)
{
    unsigned short int count;
    unsigned short int sidePannelOn = 1;
    unsigned short int illegalMove = 0;
    unsigned short int move = 0;

    char move_char[50] = ""; //place to store users imput

    while(1)
    {
        count = 0;
        system("cls"); //clears console

        ///Printing
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
                printf ("%s", getPieceSymbol(board[row][col])); //displays piece symbol on the board //
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
        //infobox
        infoBox(foxOrHoundsTurn);

        //Take user input
        if(illegalMove == 1) printf("Illegal move, please select a new move: ");
        else printf("Select a move: ");

        scanf("%s", move_char);

        //checks users input
        move = checkMove(move_char);

        if(move == 49379)
        {
            illegalMove = 1;
        }
        else return move;
    }
}

//prints the win screen
void results (int points, int PlayerVSwho, int playerWinVSbot, int playerWinVSplayer)
{
    if (PlayerVSwho == 0)// 0 - bots
    {
        if (playerWinVSbot == 1) //win
            BOTwinScreen( points);
        else BOTloseScreen (points); //lose
    }
    else
    {
        if (playerWinVSplayer == 1)
            foxWinScreen (points);
        else houndsWinScreen (points);
    }
}



