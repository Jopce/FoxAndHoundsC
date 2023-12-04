#include <stdio.h>
#include "opponents.h"
// put to header file later
#define F 1
#define H 2

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

    int res = is_game_over(initial_board);

    printf("Hello, world!\n");
    return res;
}
