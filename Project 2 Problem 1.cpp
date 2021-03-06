// Andrew Humphreys CS 2560
// Project 2 Problem 1

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
private:
	int month;	// Month of the date
	int day;	// Day of the date
	int year;	// Year of the date
	//int maxNum;	// Variable that holds the index of the maximum days in the month

	const int minDay = 1;					// Minimum amount of days
	const int maxDay[4] = {28, 29, 30, 31};	// Array that holds the maximum amount of days for months
	const int minMonth = 1;					// Minimum amount of months
	const int maxMonth = 12;				// Maximum amount of months
	const string monthAr[13] = {"Error", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};	// String for all month names

public:
	// Constructor to set the month day and year
	Date(int m, int d, int y)
	{
		// Sets the year
		year = y;

		if (ValidDate(m, d, y))
		{
			month = m;
			day = d;
		}
		else
		{
			month = 0;
			day = 0;
		}


	}

	// Default constructor
	Date()
	{
		month = 1;
		day = 1;
		year = 2000;
	}

	// Sets the index of maxDay depending on the month
	int FindMaxDays(int m, int y)
	{
		int maxNum;

		if (m == 2)
		{
			if (y % 4 == 0)
			{
				maxNum = 1;
			}
			else
			{
				maxNum = 0;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			maxNum = 2;
		}
		else
		{
			maxNum = 3;
		}

		return maxNum;
	}

	// Used to see if the date is possible
	bool ValidDate(int m, int d, int y)
	{
		bool valid = true;

		// Turns valid to false if month is outside of range
		if (m < minMonth || m > maxMonth)
		{
			valid = false;
		}

		// Sets day unless it is outside the valid range
		if (d < minDay || d > maxDay[FindMaxDays(m,y)])
		{
			valid = false;
		}

		return valid;
	}

	// Set the month
	void SetMonth(int m)
	{
		if (ValidDate(m, day, year))
		{
			month = m;
		}
		else
		{
			month = 0;
		}
		
	}

	// Set the day
	void SetDay(int d)
	{
		if (ValidDate(month, d, year))
		{
			day = d;
		}
		else
		{
			day = 0;
		}

	}

	// Set the year
	void SetYear(int y)
	{
		year = y;
	}

	// Print the date as mm/dd/yyyy.
	void PrintDateNum()
	{
		cout << setw(2) << setfill('0') << month << "/";
		cout << setw(2) << setfill('0') << day << "/";
		cout << year;
	}

	// Print the date by US standards, Month Day, Year.
	void PrintDateUS()
	{
		cout << monthAr[month] << " " << day << ", " << year;
	}

	// Print the date by international standards, Day Month Year.
	void PrintDateIntl()
	{
		cout << day << " " << monthAr[month] << " " << year;
	}
	
	// Overloaded operator functions
	Date operator++(int)
	{
		Date temp(month , day, year);
		
		if (ValidDate(month, day + 1, year))
		{
			day++;
		}
		else if(ValidDate(month + 1, 1, year))
		{
			day = 1;
			month++;
		}
		else
		{
			day = 1;
			month = 1;
			year++;
		}
		

		return temp;
	}

	Date operator--(int)
	{
		Date temp(month, day, year);

		if (ValidDate(month, day - 1, year))
		{
			day--;
		}
		else if (ValidDate(month - 1, maxDay[FindMaxDays(month - 1, year)], year))
		{
			day = maxDay[FindMaxDays(month - 1, year)];
			month--;
		}
		else
		{
			day = 31;
			month = 12;
			year--;
		}


		return temp;
	}

	bool operator==(const Date &right)
	{
		bool status;

		if (month == right.month && day == right.day && year == right.year)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	bool operator>(const Date &right)
	{
		bool status;

		if (year > right.year)
		{
			status = true;
		}
		else if (year == right.year && month > right.month)
		{
			status = true;
		}
		else if (year == right.year && month == right.month && day > right.day)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	bool operator<(const Date &right)
	{
		bool status;

		if (year < right.year)
		{
			status = true;
		}
		else if (year == right.year && month < right.month)
		{
			status = true;
		}
		else if (year == right.year && month == right.month && day < right.day)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	int operator-(const Date &right)
	{
		int count = 0;

		Date left(month, day, year);
		
		if (left > right)
		{
			while (left > right)
			{
				left--;
				count++;
			}
		}
		else
		{
			while (left < right)
			{
				left++;
				count++;
			}
		}

		return count;

	}

	friend ostream& operator<<(ostream& os, const Date& date)
	{
		os << date.monthAr[date.month] << " " << date.day << ", " << date.year;
		return os;
	}

	friend istream &operator >> (istream& is, Date& date)
	{
		int dateAr[3];

		// Prompt the user for the month.
		cout << "Month Number: ";
		is >> dateAr[0];

		// Prompt the user for the day.
		cout << "Day: ";
		is >> dateAr[1];

		// Prompt the user for the year.
		cout << "Year: ";
		is >> dateAr[2];

		// Makes sure a valid date is entered. Puts 0 for month or day if invalid.
		date.SetMonth(dateAr[0]);
		date.SetDay(dateAr[1]);
		date.SetYear(dateAr[2]);

		return is;
	}
};


int main()
{
	Date d1;
	Date d2;

	cout << "Please Enter Two Dates\n";
	cout << "\nDate 1\n";
	cin >> d1;
	cout << "\nDate 2\n";
	cin >> d2;

	cout << "\nThe dates you entered are:\n";
	cout << d1 << endl;
	cout << d2 << endl << endl;

	cout << "The day before the first date is:\n";
	d1--; 
	cout << d1 << endl << endl;

	cout << "The day after the first date is:\n";
	d1++;
	d1++;
	cout << d1 << endl << endl;

	d1--;
	cout << "There are " << (d1 - d2) << " days between the two days \n";

	return 0;
}
