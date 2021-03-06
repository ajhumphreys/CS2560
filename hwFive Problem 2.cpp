// Andrew Humphreys CS 2560
// Homework 5 Problem 2

#include "pch.h"
#include <iostream>
#include <string>

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
int main()
{
	std::string tempLastName;
	std::string tempFirstName;
	std::string tempAddress;
	std::string tempCity;
	std::string tempState;
	int tempZip;
	long long tempPhone;
	int tempCustomerNumber;
	bool tempMailingList;

	std::cout << "Enter the following information\n\n";

	std::cout << "Last Name: ";
	std::getline(std::cin, tempLastName);

	std::cout << "First Name: ";
	std::getline(std::cin, tempFirstName);

	std::cout << "Address: ";
	std::getline(std::cin, tempAddress);

	std::cout << "City: ";
	std::getline(std::cin, tempCity);

	std::cout << "State: ";
	std::getline(std::cin, tempState);

	std::cout << "Zip Code: ";
	std::cin >> tempZip;

	std::cout << "Phone Number: ";
	std::cin >> tempPhone;

	std::cout << "Customer Number: ";
	std::cin >> tempCustomerNumber;

	std::cout << "Mailing List (1 Yes/ 0 No): ";
	std::cin >> tempMailingList;

	CustomerData d(tempCustomerNumber, tempCustomerNumber, tempLastName, tempFirstName, tempAddress, tempCity, tempState, tempZip, tempPhone);

	std::cout << std::endl << "Here is the information you entered.\n";
	std::cout << d.GetLastName() << std::endl;
	std::cout << d.GetFirstName() << std::endl;
	std::cout << d.GetAddress() << std::endl;
	std::cout << d.GetCity() << std::endl;
	std::cout << d.GetState() << std::endl;
	std::cout << d.GetZip() << std::endl;
	std::cout << d.GetPhone() << std::endl;
	std::cout << d.GetNum() << std::endl;
	std::cout << d.GetMail() << std::endl;

	return 0;
}
