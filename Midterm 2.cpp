// Andrew Humphreys
// Midterm 2

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

void printInfo(class Human &h);

class Human
{
private:
	std::string name;
	int age;
	char sex;

	Human() {};

protected:
	Human(std::string n, int a, int s)
	{
		name = n;
		age = a;
		sex = s;
	}

	virtual ~Human()
	{

	}

public:
	// Get
	std::string getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}
	char getSex() const
	{
		return sex;
	}

	// Set
	void setName(std::string n)
	{
		name = n;
	}

	void setAge(int a)
	{
		age = a;
	}
	char setSex(char s)
	{
		sex = s;
	}
};

class Child : public Human
{
	friend class Parent;
private:
	std::string momName;
	std::string dadName;
	int allowance;

	Child() : Human(" ", 0, 'x') {};

public:
	Child(std::string n, int a, char s, std::string m, std::string d) : Human(n, a, s)
	{
		allowance = 0;
		momName = m;
		dadName = d;
	}

	int getAllowance() const
	{
		return allowance;
	}

	void printParent()
	{
		std::cout << "Mom: " << momName << std::endl;
		std::cout << "Dad: " << dadName << std::endl;
	}
};

class Parent : public Human
{
private:
	std::vector<std::string> children;

	Parent() : Human(" ", 0, 'x') {};

public:
	Parent(std::string n, int a, char s) :Human(n, a, s) {};

	void printChild()
	{
		std::cout << "Children: \n";
		for (int i = 0; i < children.size(); i++)
		{
			std::cout << children[i] << std::endl;
		}
	}

	void setChild(std::string c)
	{
		children.push_back(c);
	}

	void setChildAllowance(int a, Child &c)
	{

		for (int i = 0; i < children.size(); i++)
		{
			if (c.getName() == children[i])
			{
				c.allowance = a;
			}
		}

		
	}
};


int main()
{
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("Lisa", 12, 'F', "March", "Homer");
	Child Bart("Bart", 10, 'M', "March", "Homer");
	Child Maggie("Maggie", 3, 'F', "March", "Homer");

	Homer.setChild("Lisa");
	Homer.setChild("Bart");
	Homer.setChild("Maggie");

	March.setChild("Lisa");
	March.setChild("Bart");
	March.setChild("Maggie");
	
	std::cout << "Simpsons\n\n";

	std::cout << "Bart's Allowance: $" << Bart.getAllowance() << std::endl;

	Homer.setChildAllowance(5, Bart);
	std::cout << "Bart's New Allowance: $" << Bart.getAllowance() << std::endl << std::endl;

	Bart.printParent();
	std::cout << std::endl;

	std::cout << "\nMarch's Info\n";
	printInfo(March);
	std::cout << "\nLisa's Info\n";
	printInfo(Lisa);

	return 0;
}

void printInfo(Human &h)
{
	std::cout << "Name: " << h.getName() << std::endl;
	std::cout << "Age: " << h.getAge() << std::endl;
	std::cout << "Sex: " << h.getSex() << std::endl;
}
