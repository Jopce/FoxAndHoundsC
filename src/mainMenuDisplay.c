#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <dirent.h>
#include <sys/stat.h>
#include <time.h>


//#include "mainMenuDisplay.h"

//Corner symbols
static char cornerChar[4] = {201, 187, 200, 188};
// static char cornerCharV2[4] = {218, 191, 192, 217};

//Row and column symbols
static char lineChar[2] = {205, 186}; // 0 - row and 1 - column
static char lineCharV2[2] = {196, 179}; // 0 - row and 1 - column

void printRowLine (int length, char Lchar, char rowChar, char conChar, char RChar)
{
    printf ("%c", Lchar);
    for (int row = 1; row < length; ++row)
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

int checkInput(char input[])
{
    //check if the string is one symbol length
    if (strlen(input) > 1)
        return 49379;

    int num = atoi(input); //convert input string to integer using atoi()

    //check if the input is from 0 to 15
    if (num >= 0 && num <= 15)
        return num;
    else
        return 49379;
}

void gameTitle()
{
    printf("\t\t\t\t  _____                      _    _____               _      \n");
    printf("\t\t\t\t |   __|___ _ _    ___ ___ _| |  |  |  |___ _ _ ___ _| |___  \n");
    printf("\t\t\t\t |   __| . |_'_|  | .'|   | . |  |     | . | | |   | . |_ -| \n");
    printf("\t\t\t\t |__|  |___|_,_|  |__,|_|_|___|  |__|__|___|___|_|_|___|___| \n");
}

char* mainMenuField (int counter)
{
    switch (counter)
    {
    case 0:
        return ("  < Main  Menu > ");
    case 1:
        return (" ----------------");
    case 2:
        return (" New  Game    (1)");
    case 3:
        return (" Continue     (2)");
    case 4:
        return (" ----------------");
    case 5:
        return (" Exit         (3)");
    default:
        return ("");
    }
}

char* gameField (int counter)
{
    switch (counter)
    {
    case 0:
        return ("Starting game...");
    default:
        return ("");
    }
}

/*
char* savesField (unsigned short int *counter, int filesSaved, unsigned short int *savesCheck)
{

    if(filesSaved == 0)
    {
        switch(*counter)
        {
        case 0:
            return (" No saved games...");
        case 1:
            return (" ---------------- ");
        case 2:
            return (" Back to Menu (1) ");
        default:
            return ("");
        }
    }
    else
    {
        if(filesSaved < *counter-1 && *savesCheck != 1)
        {
            *counter = 7;
            *savesCheck = 1;
        }

        switch (*counter)
        {
        case 0:
            return (" Pick saved game: ");
        case 1:
            return (" ---------------- ");
        case 2:
            return (" Save nr.     (1) ");
        case 3:
            return (" Save nr.     (2) ");
        case 4:
            return (" Save nr.     (3) ");
        case 5:
            return (" Save nr.     (4) ");
        case 6:
            return (" Save nr.     (5) ");
        case 7:
            return (" ---------------- ");
        case 8:
            return (" Back to Menu (6) ");
        default:
            return ("");
        }
    }
}
*/

char* difficultyField (int counter)
{
    switch (counter)
    {
    case 0:
        return (" Pick difficulty: ");
    case 1:
        return (" ---------------- ");
    case 2:
        return (" Easy         (1) ");
    case 3:
        return (" Medium       (2) ");
    case 4:
        return (" Hard         (3) ");
    case 5:
        return (" Custom       (4) ");
    case 6:
        return (" ---------------- ");
    case 7:
        return (" Go Back      (5) ");
    default:
        return ("");
    }
}

char* customDifficultyField(int counter)
{
    switch (counter)
    {
    case 0:
        return (" Difficulty:     ");
    case 1:
        return (" ---------------- ");
    case 2:
        return (" Choose 1 to 15   ");
    case 3:
        return (" ---------------- ");
    case 4:
        return (" Go back      (0) ");
    default:
        return ("");
    }
}

char* characterField (int counter)
{
    switch (counter)
    {
    case 0:
        return (" Pick character: ");
    case 1:
        return (" ---------------- ");
    case 2:
        return (" Fox          (1) ");
    case 3:
        return (" Hound        (2) ");
    case 4:
        return (" PvP          (3) ");
    case 5:
        return (" ---------------- ");
    case 6:
        return (" Back to Menu (4) ");
    default:
        return ("");
    }
}

int pauseMenu()
{
    char input[50] = "";
    char spaces[8] = "\t\t\t\t\t\t ";
    unsigned short int optionSelect;

    while (1)
    {
        //clear console
        system("cls");

        ///top of the box
        printf ("\n\n");
        printf ("%s", spaces);
        printRowLine(8*2 +10, cornerChar[0],  lineChar[0],  lineChar[0],  cornerChar[1]);
        printf ("\n");

        ///middle of the box
        printf ("%s%c       Pause Menu        %c\n", spaces, lineCharV2[1], lineCharV2[1]);
        printf ("%s%c ----------------------- %c\n", spaces, lineCharV2[1], lineCharV2[1]);
        printf ("%s%c Continue            (1) %c\n", spaces, lineCharV2[1], lineCharV2[1]);
        printf ("%s%c Exit and save       (2) %c\n", spaces, lineCharV2[1], lineCharV2[1]);
        printf ("%s%c Exit without saving (3) %c\n", spaces, lineCharV2[1], lineCharV2[1]);

        //bottom of the box
        printf ("%s", spaces);
        printRowLine (8*2 +10, cornerChar[2],  lineChar[0],  lineChar[0],  cornerChar[3]);

        ///check user input
        printf ("\n%s Select an option: ", spaces);
        scanf ("%s", &input);

        optionSelect = checkInput (input);

        if (optionSelect != 49379)
        {
            switch (optionSelect)
            {
            case 1:
                optionSelect = 2;
                break;
            case 2:
                optionSelect = 0;
                break;
            case 3:
                optionSelect = 1;
                break;
            default:
                optionSelect = 49379;
                break;
            }

            if (optionSelect != 49379)
            {
                return optionSelect;
            }
        }
    }
}

int savedGameMenu()
{
    char spaces[] = "\t\t\t\t\t\t ";

    // Open the current directory
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    int count = 0;

    ///Prints top part of the box
    printf("\n\n");
    printf("%s", spaces);
    printRowLine(8*2 +3, cornerChar[0],  lineChar[0],  lineChar[0],  cornerChar[1]);
    printf("\n");

    printf("%s", spaces);
    printf("%c Pick saved game: %c\n", lineCharV2[1], lineCharV2[1]);
    printf("%s", spaces);
    printf("%c ---------------- %c\n", lineCharV2[1], lineCharV2[1]);


    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL && count < 5)
    {
        // Check if the entry is a regular file with the format %d.txt
        if (sscanf(entry->d_name, "%d.txt", &count) == 1)
        {
            // Get the last modified time
            struct stat fileStat;
            stat(entry->d_name, &fileStat);

            // Convert the last modified time to a readable format
            char timeString[20];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));

            // Display the information

            gameTitle();
            printf("%s File: %s, Last Modified: %s %s \n", lineCharV2[1], entry->d_name, timeString, lineCharV2[1]);
        }
    }
    ///prints bottom section
    printf("%s", spaces);
    printRowLine(8*2 +3, cornerChar[2],  lineChar[0],  lineChar[0],  cornerChar[3]);

    // Close the directory
    closedir(dir);

    //Get user input

}

