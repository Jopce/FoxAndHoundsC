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

    if (game_select == 1)
    {
        int difficulty = menuCLI(); // igno kazkokia funkcija

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
    else if (game_select == 2)
    {
        // luko funkcija kuri is save file paima boarda ir difficulty
        // jeigu jo nera tai tsg grazina default boarda
        displayLastModifiedTime();
        printf("\n Which save you want to open \n ");
        scanf("%d", &save);
        processInput(&save, array2, array3, &rowW, &colW, &player, &difficulti); //I have not added difficulty but I can add it

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
    else
    {
        exitGame(); // igno funkcija kuri isjungia programa
        return 0;
    }

    do
    {                   //Reikia informacijos -: VS_Player: 1 if playing VS another player, else 0 | foxOrHoundsTurn: 1 if fox, else 0 hounds
        int new_move = displayBoard (game_board, VS_Player, difficulty, foxOrHoundsTurn); // igno funkcija kuri grazina skaiciuka kur paejo Fox

        make_a_move(&game_board, new_move); // luko funkcija kuri grazina nauja boarda su padarytu ejimu

    } while (!luko_game_over_function()); // luko funkcija kuri tikrina ar game over

    //display_result(game_board); /// igno funkcija kuri paziuri kas laimejo ir isveda rezultata
    ///Reikia informacijos -: PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win <--------- need variables
    results (points, PlayerVSwho, playerWinVSbot, playerWinVSplayer);
}
