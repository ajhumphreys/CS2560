// Andrew Humphreys CS 2560 
// Homework Six Problem 4

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool IsPrime(const int n);

template <typename T>
void PrimeCheck(T &i)
{
	if (IsPrime(i))
	{
		std::cout << i << std::endl;
	}

}

template <typename T>
T getNum(T min)
{
	bool invalid = true;
	T num;

	do
	{
		std::cout << "Enter a number: ";
		std::cin >> num;

		if (num < min)
		{
			std::cout << "Error. Enter a number greater than " << min - 1 << ".\n\n";
		}
		else
		{
			invalid = false;
		}
	} while (invalid);
	
	return num;
}

int main()
{
	int max;
	
	std::vector<int> allNum;
	std::vector<int> prime;

	std::cout << "Prime Number Generation\n\n";
	max = getNum<int>(2);



	for (int i = 2; i <= max; i++)
	{
		allNum.push_back(i);
	}

	std::cout << "\nHere are the prime numbers in that range\n\n";

	for_each(allNum.begin(), allNum.end(), PrimeCheck<int>);
	   
	return 0;
}

bool IsPrime(const int n)
{
	bool prime = true;
	int i = 2;

	if (n < 2)
	{
		prime = false;
	}

	while(prime && i <= n/2)
	{
		if (n % i == 0)
		{
			prime = false;
		}
		i++;
	}

	return prime;
}