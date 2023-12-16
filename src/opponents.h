#define max_of_2(a, b) ((a > b) ? a : b)
#define min_of_2(a, b) ((a < b) ? a : b)

#define BOARD_SIZE 8
#define MAX_MOVES 12
#define F 1
#define H 2
#define EASY 5
#define MEDIUM 10
#define HARD 15

typedef struct
{
    int score;
    int board[BOARD_SIZE][BOARD_SIZE];
} Move;

Move opponent_move(int board[BOARD_SIZE][BOARD_SIZE], int difficulty, int is_maximizing_player);
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]);
int evaluate(int board[BOARD_SIZE][BOARD_SIZE]);
void generate_moves(int board[BOARD_SIZE][BOARD_SIZE], int child_boards[MAX_MOVES][BOARD_SIZE][BOARD_SIZE], int *number_of_moves, int is_maximizing_player);
void copy_board(int source[BOARD_SIZE][BOARD_SIZE], int destination[BOARD_SIZE][BOARD_SIZE]);
Move minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing_player, int alpha, int beta);