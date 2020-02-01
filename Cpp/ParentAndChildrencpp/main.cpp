#include <iostream>
#include <vector>
#include "Sports.h"
#include "Baseball.h"
#include "Golf.h"

int main() {
  
  Sports *baseball = new Sports("Baseball", 9, "Score more \"runs\" than opposing team.");
  
  Sports *bs = new Baseball("New York Yankees", 22);
  
  Sports *golf = new Sports("Golf", 0, "Score less points than competition (hitting the ball into the hole in fewer moves.)");

  Sports *gf = new Golf("Tiger Woods", 4);
  
  vector <Sports*> sp;
  sp.push_back(baseball);
  sp.push_back(bs);
  sp.push_back(golf);
  sp.push_back(gf);
      
  cout <<"-----------------------------Baseball---------------------------------------------------";
  
  sp[0]->Display();
  
  sp[1]->Display();
  
  cout <<"-----------------------------Golf-------------------------------------------------------";
  
  sp[2]->Display();
  
  sp[3]->Display();
}
