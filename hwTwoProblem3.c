// Andrew Humphreys CS 2560
// HW 2 Problem 3

# include <stdio.h>

int main()
{
	const int SHARES = 1000;
	const float SHARE_PRICE_BUY = 45.50;
	const float SHARE_PRICE_SELL = 56.90;
	const float COMMISSION = 0.02;

	float paid;
	float comBuy;
	float sold;
	float comSell;
	float profit;

	paid = SHARES*SHARE_PRICE_BUY;
	comBuy = paid*COMMISSION;

	sold = SHARES*SHARE_PRICE_SELL;
	comSell = sold*COMMISSION;

	profit = (sold - paid - comBuy - comSell);


	printf("Joe Paid: \t\t$%10.2f\n", paid);

	printf("Paid Commission: \t$%10.2f\n", comBuy);

	printf("Joe Sold: \t\t$%10.2f\n", sold);

	printf("Sold Commission: \t$%10.2f\n", comSell);

	printf("Joe's Profit: \t\t$%10.2f\n", profit);

	return 0;
}

