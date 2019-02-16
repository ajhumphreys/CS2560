// Andrew Humphreys CS 2560
// HW 2 Problem 1

# include <stdio.h>

int main()
{
	const float SUBTOTAL	= 88.67;
	const float TAX_RATE	= 6.75;
	const float TIP_PERCENT	= 20;

	float tax;
	float tip;
	float total;

	tax = SUBTOTAL*TAX_RATE/100;
	tip = (SUBTOTAL + tax)*(TIP_PERCENT/100);
	total = SUBTOTAL + tax + tip;

	printf("\t BILL\n\n");
	printf("Subtotal \t%7.2f\n", SUBTOTAL);
	printf("Tax \t\t%7.2f\n", tax);
	printf("Tip \t\t%7.2f\n\n", tip);
	printf("Total \t\t%7.2f\n", total);

	return 0;
}
