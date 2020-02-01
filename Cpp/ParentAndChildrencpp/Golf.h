//Carlos Mejia
#pragma once
#include "Sports.h"

struct Golf:public Sports
{
  
  Golf(){};
  
  Golf(string name, int pga)
  {
    NameOfPlayer = name;
    PGA = pga;
    NameOfSport = "Golf";
    NumOfTeamMembers = 0;
    Objective = "Score less points than competition (hitting the ball into the hole in fewer moves.)";
  }
  
  void Display() const
  {
    cout << "\nGolf player name: " << NameOfPlayer << "\nNumber of PGA Championships won: " << PGA << endl;
  }
  
  private:
    string NameOfPlayer;
    int PGA;
};
