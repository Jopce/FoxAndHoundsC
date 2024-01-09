#define n 8

typedef int** Board;

void Pwin_lose(int *win, int *lose, int *number);

void freeMemory(Board board, int *array2, int *array3);

Board allocateBoard();

void save_game(int *array2,int *array3, int *rowW, int *colW, int *player);

void processInput(int *save, int *array2, int *array3, int *rowW, int *colW, int *player);

void displayLastModifiedTime();

void check_lose(Board board, int *row, int *col, int *win, int *lose);

void generateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

void NewgenerateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

int getUserInput();

void fMove(Board board, int *row, int *col, int direction, int *player);

void printBoard(Board board);

void hMove(Board board, int *row, int *col, int direction, int *player);
