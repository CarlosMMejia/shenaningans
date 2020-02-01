#include <iostream>
#include "person.h"
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	
	vector<person> people;
	
	for(int i = 0; i < 3; i++)
	{
		cout << "\nEnter First Name:";
		string fn;
		getline (cin, fn);
		
		cout << "\nEnter Last Name:";
		string ln;
		getline (cin, ln);
		
		person p {fn, ln};
		people.push_back(p);
	}
	
	for(int i = 0; i < people.size(); i++)
	{
		people[i].display();
	}
	
	return 0;
}
