#include<stdio.h>
#include<stdlib.h>

#define n 8

void check_lose(int **board, int *row, int *col, int *win, int *lose);

void generateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

void NewgenerateRowAndColNames(int choice, int *rowValue, int *colValue, int *array2, int *array3);

int getUserInput();

void mover(int **board, int *row, int *col, int direction);

void printBoard(int **board);

void pawnsMove(int **board, int *row, int *col, int direction);

int logic();

int rowValue = 0;
int colValue = 0;

int userChoice;
int col1 = 7;
int col2 = 5;
int col3 = 3;
int col4 = 1;
int row1=0;
int row2=0;
int row3=0;
int row4=0;

int rowW = 7; // Initial position for 'F'
int colW = 4;

int number = 2; //priority value

int **board = (int **)calloc(n, sizeof(int *));

int win = 0;
int lose = 0;

int move;
