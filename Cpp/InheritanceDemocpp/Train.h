/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Vehicle.h"

class Train : public Vehicle
{
	public:
		Train(){}
		
		Train(string nm, string ct, int nc, double p)
		{
			Name = nm;
			CargoType = ct;
			NumCars = nc;
			Price = p;
			Type = "Train";
		}
		
		string CargoType;
		int NumCars;
		
		void DisplayInfo() const;
};

void Train::DisplayInfo() const
{
	cout << "\nTrain Name: " << Name << "\tCargo Type: " << CargoType;
	cout << "\tNumber of Cars: " << NumCars << "\tPrice: " << fixed << setprecision(2) << Price << endl;
}
