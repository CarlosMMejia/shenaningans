// brownies.cpp 
// This program will provide the exact number of small (1" x 1") or large (2" x 2") brownies that would fit in a pan of a specific size. 
// Carlos Mejia
#include <iostream>
using namespace std;

int main()
{   
   int length, width, small, large;
   
   cout << "Input length of the pan\n";
   cin >> length;
   cout << "Input width of the pan\n";
   cin >> width;
   
   small = length * width;
   large = (length / 2) * (width / 2);
   
   cout << "A " << length << " X " << width << " inch pan can hold " << small << " small brownies or " << large << " large brownies.";
   return 0;
}
