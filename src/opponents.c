// note to self: still need to look into evaluate for hounds and generate moves (and pruning)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "opponents.h"

// takes in the current board and the selected user difficulty
// returns the Move struct (defined in opponents.h)
Move opponent_move(int board[BOARD_SIZE][BOARD_SIZE], int difficulty, int is_maximizing_player)
{
    // the difficulty is the depth of the minimax algorithm
    Move optimal_move = minimax(board, difficulty, is_maximizing_player, INT_MIN, INT_MAX);
    return optimal_move;
}

// minimax algorithm with alpha-beta pruning
Move minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing_player, int alpha, int beta)
{
    Move new_move;
    if (depth == 0 || is_game_over(board))
    {
        new_move.score = evaluate(board);
        copy_board(board, new_move.board);
        return new_move;
    }

    // maybe get number of possible moves and then create an array of boards malloc
    int number_of_moves;
    int(*child_boards)[BOARD_SIZE][BOARD_SIZE] = malloc(MAX_MOVES * sizeof(*child_boards));
    if (child_boards == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for child_boards\n");
        exit(EXIT_FAILURE);
    }

    generate_moves(board, child_boards, &number_of_moves, is_maximizing_player);

    if (is_maximizing_player)
    {
        new_move.score = INT_MIN;

        for (int i = 0; i < number_of_moves; i++)
        {
            Move child_move = minimax(child_boards[i], depth - 1, 0, alpha, beta);
            if (child_move.score > new_move.score)
            {
                new_move.score = child_move.score;
                copy_board(child_boards[i], new_move.board);
            }

            alpha = max_of_2(alpha, new_move.score);
            if (beta <= alpha)
            {
                break;
            }
        }
    }
    else
    {
        new_move.score = INT_MAX;
        for (int i = 0; i < number_of_moves; i++)
        {
            Move child_move = minimax(child_boards[i], depth - 1, 1, alpha, beta);
            if (child_move.score < new_move.score)
            {
                new_move.score = child_move.score;
                copy_board(child_boards[i], new_move.board);
            }

            beta = min_of_2(beta, new_move.score);
            if (beta <= alpha)
            {
                break;
            }
        }
    }
    free(child_boards);

    return new_move;
}

// returns 1 if game is over (true), 0 if game is not over (false)
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE])
{
    // temporary solution (works but might be not the most efficient)
    int score = evaluate(board);
    if (score == INT_MAX || score == INT_MIN)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void copy_board(int source[BOARD_SIZE][BOARD_SIZE], int destination[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            destination[i][j] = source[i][j];
        }
    }
}

void generate_moves(int board[BOARD_SIZE][BOARD_SIZE], int (*child_boards)[BOARD_SIZE][BOARD_SIZE], int *number_of_moves, int is_maximizing_player)
{
    *number_of_moves = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (is_maximizing_player && board[i][j] == F) // If the piece is a fox
            {
                // Check all four possible moves for the fox
                int dx[4] = {-1, -1, 1, 1};
                int dy[4] = {-1, 1, -1, 1};

                for (int move = 0; move < 4; move++)
                {
                    int new_i = i + dx[move];
                    int new_j = j + dy[move];

                    // If the move is valid
                    if (new_i >= 0 && new_i < BOARD_SIZE && new_j >= 0 && new_j < BOARD_SIZE && board[new_i][new_j] == 0)
                    {
                        // Copy the current board to a new board
                        copy_board(board, child_boards[*number_of_moves]);

                        // Apply the move to the new board
                        child_boards[*number_of_moves][i][j] = 0;
                        child_boards[*number_of_moves][new_i][new_j] = F;

                        (*number_of_moves)++;
                    }
                }
            }
            else if (!is_maximizing_player && board[i][j] == H) // If the piece is a hound
            {
                // Check both possible moves for the hound
                int dx[2] = {1, 1};
                int dy[2] = {-1, 1};

                for (int move = 0; move < 2; move++)
                {
                    int new_i = i + dx[move];
                    int new_j = j + dy[move];

                    // If the move is valid
                    if (new_i >= 0 && new_i < BOARD_SIZE && new_j >= 0 && new_j < BOARD_SIZE && board[new_i][new_j] == 0)
                    {
                        // Copy the current board to a new board
                        copy_board(board, child_boards[*number_of_moves]);

                        // Apply the move to the new board
                        child_boards[*number_of_moves][i][j] = 0;
                        child_boards[*number_of_moves][new_i][new_j] = H;

                        (*number_of_moves)++;
                    }
                }
            }
        }
    }
}

// returns an int of how favorable the board is for the fox
int evaluate(int board[BOARD_SIZE][BOARD_SIZE])
{
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

    int hound_distance = 0;
    int number_of_hounds = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == H)
            {
                hound_distance += abs(i - fox_position[0]) + abs(j - fox_position[1]);
                number_of_hounds++;
            }
        }
    }

    int average_hound_distance = hound_distance / number_of_hounds;

    // Score calculation logic
    score += fox_moves * 15;                    // More moves available for the fox increases the score
    score += ((BOARD_SIZE - 1) - fox_row) * 10; // Closer the fox to the end row, higher the score
    score -= average_hound_distance * 5;        // Hounds closer to the fox decreases the score

    return score;
}