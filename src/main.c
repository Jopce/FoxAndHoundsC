#include <stdio.h>
#include "opponents.h"
#include "file_logic.h"
#include "mainMenuDisplay.h"
#include "boardDisplay.h"
// importint .h failus

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

    int game_board[BOARD_SIZE][BOARD_SIZE] = {{0, H, 0, H, 0, H, 0, H},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {F, 0, 0, 0, 0, 0, 0, 0}};

    int game_select = menuCLI();; // igno kazkokia funkcija

    if (game_select == 1) //start new game
    {
        int difficulty = menuCLI(); // igno difficulty and player choosing what character to play

        switch (difficulty)
        {
        case 1:
            difficulty = EASY;
            break;
        case 2:
            difficulty = MEDIUM;
            break;
        default:
            difficulty = HARD;
            break;
        }
    }
    else if (game_select == 2) //continue
    {
        // luko funkcija kuri is save file paima boarda ir difficulty
        // jeigu jo nera tai tsg grazina default boarda
        displayLastModifiedTime();
        printf("\n Which save you want to open \n "); // ***ingai please CLI this one
        scanf("%d", &save);
        processInput(&save, array2, array3, &rowW, &colW, &player, &difficulty); //I have not added difficulty but I can add it

        Structas save_data = get_save_data(); // luko kazkokia funkcija kuri grazina structa kazkoki kur yra {int difficulty, int board[8][8]}

        int difficulty = save_data.difficulty;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                game_board[i][j] = save_data.board[i][j];
            }
        }
    }
    else //exit
    {
        freeMemory(board, array2, array3);
        exitGame(); // igno funkcija kuri isjungia programa
        return 0;
    }

    if(save == 0)
    {if(player == 1){rowW=7;colW=4;}else{col1=0;row1=7;col2=0;row2=7;col3=0;row3=7;col4=0;row4=7;}}

    if(player == 2) //if it is hound these are values if it is loading new values or existing in the save file
    {if(save == 0){array2[0]=row1;array2[1]=row2;array2[2]=row3;array2[3]=row4;array3[0]=col1;array3[1]=col2;array3[2]=col3;array3[3]=col4;}
    else{row1=array2[0];row2=array2[1];row3=array2[2];row4=array2[3];col1=array3[0];col2=array3[1];col3=array3[2];col4=array3[3];}}
    
    do
    {                   //Reikia informacijos -: VS_Player: 1 if playing VS another player, else 0 | foxOrHoundsTurn: 1 if fox, else 0 hounds
        int new_move = displayBoard (game_board, VS_Player, difficulty, foxOrHoundsTurn); // igno funkcija kuri grazina skaiciuka kur paejo Fox

       if(player == 0 || player == 2) //fox = 0 hound = 1 pvp = 2
       {
           mover(); //player moves
       }
        else
       {
           //bot moves 
       }
        
       if(player == 0)
       {
           //bot moves
       }
        else if(player == 1 || player == 2)
       {
           pawnMove();
       }

    } while (!luko_game_over_function()); // luko funkcija kuri tikrina ar game over

    freeMemory(board, array2, array3);
    Pwin_lose(&win, &lose, &player);
    
    //display_result(game_board); /// igno funkcija kuri paziuri kas laimejo ir isveda rezultata
    ///Reikia informacijos -: PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win <--------- need variables
    results (points, PlayerVSwho, playerWinVSbot, playerWinVSplayer);
}
