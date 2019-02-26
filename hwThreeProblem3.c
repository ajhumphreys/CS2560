// Andrew Humphreys CS 2560
// HW 3 Problem 3

# include <stdio.h>
# include <ctype.h>

int ROWS = 3;
int COLS = 3;

char GetChoice();
void GetNumAr(int ar[]);

void PrintIntAr1D(int ar[], int size);
void PrintCharAr1D(char ar[], int size);

void CharArInit2D(char ar[ROWS][COLS], char fill);
void PrintCharAr2D(char ar[ROWS][COLS]);
void MakeMove(char ar[ROWS][COLS], int row, int col, char c);
void WinCheck(char ar[ROWS][COLS], char *winner);

void CharRowCheck(char ar[ROWS][COLS], int same[ROWS], char c[ROWS]);
void CharColCheck(char ar[ROWS][COLS], int same[COLS], char c[COLS]);
void CharDiagCheck(char ar[ROWS][COLS], int same[2], char c[2]);

void IntArInit1D(int ar[], int size, int fill);
void CharArInit1D(char ar[], int size, char fill);

int In2DArrayCheck(char ar1[ROWS][COLS], int ar2[], int size);
int ArrayCheck(char ar1[ROWS][COLS], int ar2[], char empty);

int main()
{
	char board[ROWS][COLS];
	char empty = '*';
	char winner = '*';

	char PLAYER1 = 'X';
	char PLAYER2 = 'O';

	char playerTurn = PLAYER1;
	int playerNum;

	int turnCount = 1;
	int MIN_WIN = 5;
	int MAX_TURNS = 9;

	int move[2];
	int run = 1;
	char play;

	int inBoard;
	int emptySpace;

	while(run == 1)
	{

		// Prompts the user if they want to play or not
		play = GetChoice();
		play = tolower(play);

		switch(play)
		{
		case 'n' :

			// sets turn to one, no winner, clears the board
			turnCount = 1;
			winner = '*';
			CharArInit2D(board, empty);

			// runs until the board is filled or there is a winner
			while(turnCount <= MAX_TURNS && winner == '*')
			{
				// changes the current player
				if(turnCount % 2 == 1)
				{
					playerTurn = PLAYER1;
					playerNum = 1;
				}
				else
				{
					playerTurn = PLAYER2;
					playerNum = 2;
				}

				printf("\nPlayer %d Turn\n\n", playerNum);

				printf("Board\n");
				PrintCharAr2D(board);
				printf("\n");

				// Explains how to enter moves better if it's the first turn
				if(turnCount == 1)
				{
					printf("Enter your move by entering the row then the column of the space you want\n");
					printf("([0,0] is the top left corner.)\n");
				}
				else
				{
					printf("Enter your move\n");
				}


				// Gets the move from player. Move must be in an empty space in the board
				do
				{
					GetNumAr(move);
					inBoard = In2DArrayCheck(board, move, 2);
					emptySpace = ArrayCheck(board, move, empty);
					if(inBoard == 0 || emptySpace == 0)
					{
						printf("\nError! Invalid Move. Try Again\n");
					}
				}while(inBoard == 0 || emptySpace == 0);

				MakeMove(board, move[0], move[1], playerTurn);

				// Checks if someone has won if it is possible for someone to have won
				if(turnCount >= MIN_WIN)
				{
					WinCheck(board, &winner);
					// If there is a winner it will end the game and enter victory message
					if(winner != '*')
					{
						printf("\nPlayer %d has won!\n", playerNum);
						printf("Board\n");
						PrintCharAr2D(board);
						printf("\n");
					}
					// If there is no winner and the maximum number of turns has happened then it is a stalemate
					else if(turnCount == MAX_TURNS)
					{
						printf("\nStalemate!\n");
						printf("Board\n");
						PrintCharAr2D(board);
						printf("\n");
					}
				}

				turnCount++;

			}
			break;

		case 'x' :
			run = 0;
			break;

		default :
			printf("Error! Please Enter a Valid Choice (N or X)\n\n");
			break;
		}

	}
	return 0;
}

void CharArInit2D(char ar[ROWS][COLS], char fill)
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			ar[i][j] = fill;
		}
	}
}

void PrintCharAr2D(char ar[ROWS][COLS])
{
	for(int i = 0; i < ROWS; i++)
		{
			for(int j = 0; j < COLS; j++)
			{
				printf("%c ",ar[i][j]);
			}
			printf("\n");
		}
}

void MakeMove(char ar[ROWS][COLS], int row, int col, char c)
{
	ar[row][col] = c;
}

void WinCheck(char ar[ROWS][COLS], char *winner)
{
	int sameRC[ROWS];
	char cRC[ROWS];

	int sameD[2];
	char cD[2];

	// will run checks if there is no winner yet
	if(*winner == '*')
	{
		CharRowCheck(ar, sameRC, cRC);
		for(int i = 0; i < ROWS; i++)
		{
			if(sameRC[i] == 1 && cRC[i] != '*')
			{
				*winner = cRC[i];
			}
		}
	}

	if(*winner == '*')
	{
		CharColCheck(ar, sameRC, cRC);
		for(int i = 0; i < COLS; i++)
		{
			if(sameRC[i] == 1 && cRC[i] != '*')
			{
				*winner = cRC[i];
			}
		}
	}

	if(*winner == '*')
	{
		CharDiagCheck(ar, sameD, cD);
		for(int i = 0; i < 2; i++)
		{
			if(sameD[i] == 1 && cD[i] != '*')
			{
				*winner = cD[i];
			}
		}
	}


}

