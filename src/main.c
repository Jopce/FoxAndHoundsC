#include <stdio.h>
#include "opponents.h"
// importint .h failus

int main()
{

    int game_board[BOARD_SIZE][BOARD_SIZE] = {{0, H, 0, H, 0, H, 0, H},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {F, 0, 0, 0, 0, 0, 0, 0}};

    int game_select = display_menu(); // igno kazkokia funkcija

    if (game_select == 1)
    {
        int difficulty = get_difficulty(); // igno kazkokia funkcija

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
        exit_game(); // igno funkcija kuri isjungia programa
        return 0;
    }

    do
    {
        int new_move = display_board(game_board); // igno funkcija kuri grazina skaiciuka kur paejo Fox

        make_a_move(&game_board, new_move); // luko funkcija kuri grazina nauja boarda su padarytu ejimu

    } while (!luko_game_over_function()); // luko funkcija kuri tikrina ar game over

    display_result(game_board); // igno funkcija kuri paziuri kas laimejo ir isveda rezultata
}
