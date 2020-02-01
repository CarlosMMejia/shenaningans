/************************Carlos Mejia***************************
03/19/2019 Inclass program
****************************************************************/

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Person
{
	Person *Next;
	string Name;
	int Age;
	
	Person(){Next = NULL;}
	Person(string n, int a) : Name(n), Age(a), Next(NULL){};
	
	void Display(){cout << "Name: " << Name << "\tAge: " << Age << endl;}
	
};

class PeopleList
{
	Person *Head;
	Person *Trail;
	
	public:
		PeopleList() : Head(NULL), Trail(NULL){}
		PeopleList(Person *p) : Head(p), Trail(Head){}
		
		void Insert(string n, int a)
		{
			Person *add = new Person(n, a);
			
			if(Head == NULL)
			{
				Head = add;
				Trail = Head;
			}
			
			else
			{
				Trail -> Next = add;
				Trail = add;
			}
		}
		
		Person *Find(string n)
		{
			Person *current = Head;
	
			while(current != NULL)
			{
				if(current -> Name == n)
					return current;
					
				current = current -> Next;
			}
			
			cout << "Couldn't find anyone named \"" << n << "\"";
			return new Person();
		}
		
		bool Remove(string n)
		{
			if(Find(n) -> Name == "")
				return 0;
			
			Person *current = Head;
			
			while(current -> Next != Find(n))
				current = current -> Next;
			
			Person *temp = Find(n) -> Next;
			Find(n) -> Next = NULL;
			current -> Next = temp;
			return 1;
		}
		
		void Display()
		{
			Person *current = Head;
	
			while(current != NULL)
			{
				current -> Display();
				current = current -> Next;
			}
		}
};
