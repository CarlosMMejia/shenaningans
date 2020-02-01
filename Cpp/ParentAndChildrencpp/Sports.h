//Carlos Mejia
#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Sports
{
  virtual void Display() const
  {
    cout << "\nName of sport: " << NameOfSport << "\nNumber of team members: " << NumOfTeamMembers << "\nObjective to win: " << Objective << endl;
  }  
  
  Sports(){};
  
  Sports(string name, int number, string obj)
  {
    NameOfSport = name;
    NumOfTeamMembers = number;
    Objective = obj;
  }
  
  protected:
  
    string NameOfSport;
    int NumOfTeamMembers;
    string Objective;
};
