/******************************************
<project firstname="Carlos" lastname="Mejia" projname="CurrencyProject"/>
Purpose:
Practicing classes
*******************************************/
//#include "C:\Users\carli\Downloads\Libraries\cpp-netlib-0.13.0-final/boost/network/protocol/http/client.hpp"
#include <iostream>
#include "Currency.h"
using namespace std;

int main(int argc, char** argv) {
	int size = 2;
	Currency array[size];
	
	array[0] = Currency(100, "US Dollar", "$", "USD");
	array[1] = Currency(300, "Mexican Peso", "Mex$", "MXN");
	
	for(int i = 0; i < size; i++)
	{
		array[i].display();
	}
	return 0;
}
