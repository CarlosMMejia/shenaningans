//Carlos Mejia
#pragma once
#include "Sports.h"

struct Baseball:public Sports
{
  
  Baseball(){};
  
  Baseball(string name, int mvp)
  {
    NameOfTeam = name;
    MVP = mvp;
    NameOfSport = "Baseball";
    NumOfTeamMembers = 9;
    Objective = "Score more \"runs\" than opposing team.";
  }
  
  void Display() const
  {
    cout << "\nBaseball team name: " << NameOfTeam << "\nNumber of MVPs won: " << MVP << endl;
  }
  
  private:
    string NameOfTeam;
    int MVP;
};
