// Andrew Humphreys CS 2650
// Homework 4 Problem 2

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string license;
	int timeParked;

public:

	ParkedCar(string ma, string mo, string c, string l, int t)
	{
		make = ma;
		model = mo;
		color = c;
		license = l;
		timeParked = t;
	}

	ParkedCar()
	{
		make = " ";
		model = " ";
		color = " ";
		license = " ";
		timeParked = 0;
	}

	string GetMake()
	{
		return make;
	}

	string GetModel()
	{
		return model;
	}

	string GetColor()
	{
		return color;
	}
	
	string GetLicense()
	{
		return license;
	}
	
	int GetTimeParked()
	{
		return timeParked;
	}

};

class ParkingMeter
{
private:
	int timePurchased;

public:
	ParkingMeter(int t)
	{
		timePurchased = t;
	}

	ParkingMeter()
	{
		timePurchased = 0;
	}

	int GetTimePurchased()
	{
		return timePurchased;
	}

};

class ParkingTicket
{
private:
	ParkedCar m_car;
	float hours;
	string name;
	int badgeNum;
	const int FINE_P1 = 25;
	const int FINE_P2 = 10;
	int totalFine;

public:
	ParkingTicket(ParkedCar &car, float h, string n, int b)
	{
		m_car = car;
		hours = h;
		name = n;
		badgeNum = b;
	}
	ParkingTicket()
	{
		ParkedCar m_car;
	}

	void CalcFine()
	{
		if (hours < 1)
		{
			totalFine = FINE_P1;
		}
		else
		{
			totalFine = FINE_P1 + FINE_P2 * int(hours);
		}
	}

	void PrintTicket()
	{
		cout << fixed << setprecision(2);
		cout << "**************************************\n";
		cout << "***         Parking Ticket         ***\n";
		cout << "**************************************\n";
		cout << left << "Make: "				<< setw(32) << right << m_car.GetMake()	<< endl;
		cout << left << "Model: "				<< setw(31) << right << right << m_car.GetModel()<< endl;
		cout << left << "Color: "				<< setw(31) << right << m_car.GetColor() << endl;
		cout << left << "License Number: "		<< setw(22) << right << m_car.GetLicense() << endl;
		cout << "--------------------------------------\n";
		cout << left << "Amount: "				<< setw(22) << right << "$" << setw(8)<< float(totalFine) << endl;
		cout << "--------------------------------------\n";
		cout << left << "Ticketing Officer: "	<< setw(19) << right << name << endl;
		cout << left << "Badge Number: "		<< setw(24) << right << badgeNum << endl;

	}
};

class PoliceOfficer
{
private:
	string name;
	int badgeNum;
	ParkedCar m_car;
	ParkingMeter m_meter;
	ParkingTicket m_ticket;
	float hours;

	
public:
	PoliceOfficer(string n, int b, ParkedCar &car, ParkingMeter &meter)
	{
		name = n;
		badgeNum = b;
		m_car = car;
		m_meter = meter;
	}

	PoliceOfficer()
	{
		name = " ";
		badgeNum = 0;
	}

	void CreateTicket()
	{
		if (m_car.GetTimeParked() >= m_meter.GetTimePurchased())
		{
			hours = (m_car.GetTimeParked() - m_meter.GetTimePurchased())/60.0;
			ParkingTicket m_ticket(m_car, hours, name, badgeNum);
			m_ticket.CalcFine();
			m_ticket.PrintTicket();
		}
	}
};



int main()
{
	ParkedCar car1("Toyota", "Corolla", "Red", "7BTD991", 541);
	ParkingMeter time1(30);
	PoliceOfficer officer1("Officer Hernandez", 1247, car1, time1);

	officer1.CreateTicket();

	return 0;
}
