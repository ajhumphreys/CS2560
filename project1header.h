
#ifndef PROJECT1HEADER_H_
#define PROJECT1HEADER_H_

# include <stdio.h>
# include <ctype.h>

int ROWS = 15;
int COLS = 30;

# include <stdio.h>
# include <ctype.h>

void CharArInit2D(char ar[ROWS][COLS], char fill);	// Fills a 2D array with a character
void PrintSeats(char ar1[ROWS][COLS], int ar2[]);	// Prints title, array that shows seat number, row number, and all the seats
void PrintIntAr1D(int ar[], int size);
void PrintFlAr1D(float ar[], int size);
void NumArInit(int ar[], int size);
void NumArFill(int ar[], int size, int fill);
void FloatArInit(float ar[], int size);
int In2DArrayCheck(char ar1[ROWS][COLS], int ar2[], int size);
void ChangeElement(char ar[ROWS][COLS], int row, int col, char c);
int GetInt(char prompt[], int min, int max, char error[]);
void GetSeats(char ar[ROWS][COLS], int *seatNum, int *row, int *colStart, char empty);
int GetChoice();
char GetChar(char prompt[], char good[], int size, char error[]);
int EmptyCheck(char ar[ROWS][COLS], int row, int start, int num, char empty);
char GetEmptyChoice();

#endif
