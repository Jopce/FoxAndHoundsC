#include <stdio.h>
#include <stdlib.h>
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
    if (depth == 0 || is_game_over(board))
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

// returns 1 if game is over (true), 0 if game is not over (false)
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE])
{
    // temporary solution (works but might be not the most efficient)
    if (evaluate(board) == INT_MAX || evaluate(board) == INT_MIN)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int generate_moves(int board[BOARD_SIZE][BOARD_SIZE], int child_boards[MAX_MOVES][BOARD_SIZE][BOARD_SIZE], int *number_of_moves)
{

    return 0;
}

int evaluate(int board[BOARD_SIZE][BOARD_SIZE])
{
    // evaluate function returns a score based on how favorable
    // the current board is to either fox (>0) or hounds (<0)
    // the score is based on how far the fox is from the finish, how many moves it has,
    // how many hounds are blocking it, and how spread out the hounds are

    int score = 0;
    int fox_moves = 0;
    int fox_row = 0;

    // get fox position
    int fox_position[2] = {-1, -1};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == F)
            {
                fox_position[0] = i;
                fox_position[1] = j;
                // fox found, break the inner loop
                break;
            }
        }
        if (fox_position[0] != -1)
        {
            // fox found, break the outer loop
            break;
        }
    }

    fox_row = fox_position[0];

    if (fox_row == 0)
    {
        // game is won
        return INT_MAX;
    }

    // Forward Right Diagonal Move
    if (fox_position[0] + 1 < BOARD_SIZE && fox_position[1] + 1 < BOARD_SIZE &&
        board[fox_position[0] + 1][fox_position[1] + 1] == 0)
    {
        fox_moves++;
    }

    // Forward Left Diagonal Move
    if (fox_position[0] + 1 < BOARD_SIZE && fox_position[1] - 1 >= 0 &&
        board[fox_position[0] + 1][fox_position[1] - 1] == 0)
    {
        fox_moves++;
    }

    // Backward Right Diagonal Move
    if (fox_position[0] - 1 >= 0 && fox_position[1] + 1 < BOARD_SIZE &&
        board[fox_position[0] - 1][fox_position[1] + 1] == 0)
    {
        fox_moves++;
    }

    // Backward Left Diagonal Move
    if (fox_position[0] - 1 >= 0 && fox_position[1] - 1 >= 0 &&
        board[fox_position[0] - 1][fox_position[1] - 1] == 0)
    {
        fox_moves++;
    }

    if (fox_moves == 0)
    {
        // game is lost
        return INT_MIN;
    }

    // add logic about hounds here later after other pieces are done

    // Score calculation logic
    score += fox_moves * 15;                    // More moves available for the fox increases the score
    score += ((BOARD_SIZE - 1) - fox_row) * 10; // Closer the fox to the end row, higher the score

    return score;
}