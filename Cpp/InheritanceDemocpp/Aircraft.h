/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Vehicle.h"

class Aircraft : public Vehicle
{
	public:
		Aircraft(){}
		
		Aircraft(string nm, string pur, int ns, double p)
		{
			Name = nm;
			Purpose = pur;
			NumSeats = ns;
			Price = p;
			Type = "Aircraft";
		}
		
		string Purpose;
		int NumSeats;
		
		void DisplayInfo() const;
};

void Aircraft::DisplayInfo() const
{
	cout << "\nAircraft Name: " << Name << "\tPurpose: " << Purpose;
	cout << "\tNumber of Seats: " << NumSeats << "\tPrice: " << fixed << setprecision(2) << Price << endl;
}
