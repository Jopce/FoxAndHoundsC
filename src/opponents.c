#include <stdio.h>
#include <limits.h>
#include "opponents.h"

int opponent_move(int board[BOARD_SIZE][BOARD_SIZE], int difficulty)
{
    // this will be called from main.c when it is the opponents turn
    // not sure what to return quite yet
    return 0;
}

// minimax algorithm template i did in C (later add alpha-beta pruning)
int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing_player)
{
    if (depth == 0 || isGameOver(board))
    {
        return evaluate(board);
    }

    // maybe get number of possible moves and then create an array of boards malloc
    int child_boards[MAX_MOVES][BOARD_SIZE][BOARD_SIZE];
    int number_of_moves;
    generate_moves(board, child_boards, &number_of_moves);

    if (is_maximizing_player)
    {
        int max_eval = INT_MIN;

        for (int i = 0; i < number_of_moves; i++)
        {
            int eval = minimax(child_boards[i], depth - 1, 0);
            max_eval = max(max_eval, eval);
        }

        return max_eval;
    }
    else
    {
        int min_eval = INT_MAX;

        for (int i = 0; i < number_of_moves; i++)
        {
            int eval = minimax(child_boards[i], depth - 1, 1);
            min_eval = min(min_eval, eval);
        }

        return min_eval;
    }
}

int is_game_over(int board[BOARD_SIZE][BOARD_SIZE])
{
    return 0;
}

int generate_moves(int board[BOARD_SIZE][BOARD_SIZE], int child_boards[MAX_MOVES][BOARD_SIZE][BOARD_SIZE], int *number_of_moves)
{

    return 0;
}

// functions to implement: isGameOver, generate_moves, evaluate
// perhaps in main.c there will be one of them implemented simply since it is vital for game logic?

// game is checkers: fox and hounds
int evaluate(int board[BOARD_SIZE][BOARD_SIZE])
{
    int score = 0;

    // its better when fox has more moves and is closer to the finish line
    // its worse when hounds are closer to the fox and fox has less moves

    return score;
}