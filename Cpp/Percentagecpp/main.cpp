/**********************************************************************************************************
<project firstname="Carlos" lastname="Mejia" projname="SCHEDULER3" />
Purpose of Program:
Read a list of schedule from a csv file and allow the user to search for schedules given day or activity

Pseudo Code:
1. Create functions to display the list of schedules, search by day and search by activity
2. Read csv file and store the list of schedules as a vector (dynamic memory allocation)
3. Print the menu for the user to see and prompts the user to choose an option by entering '1', '2', '3' or 'X'
4. Display the list of schedules if the user enters '1'
5. Prompts the user to enter the day of the schedule if the user enters '2' (search by day)
6. Prompts the user to enter the activity of the schedule if the user enters '3' (search by activity)
7. Exits the program if the user enters 'X'.
***********************************************************************************************************/

#include <iostream>
#include <vector>
#include "schedule.h"
#include "stringutil.h"
#include "CSVReader2.h"

using namespace std;

//Display the list of schedule
void DisplaySchedule(vector<Schedule> schs)
{
	 cout << "-----------------------------CURRENT SCHEDULE----------------------------------------------------\n\n";
	for(int i = 0; i < schs.size(); i++)
	  {
	  	  cout << "----------------------------------------------------------------------------------\n";
		  cout<<(i + 1) << ".";
		  schs[i].Display();
	  }
	  cout << endl;
}

void searchDay (vector<Schedule> schs, string s)
{
	cout<<"----------------------------------------------------------------------------------\n";
	bool found = 0;
	
	for(int i = 0; i < schs.size(); i++)
	{
		if(iequals(schs[i].getDay(), s))
		{
			found = 1;
			schs[i].Display();
		}
	}
	
	if(!found)
		cout << "No schedule found for day [" << s << "]\n";
}

void searchAct (vector<Schedule> schs, string s)
{
	cout<<"----------------------------------------------------------------------------------\n";
	bool found = 0;
	
	for(int i = 0; i < schs.size(); i++)
	{
		if(contains(schs[i].getAct(), s))
		{
			found = 1;
			schs[i].Display();
		}
	}
	
	if(!found)
		cout << "No schedule found for activity [" << s << "]";
}

int main(int argc, char** argv) {
	
	//Load the entire schedules.csv into rd
	CSVReader *rd = new CSVReader("schedules.csv",',');
	
	//(OPTIONAL) show for debuging purpose that we have all schedules
	for(int i = 0; i < rd -> getRowsCount(); i++)
	 rd -> printRow(i);
	 
	 
	vector<Schedule> sch; //vector to store schedules
	
	for(int i=1; i < rd -> getRowsCount(); i++) //start from i = 1 to avoid the header in schedules.csv
	{
		vector <int> intstart; //Vector to read the start time from the file and store it using getCellsAsIntVector
		intstart = rd->getCellAsIntVector(i, 1,':'); //Store start time as a vector into intstart
		Time start = Time(intstart[0], intstart[1], intstart[2]); //Store vector time as an object of the Time type struct
		
		vector <int> intend; //Vector to read the end time from the file and store it using getCellsAsIntVector
		intend = rd->getCellAsIntVector(i, 2,':'); //Store end time as a vector into intend
		Time end = Time(intend[0],intend[1],intend[2]); //Store vector time as an object of the Time type struct
		
		Schedule s = Schedule(rd->getCellAsString(i,0), //Day of the week
		            start, //Start time
		            end, //End time
		            rd->getCellAsString(i,3)  //Activity
		  );
		  
		  //store the schedule in the database
		  sch.push_back(s);
	}
		
		char choice = ' ';
	while(1){
		cout<<"\n======================================\nWelcome to My Scheduler\n======================================\n";
		cout <<"[1] See all schedules\n[2] See schedules for a given day\n[3] See schedules given an activity\n[X] Exit this program\nEnter Choice: ";
		cin >> choice;
		if(choice == '1')
			DisplaySchedule(sch);
			else if(choice == '2'){
				string day;
				cout << "Enter Day of Week as Mon,Tue etc: ";
				cin >> day;
				searchDay(sch, day);
			}
				else if(choice == '3'){
					string act;
					cout << "Enter Activity: ";
					cin >> act;
					searchAct(sch, act);
				}
				
					else if(choice == 'x' || choice == 'X'){
						cout << "Good bye";
						break;
					}
				
						else
							cout << "Invalid Entry\n";
					
	}
	return 0;
}
