// Andrew Humphreys CS 2560
// HW 2 Problem 2

# include <stdio.h>

int main()
{
	const float RISING_RATE	= 1.5;	// In mm/year

	printf("In %d years, the ocean will be %.1f millimeters higher than the current level.\n", 5, (5*RISING_RATE));
	printf("In %d years, the ocean will be %.1f millimeters higher than the current level.\n", 7, (7*RISING_RATE));
	printf("In %d years, the ocean will be %.1f millimeters higher than the current level.\n", 10, (10*RISING_RATE));

	return 0;
}

