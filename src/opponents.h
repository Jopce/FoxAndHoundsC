#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

#define BOARD_SIZE 8
#define MAX_MOVES 12
#define F 1
#define H 2

int opponent_move(int board[BOARD_SIZE][BOARD_SIZE], int difficulty);
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]);
int evaluate(int board[BOARD_SIZE][BOARD_SIZE]);
int generate_moves(int board[BOARD_SIZE][BOARD_SIZE], int child_boards[MAX_MOVES][BOARD_SIZE][BOARD_SIZE], int *number_of_moves);
