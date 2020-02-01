/*
Carlos Mejia
CS451 PQ Programming Assignment
bowling.cpp
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void read_player(int &p) //Reads the number of the player and stores it by reference
{
  cout << "\nEnter number of player: ";
  cin >> p;
}

void read_scores(int &s1, int &s2, int &s3) //Reads 3 scores between 0 and 300 stores them by reference
{
  cout << "Enter score 1: ";
  cin >> s1;
  cout << "\nEnter score 2: ";
  cin >> s2;
  cout << "\nEnter score 3: ";
  cin >> s3;
  
  if(s1 < 0 || s2 < 0 || s3 < 0 || s1 > 300 || s2 > 300 || s3 > 300)
  {
    cout << "Error: Scores can only be between 0 and 300";
    exit(1);
  }
}

double find_average(int s1, int s2, int s3) //Finds and return the average of the three scores (passed by value)
{
  return (double) (s1 + s2 + s3) / 3;
}

char what_performance(double avg) //Returns a performance character based on the average (passed by value)
{
  if(avg >= 50)
  {
    if(avg >= 100)
    {
      if(avg >= 150)
      {
        if(avg >= 200)
        {
          if(avg >= 250)
          {
            return 'A';
          }
          
          return 'B';
        }
        
        return 'C';
      }
      
      return 'D';
    }
    
    return 'E';
  }
  
  return 'X';
}

void headings() //Displays the headings
{
  cout << "\n\t\t\tCARLOS MEJIA - CS451 PQ" 
  << "\n\t\t\t======================="
  << "\n\t\t\t\tBOWLING SCORES"
  << "\n\t\t\t\t==============="
  << "\nPLAYER#\tSCORE-1\tSCORE-2\tSCORE-3\tAVERAGE\tPERFORMANCE" 
  << "\n=======\t=======\t=======\t=======\t=======\t===========";
}

void print_scores(int p, int s1, int s2, int s3, double avg, char perf) //Prints everything passed by value
{
  cout << "\n\t" << p << "\t" << s1 << "\t\t" << s2 << "\t\t" << s3 << "\t\t" << fixed << setprecision(2) << setw(6) << avg << "\t\t" << perf;
}

struct player //Linked List class to store all players' data
{
  player *next;
  int p;
  int s1, s2, s3;
  double avg;
  char perf;
  
  player(){next = NULL;}
};

int main() {
  double gavg = 0;
  int counter = 0;
  
  player *p = new player(); //Creates a player object named p
  player *current = p; //Creates a player object which will be used to traverse from p towards the next players
  
  while(1) //Reads and processes all the players' data until the user inputs a player with 0 for all three scores
  {
    read_player(current->p); //Stores number of player in p
    read_scores(current->s1, current->s2, current->s3); //Stores the scores in s1, s2 and s3

    if(current->s1 == 0 && current->s2 == 0 && current->s3 == 0) //If all three scores = 0, break the loop
      break;

    current->avg = find_average(current->s1, current->s2, current->s3); //Calculates and stores the average of the three scores
    current->perf = what_performance(current->avg); //Returns a performance character based on the average and stores it in perf
    
    gavg = gavg + current->avg; //Adds the player's average score to the game's average score
    counter++; //Keeps track of how many players there are
    
    current->next = new player(); //Create next player
    current = current->next; //Point to next player
  }
  
  current = p;
  headings();

  while(current->next != NULL) //While we still have players left
  {
    print_scores(current->p, current->s1, current->s2, current->s3, current->avg, current->perf); //Print their scores

    current = current -> next; //Look for next player
  }

  cout << "\nThe game's average is " << gavg/counter; //Prints game's average
  
  
  return 0;
}
