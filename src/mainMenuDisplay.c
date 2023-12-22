#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "mainMenuDisplay.h"

//Corner symbols
static char cornerChar[4] = {201, 187, 200, 188};
// static char cornerCharV2[4] = {218, 191, 192, 217};

//Row and column symbols
static char lineChar[2] = {205, 186}; // 0 - row and 1 - column
static char lineCharV2[2] = {196, 179}; // 0 - row and 1 - column

//Side connection symbols
// static char sideChar[2] = {185, 204}; //other values - 180, 195

//Top and bottom connection symbols
// static char TnBChar[2] = {203, 202}; //0 - connection from top to bottom, 1 - connection from bottom to top
//other values - 194, 193

//All connection symbol
// static char conAllChar = 206;
//static char conAllCharV2 = 197;

void gameTitle()
{
    printf("\t\t\t\t  _____                      _    _____               _      \n");
    printf("\t\t\t\t |   __|___ _ _    ___ ___ _| |  |  |  |___ _ _ ___ _| |___  \n");
    printf("\t\t\t\t |   __| . |_'_|  | .'|   | . |  |     | . | | |   | . |_ -| \n");
    printf("\t\t\t\t |__|  |___|_,_|  |__,|_|_|___|  |__|__|___|___|_|_|___|___| \n");
}

char* difficultyField (int counter)
{
    switch (counter)
    {
    case 0:
        return (" Easy         (1)");
        break;
    case 1:
        return (" Medium       (2)");
        break;
    case 2:
        return (" Hard         (3)");
        break;
    case 3:
        return (" Custom       (4)");
        break;
    case 4:
        return (" ---------------- ");
        break;
    case 5:
        return (" Back to Menu (5)");
        break;
    default:
        return ("");
        break;
    }
}

char* mainMenuField (int counter)
{
    switch (counter)
    {
    case 0:
        return (" New  Game    (1)");
        break;
    case 1:
        return (" Continue     (2)");
        break;
    case 2:
        return (" Difficulty   (3)");
        break;
    case 3:
        return (" ---------------- ");
        break;
    case 4:
        return (" Exit         (4)");
        break;
    default:
        return ("");
        break;
    }
}

void exitGame()
{
    char temp = "";

    system("cls");
    //setlocale(LC_ALL, "lt_LT"); //Dont work

    printf (" _____           _ _ _          _ \n");
    printf ("|     |___ ___ _| |_| |_ ___   |_|\n");
    printf ("|   --|  _| -_| . | |  _|_ -|   _ \n");
    printf ("|_____|_| |___|___|_|_| |___|  |_|\n");

    printRowLine(8*2 +16, cornerChar[0],  lineCharV2[0],  lineCharV2[0],  cornerChar[1]);
    printf("\n");

    printf("%c Projektinis darbas paruostas: %c\n", lineCharV2[1], lineCharV2[1]);
    printf("%c   -Jokubo Petraicio           %c\n", lineCharV2[1], lineCharV2[1]);
    printf("%c   -Igno Caso,                 %c\n", lineCharV2[1], lineCharV2[1]);
    printf("%c   -Luko Amos Alvorado         %c\n", lineCharV2[1], lineCharV2[1]);

    printRowLine(8*2 +16, cornerChar[2],  lineCharV2[0],  lineCharV2[0],  cornerChar[3]);

    printf("\n\nPress any button to exit ");
    scanf("%c", &temp);
}

int menuCLI ()
{
    unsigned short int ilegalInput;
    unsigned short int counter;
    unsigned short int game_select = 0;
    unsigned short int temp = 0;

    char spaces[] = "\t\t\t\t\t\t ";
    char text[20] = "";
    char input[50] = "";

    while(1)
    {
        ilegalInput = 0;
        counter = 0;

        //clear console
        system("cls");
        ///title
        gameTitle();

        ///Prints top part of the box
        printf("\n\n");
        printf("%s", spaces);
        printRowLine(8*2 +3, cornerChar[0],  lineChar[0],  lineChar[0],  cornerChar[1]);
        printf("\n");

        //Prints inside of box
        while(1)
        {
            switch(game_select)
            {
            case 0:
                strcpy (text, mainMenuField (counter));
                break;
            case 1:
                strcpy (text, difficultyField (counter));
                break;
            default:
                strcpy (text, mainMenuField (counter));
                break;
            }

            if(text[0] == '\0') break; //checks if there is a text to display

            //prints the left side of the section
            printf("%s", spaces);
            printf("%c", lineCharV2[1]);

            //prints the middle section
            for(int i = 0; i < 15 +3; i++)
            {
                if(i < 31 && temp != 1)
                {
                    //Checks if text has ended
                    if(text[i] == '\0')
                    {
                        temp = 1;
                    }
                    printf("%c", text[i]);
                }
                else printf(" ");
            }

            if(temp)
            {
                printf(" ");
                temp = 0;
            }

            //prints the right side of the section
            printf("%c", lineCharV2[1]);
            printf("\n");
            (counter)++;
        }
        //prints bottom section
        printf("%s", spaces);
        printRowLine(8*2 +3, cornerChar[2],  lineChar[0],  lineChar[0],  cornerChar[3]);

        ///Get user input
        if(ilegalInput == 1) printf("Illegal move, please select a new move: ");
        else printf("\n\t\t\t\t\t\t  Select an option: ");

        scanf("%s", &input);

        //checks users input
        game_select = checkInput(input);

        if(game_select == 49379)
            ilegalInput = 1;
        else return game_select;
    }
}

int checkInput(char input[])
{
    if(strlen(input) > 1)
        return 49379;

    switch (input[0])
    {
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

void printRowLine (int lenght, char Lchar, char rowChar, char conChar, char RChar)
{
    printf ("%c", Lchar);
    for (int row = 1; row < lenght; ++row)
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


