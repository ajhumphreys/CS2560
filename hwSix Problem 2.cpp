// Andrew Humphreys CS 2560 
// Homework Six Problem 2

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>       //we could have more then 1 typename so the letter T is arbitray ex: ,typename X 
T maxof(const T & a, const T & b) {

	return (a > b ? a : b);         //ternary operator 

}

template <typename T>
T minimum(const T & a, const T & b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename T>
T maximum(const T & a, const T & b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int int1 = 7;
	int int2 = 9;

	float float1 = 6.957;
	float float2 = 4.765;

	std::string string1 = "Football";
	std::string string2 = "Baseball";

	std::cout << "Integers\n\n";
	std::cout << "Min: " << minimum<int>(int1, int2) << std::endl;
	std::cout << "Max: " << maximum<int>(int1, int2) << std::endl << std::endl;

	std::cout << "Floats\n\n";
	std::cout << "Min: " << minimum<float>(float1, float2) << std::endl;
	std::cout << "Max: " << maximum<float>(float1, float2) << std::endl << std::endl;

	std::cout << "Strings\n\n";
	std::cout << "Min: " << minimum<std::string>(string1, string2) << std::endl;
	std::cout << "Max: " << maximum<std::string>(string1, string2) << std::endl << std::endl;

	return 0;
}

