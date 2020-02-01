// Lab 3 icecream.cpp
// Simulates the purchase of several icecream cones, with different prices for
// different number of scoops of icecream.
// Carlos Mejia
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  const double singleScoop = 1.49;
  const double doubleScoops = 2.49;
  const double tripleScoops = 3.49;
  
  int singleSold, doubleSold, tripleSold, totalScoops;
  double total;
  
  cout << "Number of single scoop scones sold: ";
  cin >> singleSold;
  cout << "Number of double scoop cones sold: ";
  cin >> doubleSold;
  cout << "Number of triple scoop cones sold: ";
  cin >> tripleSold;
  
  totalScoops = singleSold + doubleSold + tripleSold;
  total = singleSold * singleScoop + doubleSold * doubleScoops + tripleSold * tripleScoops;
  
  cout << "\nDeLIGHTful cones \t" << singleSold << "\t$" << fixed << setprecision(2) << (double) singleSold * singleScoop;
  cout << "\nDouble DeLIGHT cones \t" << doubleSold << "\t$" << fixed << setprecision(2) << (double) doubleSold * doubleScoops;
  cout << "\nTriple DeLIGHT cones \t" << tripleSold << "\t$" << fixed << setprecision(2) << (double) tripleSold * tripleScoops;
  cout << "\nTotal:\t\t\t" << totalScoops << "\t$" << total;
  return 0;
}
