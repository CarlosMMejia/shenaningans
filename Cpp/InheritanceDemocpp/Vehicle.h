/**********************************Carlos Mejia******************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle
{
	public:
		Vehicle(){}
		Vehicle(string nm, string type, double price):Name(nm),Type(type),Price(price){}
		
		string Name;
		string Type;
		string Fuel;
		string Make;
		virtual void DisplayInfo() const = 0;
		
	protected:
		double Price;
};

/*
void Vehicle::DisplayInfo() const
{
	cout << "\nVehicle Name = " << Name << "\nType = " << Type;
	cout << fixed << setprecision(2) << "\nPrice = $" << Price << endl;
}
*/
