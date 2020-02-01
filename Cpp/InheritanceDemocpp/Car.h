/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
	public:
		Car(){}
		Car(string name, string color, double price)
		{
			Name = name;
			Color = color;
			Price = price;
			Type = "Car";
		}
		
		int NumWheels;
		string Color;
		double HorsePower;
		
		void DisplayInfo() const;
		
	protected:
		int nothing;
};

void Car::DisplayInfo() const
{
	cout << "\nCar Name: " << Name << "\tColor: " << Color <<"\tPrice: $" << fixed << setprecision(2) << Price <<endl;
}
