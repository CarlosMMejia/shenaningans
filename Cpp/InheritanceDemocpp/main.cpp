/**********************************Carlos Mejia******************
03/14/2019 Inclass program
****************************************************************/

#include <vector>

//#include "Vehicle.h"
//#include "Car.h"
#include "Train.h"
#include "Aircraft.h"
#include "Boat.h"
#include "Submarine.h"
//#include "Suv.h"
#include "ECOSuv.h"

int main(int argc, char** argv) 
{
	// CREATE 3 INSTANCES OF A CAR IN A CARS VECTOR
	Car *suv = new Car("ME 230", "Tan", 45000);
	Car *truck = new Car("Big Boy", "Black", 90000);
	Car *trailer = new Car("Lazy", "Beige", 50000);
	
	vector <Car> c;
	
	c.push_back(*suv);
	c.push_back(*truck);
	c.push_back(*trailer);
	
	// CREATE 5 DIFFERENT TYPES OF VEHICLES IN A VEHICLES VECTOR
	Vehicle *racing = new Car("Sonic" , "Blue", 70000);
	Vehicle *bullet = new Train("Light", "Passengers", 10, 40000000000); //$40 billion
	Vehicle *jet = new Aircraft("John Cena", "Fighter Jet", 2, 120000000); // "U Can't C Me" - $120 million
	Vehicle *fishing = new Boat("Hook", "Fishing", 6, 10000);
	Vehicle *civilian = new Submarine("Whale", "Research", 10, 3000000000); //$3 billion
	Vehicle *exploring = new Suv("Stable", 7, "AWD");
	Vehicle *eco = new ECOSuv("Greenie", 5, "AWD");
	vector <Vehicle*> pvh;
	
	pvh.push_back(racing);
	pvh.push_back(bullet);
	pvh.push_back(jet);
	pvh.push_back(fishing);
	pvh.push_back(civilian);
	pvh.push_back(exploring);
	pvh.push_back(eco);
	
	for(int i = 0; i < pvh.size(); i++) pvh[i]->DisplayInfo();
	
	/*	
	vector <Vehicle> vh;

	vh.push_back(*racing);
	vh.push_back(*bullet);
	vh.push_back(*jet);
	vh.push_back(*fishing);
	vh.push_back(*civilian);

	for(int i = 0; i < vh.size(); i++) vh[i].DisplayInfo();	
	*/
		
	//DESTROY THE VECTORS
	vector<Car>().swap(c);
	vector<Vehicle*>().swap(pvh);
//	vector<Vehicle>().swap(vh);
	return 0;
}
