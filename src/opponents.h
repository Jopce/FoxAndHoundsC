#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

#define BOARD_SIZE 8
#define MAX_MOVES 12

int opponent_move(int board[BOARD_SIZE][BOARD_SIZE], int difficulty);
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]);
