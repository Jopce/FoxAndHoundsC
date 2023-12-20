#include <stdio.h>
#include "opponents.h"
#include "time.h" // temporary

// can already be ran to test out the opponent_move function
// change depth to see how long it takes to run
int main()
{
    int initial_board[8][8] = {{0, H, 0, H, 0, H, 0, H},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0},
                               {F, 0, 0, 0, 0, 0, 0, 0}};

    int new_board[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                           {H, 0, H, 0, H, 0, H, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, F, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    int res = evaluate(new_board);

    /*

    int ret = display_menu()

    if (1) {
        difficult = get_diff()

        if (1) {
            ksamdokamsd = 5
        }
        2 tai 10
        3 tai 15

        4 input_diff
    }

    while

    int move = display_board(current_board)

    1 arba 2

    paeini boarde

    int move = display_board(current_board)

    new_board = opponent_move(current_board)

    percopini new_board i current_board

    is game over

    end while


    */

    printf("%d\n", res);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // before pruning: depth = 10 -> 2.229; depth = 11 -> 13.578
    // after pruning: depth = 10 -> 0.013; depth = 11 -> 0.034
    // crazy shit
    Move res_board = opponent_move(new_board, 15, 0);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", res_board.board[i][j]);
        }
    }

    printf("\nopponent_move took %f seconds to execute \n", cpu_time_used);

    printf("playing self:\n");

    printf("initial board\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", initial_board[i][j]);
        }
    }
    printf("\n");

    int is_maximising = 1;

    // gives some random digits near the end and stops idk why
    while (!(is_game_over(initial_board)))
    {
        Move res_board = opponent_move(initial_board, 15, is_maximising);

        // copy res_board.board

        // print out the board
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            printf("\n");
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (res_board.board[i][j] == F)
                {
                    printf("F ");
                }
                else if (res_board.board[i][j] == H)
                {
                    printf("H ");
                }
                else
                {
                    printf("%d ", res_board.board[i][j]);
                }
            }
        }
        printf("\n");

        // copy res_board.board to initial_board
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                initial_board[i][j] = res_board.board[i][j];
            }
        }

        if (is_maximising == 1)
        {
            is_maximising = 0;
        }
        else
        {
            is_maximising = 1;
        }
    }

    return res;
}
