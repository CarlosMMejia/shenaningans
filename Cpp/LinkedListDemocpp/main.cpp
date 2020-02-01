/************************Carlos Mejia***************************
03/19/2019 Inclass program
****************************************************************/

#include "Person.h"

int main(int argc, char** argv)
{
	PeopleList	*L = new PeopleList();
	
	L->Insert("Carlos", 22);
	L->Insert("Emily", 25);
	L->Insert("Stephanie", 25);
	L->Insert("Joe", 40);
	
	L->Display();
	
	cout << "\n--------FIND(Stephanie)---------\n";
	L->Find("Stephanie")->Display();
	
	cout << "\n--------REMOVE(Stephanie)-------\n";
	if(L->Remove("Stephanie"))
		cout << "Stephanie has been removed.";
		
	cout << "\n--------DISPLAY AGAIN--------\n";
	L->Display();
	
	cout << "\n--------INSERT(Stephanie)-------\n";
	L->Insert("Stephanie", 25);
		
	cout << "\n--------DISPLAY AGAIN--------\n";
	L->Display();
	
	
	return 0;
}
