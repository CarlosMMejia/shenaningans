/************************Carlos Mejia***************************
03/14/2019 Inclass program
****************************************************************/

#pragma once
#include "Car.h"

class Suv : public Car
{
	public:
		Suv(){}
		Suv(string name, int seats, string drive)
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

void Suv::DisplayInfo() const
{
	cout << "\nSUV Name: " << Name << "\tNumber of Seats: " << NumSeats <<"\tDriveTrain: " << DriveTrain <<endl;
}
