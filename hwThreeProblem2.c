// Andrew Humphreys CS 2560
// HW 3 Problem 2

# include <stdio.h>

void GetLL(long long *l, char prompt[], long long *er);
void GetInt(int *i, char prompt[], int er);
void GetFloat(float *f, char prompt[], float er);
long long PopCalc(long long p, float br, float dr, int y);
float PerToDec(float p);


int main()
{
	char run = 'y';
	long long startPop;
	float birthRate;
	float deathRate;
	int years;
	long long finalPop;

	long long minPop = 2;
	int minRate = 0;
	int minYear = 1;

	char prompt1[100] = "Enter the Starting Population: ";
	char prompt2[100] = "Enter the Birth Rate as a Percentage: ";
	char prompt3[100] = "Enter the Death Rate as a Percentage: ";
	char prompt4[100] = "Enter the Number of Years to Display: ";

	while(run == 'y' || run == 'Y')
	{
		GetLL(&startPop, prompt1, &minPop);

		GetFloat(&birthRate, prompt2, minRate);
		birthRate = PerToDec(birthRate);

		GetFloat(&deathRate, prompt3, minRate);
		deathRate = PerToDec(deathRate);

		GetInt(&years, prompt4, minYear);

		finalPop = PopCalc(startPop, birthRate, deathRate, years);

		printf("\nThe population after %d year(s) is %lld.\n\n", years, finalPop);

		printf("Would you like to run the program again? (y/n) ");
		fflush(stdout);
		scanf(" %c",&run);
		printf("\n");
	}

	return 0;
}

void GetLL(long long *l, char prompt[], long long *er)
{
	do
	{
		printf("%s", prompt);
		fflush(stdout);
		scanf(" %lld", l);
		if(*l < *er)
		{
			printf("Error! Value Must Be Greater Than %lld.\n\n", *er);
		}
	}while(*l < *er);
}

void GetInt(int *i, char prompt[], int er)
{
	do
	{
		printf("%s", prompt);
		fflush(stdout);
		scanf(" %d", i);
		if(*i < er)
		{
			printf("Error! Value Must Be Greater Than %d.\n\n", er);
		}
	}while(*i < er);
}

void GetFloat(float *f, char prompt[], float er)
{
	do
	{
		printf("%s", prompt);
		fflush(stdout);
		scanf(" %f", f);
		if(*f < er)
		{
			printf("Error! Value Must Be Greater Than %f.\n\n", er);
		}
	}while(*f < er);
}

long long PopCalc(long long p, float b, float d, int y)
{
	for(int i = 1; i <= y; i++)
	{
		p = p + b*p - d*p;
	}

	return p;
}

float PerToDec(float p)
{
	return p/100;
}