void exitGame()
{
    char temp = '\n';

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

int OptAvailability (int game_select, int field_Select) /// /////SUTVARKYK <---
{
    //check if different options are in the fields are available
    switch (game_select)
    {

    case 0: //main menu
        if (field_Select >= 1 && field_Select <= 3)
        {
            return field_Select;
        }
        else
        {
            return 49379;
        }
    case 1: //new game
        return field_Select;
    /*
    case 2: //continue
        if (field_Select >= 1 && field_Select <= filesSaved) ///check if exists
        {
            return field_Select-1;
        }
        else if (field_Select == 6)
        {
            return field_Select;
        }
        else
        {
            return 49379;
        }
        */
    case 3: //difficulty
        if (field_Select >= 1 && field_Select <= 5)
        {
            return field_Select;
        }
        else
        {
            return 49379;
        }

    case 4: //character
        if (field_Select >= 1 && field_Select <= 4)
        {
            return field_Select-1;
        }
        else
        {
            return 49379;
        }

    case 5: //custom difficulty
        if (field_Select >= 0 && field_Select <= 15)
        {
            return field_Select;
        }
        else
        {
            return 49379;
        }

    default:
        return 49379;
    }
}

int menuCLI (int game_select)
{
    unsigned short int field_Select;
    unsigned short int counter;
    unsigned short int savesCheck = 0;
    unsigned short int temp = 0;

    char spaces[] = "\t\t\t\t\t\t ";
    char text[20] = "";
    char input[50] = "";

    while(1)
    {
        counter = 0;

        //clear console
        //system("cls");
        //title
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
                strcpy (text, mainMenuField (counter)); //main menu option
                break;
            case 1:
                strcpy (text, gameField (counter)); ///should start game
                break;
                //case 2:
                //   strcpy (text, savesField (&counter, filesSaved, &savesCheck)); //saved progress options
                break;
            case 3:
                strcpy (text, difficultyField (counter)); //difficulty option
                break;
            case 4:
                strcpy (text, characterField (counter)); //character options
                break;
            case 5:
                strcpy (text, customDifficultyField (counter)); //custom difficulty options
                break;
            default:
                strcpy (text, mainMenuField (counter)); //default option
                break;
            }

            if(text[0] == '\0') break; //checks if there is a text to display

            //prints the left side of the section
            printf("%s", spaces);
            printf("%c", lineCharV2[1]);

            ///prints the middle section
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
        ///prints bottom section
        printf("%s", spaces);
        printRowLine(8*2 +3, cornerChar[2],  lineChar[0],  lineChar[0],  cornerChar[3]);

        //Get user input
        printf("\n\t\t\t\t\t\t  Select an option: ");
        scanf("%s", &input);

        //checks users input
        field_Select = checkInput(input);

        if(field_Select != 49379)
        {
            field_Select = OptAvailability(game_select, field_Select);

            if(field_Select != 49379)
            {
                return field_Select;
            }
        }
    }
}
