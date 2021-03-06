// Andrew Humphreys CS 2560
// Homework 5 Problem 3

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

class PersonData
{
private:
	std::string lastName;
	std::string firstName;
	std::string address;
	std::string city;
	std::string state;
	int zip;
	long long phone;

public:
	// Constructor
	PersonData(std::string l, std::string f, std::string a, std::string c, std::string s, int z, long long p)
	{
		lastName = l;
		firstName = f;
		address = a;
		city = c;
		state = s;
		zip = z;
		phone = p;
	}

	// Default Constructor
	PersonData()
	{
		lastName = " ";
		firstName = " ";
		address = " ";
		city = " ";
		state = " ";
		zip = 0;
		phone = 0;
	}

	// Get Functions
	const std::string & GetLastName() const { return lastName; }
	const std::string & GetFirstName() const { return firstName; }
	const std::string & GetAddress() const { return address; }
	const std::string & GetCity() const { return city; }
	const std::string & GetState() const { return state; }
	const int GetZip() const { return zip; }
	const long long & GetPhone() const { return phone; }

	// Set Functions
	void SetLastName(std::string l) { lastName = l; }
	void SetFirstName(std::string f) { firstName = f; }
	void SetAddress(std::string a) { address = a; }
	void SetCity(std::string c) { city = c; }
	void SetState(std::string s) { state = s; }
	void SetZip(int z) { zip = z; }
	void SetPhone(long long p) { phone = p; }
};

class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	// Constructor
	CustomerData(int n, bool m, std::string l, std::string f, std::string a, std::string c, std::string s, int z, long long p) : PersonData(l, f, a, c, s, z, p)
	{
		customerNumber = n;
		mailingList = m;
	}

	// Default Constructor
	CustomerData() : PersonData()
	{
		customerNumber = 0;
		mailingList = false;
	}

	// Get Functions
	const int GetNum() const { return customerNumber; }
	const bool GetMail() const { return mailingList; }

	// Set Functions
	void SetNum(int n) { customerNumber = n; }
	void SetMail(bool m) { mailingList = m; }
};

class PreferredCustomer : public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;
	double saleAmount;

	const double level1 = .05;
	const double level2 = .06;
	const double level3 = .07;
	const double level4 = .10;

	const int l1 = 500;
	const int l2 = 1000;
	const int l3 = 1500;
	const int l4 = 2000;


public:
	// Constructor
	PreferredCustomer(int n, bool m, std::string l, std::string f, std::string a, std::string c, std::string s, int z, long long p) : CustomerData(n, m, l, f, a, c, s, z, p)
	{
		purchasesAmount = 0;
		discountLevel = 0;
		saleAmount = 0;
	}

	// Default Constructor
	PreferredCustomer() : CustomerData()
	{
		purchasesAmount = 0;
		discountLevel = 0;
		saleAmount = 0;
	}

	void NewPurchase(double amount)
	{
		if (amount >= 0)
		{
			saleAmount = amount - (amount * discountLevel);
			purchasesAmount += saleAmount;
			
			
			if (purchasesAmount >= l4)
			{
				discountLevel = level4;
			}
			else
			{
				if (purchasesAmount >= l3)
				{
					discountLevel = level3;
				}
				else
				{
					if (purchasesAmount >= l2)
					{
						discountLevel = level2;
					}
					else
					{
						if (purchasesAmount >= l1)
						{
							discountLevel = level1;
						}
					}
				}
			}

			
		}
		else
		{
			std::cout << "Error Invalid Amount.\n\n";
		}
	}

	// Get Functions
	const double & GetPurchasesAmount() const { return purchasesAmount; }
	const double & GetDiscountLevel() const { return discountLevel; }
	const double & GetSaleAmount() const { return saleAmount; };

	// Set Functions
	void SetPurchasesAmount(double p) { purchasesAmount = p; }
	void SetDiscountLevel(double d) { discountLevel = d; }
	void SetSaleAmount(double a) { saleAmount = a; }
	
};

int main()
{
	int run = 1;
	double amount;
	
	PreferredCustomer cust1(571, 1, "Jones", "Justin", "5 Maple Street", "La Verne", "CA", 91750, 9092223333);

	while (run == 1)
	{
		std::cout << "Would you like to make a purchase? (1 = Yes, 0 = No): ";
		std::cin >> run;

		if (run == 1)
		{
			std::cout << "Enter Purchase Amount: ";
			std::cin >> amount;

			cust1.NewPurchase(amount);

			std::cout << std::fixed << std::setprecision(2);

			std::cout << "\nSale Amount: $" << cust1.GetSaleAmount() << std::endl;
			std::cout << "Total Purchases: $" << cust1.GetPurchasesAmount() << std::endl;
			std::cout << "New Discount Percentage: " << 100*cust1.GetDiscountLevel() << "%" << std::endl << std::endl;
	
		}
			
	}
	

	return 0;
}
