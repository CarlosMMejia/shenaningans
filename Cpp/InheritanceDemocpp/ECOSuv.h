/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Suv.h"

class ECOSuv : public Suv
{
	public:
		ECOSuv(){}
		ECOSuv(string name, int seats, string drive)
		{
			Name = name;
			Type = "SUV";
			NumSeats = seats;
			DriveTrain = drive;
			nothing = 12;
		}
		
		int NumSeats;
		string DriveTrain;
				
		void DisplayInfo() const;
};

void ECOSuv::DisplayInfo() const
{
	cout << "\nECOSUV Name: " << Name << "\tNumber of Seats: " << NumSeats <<"\tDriveTrain: " << DriveTrain <<endl;
}
