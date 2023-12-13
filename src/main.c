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

    printf("%d\n", res);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // before pruning: depth = 10 -> 2.229; depth = 11 -> 13.578
    // after pruning: depth = 10 -> 0.013; depth = 11 -> 0.034
    // crazy shit
    Move res_board = opponent_move(new_board, 15);

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

    return res;
}
