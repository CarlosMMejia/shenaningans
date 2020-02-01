/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Vehicle.h"

class Submarine : public Vehicle
{
	public:
		Submarine(){}
		
		Submarine(string nm, string pur, int nw, double p)
		{
			Name = nm;
			Purpose = pur;
			NumWin = nw;
			Price = p;
			Type = "Submarine";
		}
		
		string Purpose;
		int NumWin;
		
		void DisplayInfo() const;
};

void Submarine::DisplayInfo() const
{
	cout << "\nSubmarine Name: " << Name << "\tPurpose: " << Purpose;
	cout << "\tNumber of Windows: " << NumWin << "\tPrice: " << fixed << setprecision(2) << Price << endl;
}
