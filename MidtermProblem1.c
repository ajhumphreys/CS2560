// Andrew Humphreys CS 2560
// Midterm Problem 1

# include <stdio.h>


int main()
{
	int SIZE = 10;

	printf("     ");


	for(int i = 0; i < SIZE; i++)
	{
		printf("%4d", (i + 1));
	}

	printf("\n");

	printf("    +");
	printf("----------------------------------------");

	printf("\n");

	for(int i = 0; i < SIZE; i++)
	{
		printf("%4d|", (i + 1));

		for(int j = 0; j < SIZE; j++)
		{
			printf("%4d", ((i + 1)*(j + 1)));
		}
		printf("\n");
	}
	return 0;
}


