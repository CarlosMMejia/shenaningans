#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Time
{
	int Hour;
	int Minute;
	int Second;
	
	Time():Time(0,0,0){	} //default constructor - "calls" constructor with parameters
	
	Time(int hr, int min, int sec) //constructor with parameters
	{
		Hour = hr;
		if(Hour < 0 || Hour > 24) //Hours can only be between 0 and 24
		{
			cout << "Invalid input for hour (0 - 24)!";
			exit(0);
		}
		
		Minute = min;
		if(Minute < 0 || Minute > 60) //Minutes can only be between 0 and 60
		{
			cout << "Invalid input for minute (0 - 60)!";
			exit(0);
		}
		
		Second = sec;
		if(Second < 0 || Second > 60) //Seconds can only be between 0 and 60
		{
			cout << "Invalid input for second (0 - 60)!";
			exit(0);
		}
	};
	
	//read time from user
	void ReadTime()
	{
		cout << "\tEnter hour: ";
		cin >> Hour;
		if(Hour < 0 || Hour > 24)
		{
			cout << "Invalid input for hour (0 - 24)!";
			exit(0);
		}
		
		cout << "\n\tEnter minute: ";
		cin >> Minute;
		if(Minute < 0 || Minute > 60)
		{
			cout << "Invalid input for minute (0 - 60)!";
			exit(0);
		}
		
		cout << "\n\tEnter second: ";
		cin >> Second;
		if(Second < 0 || Second > 60)
		{
			cout << "Invalid input for second (0 - 60)!";
			exit(0);
		}
	}
	
	//show time
	void Show()
	{
		cout<<Hour<<":"<<Minute<<":"<<Second;
	}
};

class Schedule
{
	private:
	string Day;
	Time Start; //start of schedule
	Time End; //end of schedule
	string Activity;
	
	public:
		
		//Constructor
		Schedule(string day, Time start, Time end, string activity)
		{
			Day = day;
			Start = start;
			End = end;
			Activity = activity;
		}
		
		//display the schedule horizontally
		void Display()
		{
			cout<<setw(5)<<Day<<setw(10);
			Start.Show();
			cout<<setw(10);
			End.Show();
			cout<<setw(20);
			cout<<Activity<<setw(10);
			Length();
			cout<<endl;
		}

		//calculates the duration of the schedule
		void Length()
		{
			int startSeconds = Start.Hour * 3600 + Start.Minute * 60 + Start.Second; //Store start time in seconds
			int endSeconds =  End.Hour * 3600 + End.Minute * 60 + End.Second; //Store end time in seconds
			int differenceSeconds = endSeconds - startSeconds; //Subtract end time - start time
			
			if (differenceSeconds < 0) //If start time > end time, exit the program;
			{
				cout << "An activity cannot end before it starts!";
				exit(0);
			}
			
			//Converts the seconds to hours, minutes and seconds respectively
			int hours = differenceSeconds / 3600;
			differenceSeconds = differenceSeconds % 3600;
			int minutes = differenceSeconds / 60;
			differenceSeconds = differenceSeconds % 60;
			int seconds = differenceSeconds;
			
			cout << "[" << hours << " hour, " << minutes << " min, and " << seconds << " sec.]";
		}
		
		//read schedule from user
		void ReadSchedule()
		{
			cout << "Enter Day of week: \n";
			cin >> Day;
			cout << "Enter Start Time: \n";
			Start.ReadTime();
			cout << "\nEnter End Time: \n";
			End.ReadTime();
			cout << "\nEnter Activity: \n";
			cin >> Activity;
		}

};
