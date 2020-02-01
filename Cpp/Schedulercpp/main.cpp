/**********************************************************************************************************
<project firstname="Carlos" lastname="Mejia" projname="SCHEDULER" />
Purpose of Program:
Create a schedule to which the user can add activities

Pseudo Code:
1. Create vector to store schedules
2. Create preset schedules and store them in vector
3. Display preset schedules
4. Loop asking user for boolean input (Y/N) to continue adding schedules or end program
5. End program when user inputs something else than 'Y'
***********************************************************************************************************/

#include <iostream>
#include "schedule.h"
#include <vector>

using namespace std;

void DisplaySchedule(vector<Schedule> schs)
{
	 cout<<"-----------------------------CURRENT SCHEDULE----------------------------------------------------\n\n";
	for(int i=0;i<schs.size();i++)
	  {
	  	  cout<<"----------------------------------------------------------------------------------\n";
		  cout<<(i+1)<<".";
		  schs[i].Display();
	  }
	  cout<<endl;
}

int main(int argc, char** argv) {
	
	vector<Schedule> sch; //vector to store schedules
	
	//Preset schedules
	
	Time MonStart(9, 30, 0);
	Time MonEnd(11,15,0);
	Schedule Mon("Mon", MonStart, MonEnd, "Brainstorming");
	
 	Time TueStart(10, 40, 0);
	Time TueEnd(13,15,0);
	Schedule Tue("Tue", TueStart, TueEnd, "Programming");
	
	Time WedStart(8, 0, 0);
	Time WedEnd(16,45,0);
	Schedule Wed("Wed", WedStart, WedEnd, "Presentation");
	
	Time ThurStart(8, 0, 0);
	Time ThurEnd(10,5,0);
	Schedule Thur("Thur", ThurStart, ThurEnd, "Travel to York");
	
	Time Thur2Start(10, 20, 0);
	Time Thur2End(16,30,0);
	Schedule Thur2("Thur", Thur2Start, Thur2End, "Brainstorming");
	
	Time FriStart(8, 30, 30);
	Time FriEnd(11,0,0);
	Schedule Fri("Fri", FriStart, FriEnd, "Gym");
	
	//Store all preset schedules in vector
	
	sch.push_back(Mon);
	sch.push_back(Tue);
	sch.push_back(Wed);
	sch.push_back(Thur);
	sch.push_back(Thur2);
	sch.push_back(Fri);
	
	//Display preset schedules
	
	DisplaySchedule(sch);
	
	//Initialize character for user input and placeholder schedule
	
	char addchar = 'N';
	Time start, end;
	Schedule addsch("", start, end, ""); //Placeholder members just to initialize addsch
	
	while(1) //Infinite loop until user decides to break
	{
		cout<<"Do you want to add another schedule (Y/N)?:\n";
		cin >> addchar;
		if(addchar != 'Y') //If user inputs something other than 'Y', proceed to display schedule and break the loop
		{
			DisplaySchedule(sch);
			break;
		}
		
		addsch.ReadSchedule(); //Insert new schedule
		
		sch.push_back(addsch);	//Store new schedule in vector
	}
	
	return 0;
}
