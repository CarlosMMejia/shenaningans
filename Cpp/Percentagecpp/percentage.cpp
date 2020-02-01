// Lab 3 percentage.cpp
// This program will determine the percentage
// of answers a student got correct on a test.
// Carlos Mejia

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
  string name;
  int numQuestions,
      numCorrect;
  double percentage;
  
  // Get student's test data
  cout << "Enter student's first and last name: ";
  getline(cin, name);
  
  cout << "Number of questions on the test: ";
  cin >> numQuestions;
  cout << "Number of answers the student got correct: ";
  cin >> numCorrect;
  
  // Compute and display the student's % correct
  percentage = (double) 100 * numCorrect / numQuestions;
  
  cout << name << "'s score: " << fixed << setprecision(1) << percentage << "%";
  return 0;
}
