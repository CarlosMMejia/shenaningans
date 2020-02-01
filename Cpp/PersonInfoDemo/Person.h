#pragma once
#include <string>
using namespace std;

struct person
{
	string firstname;
	string lastname;
	string address;
	string city;
	string zip;
	char gender;
	int age;
	
//	Person(); // default constructor
	
/*	Person(string f, string l, string add, string c, string z, char g, int a) // constructor
	{
		firstname = f;
		lastname = l;
		address = add;
		city = c;
		zip = z;
		gender = g;
		age = a;
	}
*/

	void display()
	{
		cout << "First Name: "<< firstname
			 << "\nLast Name: " << lastname
			 << "\nAddress: " << address
			 << "\nCity: " << city
			 << "\nZip Code: " << zip
			 << "\nGender: " << gender
			 << "\nAge: " << age << endl << endl;
	}
};
