// Andrew Humphreys CS 2560
// In Class 2

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee
{
private:
	string name;	//Employee's Name
	int idNumber;	//Employee's ID Number
	string department;	//Employee's Department where they work
	string position;	//Employee's Job Title

public:

	Employee(string n, int i, string d, string p)
	{
		name = n;
		idNumber = i;
		department = d;
		position = p;
	}
	Employee(string n, int i)
	{
		name = n;
		idNumber = i;
		department = " ";
		position = " ";
	}
	Employee()
	{
		name = " ";
		idNumber = 0;
		department = " ";
		position = " ";
	}

	string GetName()
	{
		return name;
	}
	int GetID()
	{
		return idNumber;
	}
	string GetDepart()
	{
		return department;
	}
	string GetPos()
	{
		return position;
	}
};



int main()
{
	const int width1 = 15;
	const int width2 = 15;
	const int width3 = 15;
	const int width4 = 15;

	Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee emp2("Mark Jones", 39119, "IT", "Programmer");
	Employee emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	cout << left;
	cout << setw(width1) << "Name" << setw(width2) << "ID Number" << setw(width3) << "Department" << setw(width4) << "Position" << endl;
	cout << setw(width1) << emp1.GetName() << setw(width2) << emp1.GetID() << setw(width3) << emp1.GetDepart() << setw(width4) << emp1.GetPos() << endl;
	cout << setw(width1) << emp2.GetName() << setw(width2) << emp2.GetID() << setw(width3) << emp2.GetDepart() << setw(width4) << emp2.GetPos() << endl;
	cout << setw(width1) << emp3.GetName() << setw(width2) << emp3.GetID() << setw(width3) << emp3.GetDepart() << setw(width4) << emp3.GetPos() << endl;


	return 0;
}

