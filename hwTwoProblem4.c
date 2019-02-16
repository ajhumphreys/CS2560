// Andrew Humphreys CS 2560
// HW 2 Problem 4

# include <stdio.h>

int main()
{
	const int SIZE = 10;

	char fill1 = '+';
	char fill2 = ' ';



		for(int i = 0; i < SIZE; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				printf("%c", fill1);
			}
			for(int k = (SIZE - i); k > 0; k--)
			{
				printf("%c", fill2);
			}

			printf("\t");

			for(int k = (SIZE - i); k > 0; k--)
			{
				printf("%c", fill1);
			}
			for(int j = 0; j < i; j++)
			{
				printf("%c", fill2);
			}


			printf("\n");
		}



	printf("\n");
	return 0;
}
