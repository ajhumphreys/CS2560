// Andrew Humphreys CS 2560
// Project 2 Problem 2

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PatientAccount
{
private:
	float totalCharge;
	int dayTotal;
	const float dayRate = 10;

public:
	PatientAccount()
	{
		totalCharge = 0;
		dayTotal = 0;
	}

	void ChangeTotal(const float t)
	{
		totalCharge += t;
	}

	void ChangeDays(const int d)
	{
		dayTotal = d;
		ChangeTotal(dayTotal*dayRate);
	}

	void PrintTotal() 
	{
		cout << fixed << setprecision(2);
		cout << "\nTotal Charges: $" <<totalCharge << endl << endl;
	}

};

class Surgery
{
private:
	const float surgeryPrice[5] = {950, 700, 1000, 475, 1250};

public:
	Surgery(PatientAccount &p, const int s)
	{
		p.ChangeTotal(surgeryPrice[s]);
	}

};

class Pharmacy
{
private:
	const float medicationPrice[5] = { 57, 72, 43, 94, 66};

public:
	Pharmacy(PatientAccount &p, const int m)
	{
		p.ChangeTotal(medicationPrice[m]);
	}
};

int GetChoice(const string &prompt, const int min, const int max);

int main()
{
	int choiceP = 1;	// Variable for user to choose new patient
	int choiceC;		// Variable for user to choose to enter a surgery, medication, or check out
	int choiceS;		// Variable for user to choose which surgery
	int choiceM;		// Variable for user to choose which medication

	int days;	// Stores the number of days the patient was in the hospital

	// Strings to prompt user
	const string promptP = "\n\tPatient Menu\n\nWould you like to enter the information for a new patient?\n(1) New Patient\n(2) Quit\n\nChoice: ";
	const string promptC = "\n\tProcedure Menu\n\nPlease Select An Option:\n(1) Add Surgery\n(2) Add Medication\n(3) Check Out Patient\n\nChoice: ";
	const string promptS = "\n\tSurgery Menu\n\nPlease Select A Surgery For Patient:\n(1) Heart Surgery\n(2) Cataract Surgery\n(3) Spinal Surgery\n(4) Hip Surgery\n(5) Brain Surgery\n\nChoice: ";
	const string promptM = "\n\tMedication Menu\n\nPlease Select A Medication For Patient:\n(1) Morphine\n(2) Percocet\n(3) Asprin\n(4) Vicodin\n(5) Lipitor\n\nChoice: ";



	while (choiceP == 1)
	{
		// Prompts user  and creates new patient account
		choiceP = GetChoice(promptP, 1, 2);
		PatientAccount patient;

		// User chose new patient
		if (choiceP == 1)
		{
			choiceC = 1;

			// Allows user to keep inputing procedures
			while (choiceC != 3)
			{
				choiceC = GetChoice(promptC, 1, 3);
				
				// User chooses surgery
				if (choiceC == 1)
				{
					// User chooses which surgery and it adds it to the total
					choiceS = GetChoice(promptS, 1, 5);
					Surgery s(patient, choiceS - 1);
				}
				// User chooses medication
				else if (choiceC == 2)
				{
					// User chooses which medication and it adds it to the toal
					choiceM = GetChoice(promptM, 1, 5);
					Pharmacy m(patient, choiceM- 1);

				}
			}

			// Input number of days spent in the hospital
			cout << "\nEnter the number of days the patient stayed: ";
			cin >> days;
			
			// Adds the cost of the hospital stay and outputs total
			patient.ChangeDays(days);
			patient.PrintTotal();
		}
	}

	return 0;
}

// Function to get numerical choice within a certain range
int GetChoice(const string &prompt, const int min, const int max)
{
	bool invalid = 1;
	int choice;

	while (invalid)
	{
		cout << prompt;
		cin >> choice;

		if (choice >= min && choice <= max)
		{
			invalid = 0;
		}
		else
		{
			cout << "\nInvalid Choice. Please Try Again.\n\n";
		}
	}

	return choice;
}