/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Vehicle.h"

class Boat : public Vehicle
{
	public:
		Boat(){}
		
		Boat(string nm, string pur, int ns, double p)
		{
			Name = nm;
			Purpose = pur;
			NumSeats = ns;
			Price = p;
			Type = "Boat";
		}
		
		string Purpose;
		int NumSeats;
		
		void DisplayInfo() const;
};

void Boat::DisplayInfo() const
{
	cout << "\nBoat Name: " << Name << "\tPurpose: " << Purpose;
	cout << "\tNumber of Seat: " << NumSeats << "\tPrice: " << fixed << setprecision(2) << Price << endl;
}
