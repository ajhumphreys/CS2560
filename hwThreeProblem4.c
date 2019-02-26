// Andrew Humphreys CS 2560
// HW 3 Problem 3

#include <stdio.h>

void ReverseIntArray(int ar[], int size);

int main()
{

	int array[5] = {1,2,3,4,5};

	ReverseIntArray(array, 5);

	return 0;
}

void ReverseIntArray(int ar[], int size)
{

	int revAR[size];

	for(int i = 0; i < size; i++)
	{
		revAR[i] = ar[size - i - 1];
		printf("%d ",revAR[i]);
	}

}