void CharRowCheck(char ar[ROWS][COLS], int same[ROWS], char c[ROWS])
{
	// Initializes array to one to assume row contains all same char
	IntArInit1D(same, ROWS, 1);
	// Initializes array to !, This will change if a row has same char
	CharArInit1D(c, ROWS, '!');

	int j;

	// Loops through each row
	for(int i = 0; i < ROWS; i++)
	{
		j = 1;

		// Runs to check each column until it finds that two elements in row are not same
		while(j < COLS && same[i])
		{
			// If two elements are not the same it changes the same array to zero so the loop will stop checking
			if(ar[i][j-1] != ar[i][j])
			{
				same[i] = 0;
			}
			j++;

		}

		// if element in same is still 1, all elements in row are same and it stores the value of that same char
		if(same[i])
		{
			c[i] = ar[i][j-1];
		}
	}
}

void CharColCheck(char ar[ROWS][COLS], int same[COLS], char c[COLS])
{
	// Initializes array to one to assume col contains all same char
	IntArInit1D(same, COLS, 1);
	// Initializes array to !, This will change if a col has same char
	CharArInit1D(c, COLS, '!');

	int i;

	// Loops through each col
	for(int j = 0; j < COLS; j++)
	{
		i = 1;

		// Runs to check each row until it finds that two elements in col are not same
		while(i < ROWS && same[j])
		{
			// If two elements are not the same it changes the same array to zero so the loop will stop checking
			if(ar[i-1][j] != ar[i][j])
			{
				same[j] = 0;
			}
			i++;

		}

		// if element in same is still 1, all elements in col are same and it stores the value of that same char
		if(same[j])
		{
			c[j] = ar[i-1][j];
		}
	}
}


void CharDiagCheck(char ar[ROWS][COLS], int same[2], char c[2])
{
	// Initializes array to one to assume diagonals contain all same char
	IntArInit1D(same, 2, 1);
	// Initializes array to !, This will change if a diagonal has same char
	CharArInit1D(c, 2, '!');

	int i = 1;

	// Runs to check if each element in main diagonal is same
	while(i < ROWS && same[0])
	{
		// If two elements are not the same it changes the same array to zero so the loop will stop checking
		if(ar[i-1][i-1] != ar[i][i])
		{
			same[0] = 0;
		}
		i++;

	}

	// if element in same is still 1, all elements in row are same and it stores the value of that same char
	if(same[0])
	{
		c[0] = ar[i-1][i-1];
	}

	int j = 1;

	// Runs to check if each element in main diagonal is same
	while(j < ROWS && same[1])
	{

		// If two elements are not the same it changes the same array to zero so the loop will stop checking
		if(ar[j-1][ROWS-j] != ar[j][ROWS-(j+1)])
		{
			same[1] = 0;
		}
		j++;

	}

	// if element in same is still 1, all elements in row are same and it stores the value of that same char
	if(same[1])
	{
		c[1] = ar[j-1][0];
	}
}

void IntArInit1D(int ar[], int size, int fill)
{
	for(int i = 0; i < size; i++)
	{
		ar[i] = fill;
	}
}

void CharArInit1D(char ar[], int size, char fill)
{
	for(int i = 0; i < size; i++)
	{
		ar[i] = fill;
	}
}

void PrintIntAr1D(int ar[], int size)
{
	for(int i = 0; i < size; i++)
		{
			printf("%d ",ar[i]);
		}
	printf("\n");
}

void PrintCharAr1D(char ar[], int size)
{
	for(int i = 0; i < size; i++)
		{
			printf("%c ",ar[i]);
		}
	printf("\n");
}

char GetChoice()
{

	char choice;

	printf("     TIC TAC TOE\n\n");
	printf("Press 'N' for New Game\n");
	printf("Press 'X' to Exit:\n\n");
	printf("Selection: ");
	fflush(stdout);

	scanf(" %c", &choice);

	return choice;
}

void GetNumAr(int ar[])
{

	printf("Row: ");
	fflush(stdout);
	scanf(" %d", &ar[0]);

	printf("Column: ");
	fflush(stdout);
	scanf(" %d", &ar[1]);

}

int In2DArrayCheck(char ar1[ROWS][COLS], int ar2[], int size)
{
	int isValid = 1;

	for(int i = 0; i < size; i++)
	{
		if(ar2[i] >= ROWS && ar2[i] >= COLS)
		{
			isValid = 0;
		}
	}


	return isValid;
}

int ArrayCheck(char ar1[ROWS][COLS], int ar2[], char empty)
{
	int isValid = 1;

	if(ar1[ar2[0]][ar2[1]] != empty)
	{
		isValid = 0;
	}

	return isValid;
}
