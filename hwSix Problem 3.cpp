// hwSix Problem 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Employee
{
private:
	std::string name;
	int	num;
	int hireDay;
	int hireMonth;
	int hireYear;

public:
	// Constructor
	Employee(std::string na, int nu, int d, int m, int y)
	{
		name = na;
		hireDay = d;
		hireMonth = m;
		hireYear = y;

		if (nu < 0 || nu > 9999)
		{
			std::string exception = "Error! Employee number must be between 0 and 9999.\n\n";
			throw exception;
		}
		else
		{
			num = nu;
		}
	}

	// Default Constructor
	Employee()
	{
		name = " ";
		num = 0;
		hireDay = 0;
		hireMonth = 0;
		hireYear = 0;
	}

	// Accessor Functions
	std::string GetName()
	{
		return name;
	}

	int GetNum()
	{
		return num;
	}

	int GetDay()
	{
		return hireDay;
	}

	int GetMonth()
	{
		return hireMonth;
	}

	int GetYear()
	{
		return hireYear;
	}

	// Mutator Functions
	void SetName(std::string n)
	{
		name = n;
	}

	void SetNum(int n)
	{

		if (n < 0 || n > 9999)
		{
			std::string exception = "Error! Employee number must be between 0 and 9999.\n\n";
			throw exception;
		}
		else
		{
			num = n;
		}
	}

	void SetDay(int d)
	{
		hireDay = d;
	}

	void SetMonth(int m)
	{
		hireMonth = m;
	}

	void SetYear(int y)
	{
		hireYear = y;
	}
};

class ProductionWorker : public Employee
{
private:
	int shift;
	float payRate;

public:
	// Constructor
	ProductionWorker(int s, float p, std::string na, int nu, int d, int m, int y) : Employee(na, nu, d, m, y)
	{
		if (s != 1 && s != 2)
		{

			std::string exception = "Error! Shift can only by 1 or 2.\n\n";
			throw exception;
		}
		else
		{
			shift = s;
		}

		if (p < 0)
		{
			std::string exception = "Error! Pay Rate must be positive.\n\n";
			throw exception;
		}
		else
		{
			payRate = p;
		}
	
	}

	// Default Constructor
	ProductionWorker() : Employee()
	{
		shift = 0;
		payRate = 0;
	}

	//Accessor Fuctions
	int GetShift()
	{
		return shift;
	}

	float GetPayRate()
	{
		return payRate;
	}

	//Mutator Fuctions
	void SetShift(int s)
	{
		if (s != 1 && s != 2)
		{
			
			std::string exception = "Error! Shift can only by 1 or 2.\n\n";
			throw exception;
		}
		else
		{
			shift = s;
		}
	
	}

	void SetPayRate(float p)
	{
		
		if (p < 0)
		{
			std::string exception = "Error! Pay Rate must be positive.\n\n";
			throw exception;
		}
		else
		{
			payRate = p;
		}
	}

};

int main()
{
	std::string name = "Steve";
	int	num = -1;
	int hireDay = 8;
	int hireMonth = 21;
	int hireYear = 2016;
	int shift = 0;
	float payRate = 11.50;

	ProductionWorker p1;

	try
	{
		ProductionWorker p1(1, 11.50, "Steve", 900, 1, 1, 2018);
		std::cout << "Successfully Constructed\n\n";
	}
	catch (std::string exception)
	{
		std::cout << exception;
	}

	try
	{
		p1.SetNum(10000);
		std::cout << "Successfully Changed Number\n\n";
	}
	catch (std::string exception)
	{
		std::cout << exception;
	}

	try
	{
		p1.SetShift(0);
		std::cout << "Successfully Changed Shift\n\n";
	}
	catch (std::string exception)
	{
		std::cout << exception;
	}

	try
	{
		p1.SetPayRate(-1);
		std::cout << "Successfully Changed Pay Rate\n\n";
	}
	catch (std::string exception)
	{
		std::cout << exception;
	}

	return 0;
}

