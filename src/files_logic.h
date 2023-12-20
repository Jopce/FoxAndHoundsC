#define n 8

void check_lose(int **board, int *row, int *col, int *win, int *lose);

void generateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

void NewgenerateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

int getUserInput();

void mover(int **board, int *row, int *col, int direction);

void printBoard(int **board);

void pawnsMove(int **board, int *row, int *col, int direction);

int logic();
