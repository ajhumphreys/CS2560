// Andrew Humphreys CS 2560
// HW 3 Problem 3


# include "project1header.h"

int main()
{
	FILE *fp;
	float rowPrice[ROWS];
	fp = fopen("ticketPrices.txt", "r");

	for(int i = 1; i < ROWS; i++)
	{
		fscanf(fp, "%f/n", &rowPrice[i]);
	}

	fclose(fp);

	char theater[ROWS][COLS];
	char empty = '*';
	char fill = '#';
	int seatNum[COLS];
	int seatNumBuy;
	int rowBuy;
	int seatStartBuy;

	float sale;
	float totalSale;

	int emptySeats;
	int takenSeats;

	int emptySeatsRow[ROWS];
	int takenSeatsRow[ROWS];

	char emptyChoice;
	int rowChoice;

	int choice;
	char buySeats;
	char yesOrNo[4] = {'Y','y','N','n'};
	int run = 1;

	emptySeats = ROWS*COLS;
	takenSeats = 0;

	NumArFill(emptySeatsRow, ROWS, COLS);
	NumArFill(takenSeatsRow, ROWS, 0);

	CharArInit2D(theater, empty);
	NumArInit(seatNum, COLS);

	while(run == 1)
	{
		choice = GetChoice();

		switch(choice)
		{
		case 1:
			buySeats = 'y';
			while(buySeats == 'y')
			{
				PrintSeats(theater, seatNum);

				printf("\n");

				GetSeats(theater, &seatNumBuy, &rowBuy, &seatStartBuy, empty);

				for(int i = seatStartBuy; i < seatStartBuy + seatNumBuy; i++)
				{
					ChangeElement(theater, rowBuy - 1, i - 1, fill);
				}

				sale = seatNumBuy * rowPrice[rowBuy];
				totalSale += sale;

				emptySeats -= seatNumBuy;
				takenSeats += seatNumBuy;

				emptySeatsRow[rowBuy - 1] -= seatNumBuy;
				takenSeatsRow[rowBuy - 1] += seatNumBuy;

				printf("\nTotal: $%.2f\n\n", sale);
				PrintSeats(theater, seatNum);

				printf("\n");
				buySeats = GetChar("Buy more seats? (Y/N): ", yesOrNo, 4, "Error! Please enter Y for yes or N for no.\n");

			}

			break;

		case 2:
			printf("\nTotal Sales For Show: $%.2f\n\n", totalSale);
			break;

		case 3:
			printf("\nSeats Sold: %d\n\n", takenSeats);
			break;

		case 4:
			emptyChoice = GetEmptyChoice();
			emptyChoice = tolower(emptyChoice);
			switch(emptyChoice)
			{
			case 'a':
				printf("Number Of Empty Seats In Entire Theater: %d\n\n", emptySeats);
				break;

			case 'r':
				rowChoice = GetInt("Select Row to View: ", 1, 15, "Error! Invalid Row! Please Try Again.\n");
				printf("Number Of Empty Seats In Row %d: %d\n\n", rowChoice, emptySeatsRow[rowChoice - 1]);
				break;

			default:
				printf("Error! Invalid Selection!\n");
				break;
			}
			break;

		case 5:
			run = 0;
			break;

		default:
			printf("Error! Please Enter a Valid Choice (1-5)\n\n");
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

void PrintSeats(char ar1[ROWS][COLS], int ar2[])
{
	// Title
	printf("\t\t    Seats\n\t");

	// Seat Number
	for(int a = 0; a < COLS; a++)
	{
		printf("%d", ar2[a]);
	}
	printf("\n");


	for(int i = 0; i < ROWS; i++)
	{
		// Row Number
		printf("Row %d\t", i + 1);

		// Each Seat
		for(int j = 0; j < COLS; j++)
		{
			printf("%c",ar1[i][j]);
		}
		printf("\n");
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

void PrintFlAr1D(float ar[], int size)
{
	for(int i = 0; i < size; i++)
			{
				printf("%.2f ",ar[i]);
			}
		printf("\n");
}

void NumArInit(int ar[], int size)
{
	for(int i = 0; i < size; i++)
	{
		ar[i] = (i+1)%10;
	}
}

void NumArFill(int ar[], int size, int fill)
{
	for(int i = 0; i < size; i++)
	{
		ar[i] = fill;
	}
}

void FloatArInit(float ar[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("Row #%d: ", i+1);
		fflush(stdout);
		scanf(" %f", &ar[i]);
	}
}

void ChangeElement(char ar[ROWS][COLS], int row, int col, char c)
{
	ar[row][col] = c;
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


void GetSeats(char ar[ROWS][COLS], int *seatNum, int *row, int *colStart, char empty)
{
	int valid = 0;
	char *prompt[100];

	do
	{
		*seatNum = GetInt("Enter the number of seats you want to buy: ", 1, 30, "Error! Invalid Number of Seats! Try Again.\n");
		*row = GetInt("Enter Row Number: ", 1, 15, "Error! Invalid Row Number! Try Again.\n");

		if(*seatNum == 1)
		{
			*prompt = "Enter Seat Number: ";
		}
		else
		{
			*prompt = "Enter Leftmost Seat In Row: ";
		}

		*colStart = GetInt(*prompt, 1, COLS + 1 - *seatNum, "Error! Invalid Number of Seats! Try Again.\n");

		valid = EmptyCheck(ar, *row - 1, *colStart - 1, *seatNum, empty);

		if(!valid)
		{
			printf("\nThe seats are already taken. Please try again.\n\n");
		}

	}while(!valid);
}

int GetInt(char prompt[], int min, int max, char error[])
{
	int i;

	do
	{
		printf("%s", prompt);
		fflush(stdout);
		scanf(" %d", &i);
		if(i < min || i > max)
		{
			printf("%s",error);
		}

	}while(i < min || i > max);

	return i;
}

char GetChar(char prompt[], char good[], int size, char error[])
{
	char c;
	int invalid = 1;

	do
	{
		printf("%s", prompt);
		fflush(stdout);
		scanf(" %c", &c);

		int i = 0;

		while(i < size && invalid)
		{
			if(c == good[i])
			{
				invalid = 0;
			}
			i++;
		}
		if(invalid)
		{
			printf("%s",error);
		}
	}while(invalid);

	return c;
}

int GetChoice()
{

	int choice;

	printf("Theater Seating\n\n");
	printf("\t1. Purchase Seats\n");
	printf("\t2. View Sales\n");
	printf("\t3. View Number of Seats Sold\n");
	printf("\t4. View Available Seats\n");
	printf("\t5. Quit\n\n");
	printf("\tEnter your choice (1-5): ");
	fflush(stdout);

	scanf(" %d",&choice);

	printf("\n");

	return choice;
}

int CharRowCheck(char ar[ROWS][COLS], int row, int same[COLS], char check, int *taken)
{
	int numSame;
	*taken = 0;

	// Initializes array to one to assume row contains all same char
	NumArFill(same, COLS, 0);

	// Loops through each row
	for(int i = 0; i < COLS; i++)
	{
			// If two elements are not the same it changes the same array to zero so the loop will stop checking
		if(ar[row][i] == check)
		{
			same[i] = 1;
			numSame++;
			*taken = 1;
		}

	}
	return numSame;
}

int EmptyCheck(char ar[ROWS][COLS], int row, int start, int num, char empty)
{
	int isEmpty = 1;
	int i = start;

	while(i < start + num && isEmpty)
	{
		if(ar[row][i] != empty)
		{
			isEmpty = 0;
		}
		i++;
	}
	return isEmpty;
}

char GetEmptyChoice()
{

	char choice;

	printf("Press 'A' to view the number of seats available in the entire theater.\n");
	printf("Press 'R' to view the number of seats available in a specific row.\n");
	printf("Enter your choice: ");
	fflush(stdout);

	scanf(" %c",&choice);

	printf("\n");

	return choice;
}
