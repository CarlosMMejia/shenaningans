#pragma once
#include <string>
using namespace std;

class Currency
{
	private:
	
	double Value;
	string Name, Symbol, Code;
	
	public:
	
	Currency () {}
	
	
	Currency (double v, string n, string s, string c)
	{
		Value = v;
		Name = n;
		Symbol = s;
		Code = c;
	}
	
	void setValue(double v)
	{
		Value = v;
	}
	
	void setName(string n)
	{
		Name = n;
	}
	
	void setSymbol (string s)
	{
		Symbol = s;
	}
	
	void setCode (string c)
	{
		Code = c;
	}
	
	double getValue()
	{
		return Value;
	}
	
	string getName()
	{
		return Name;
	}
	
	string getSymbol()
	{
		return Symbol;
	}
	
	string getCode ()
	{
		return Code;
	}
	
	void display ()
	{
		cout << "\nValue: " << Value << "\nName: " << Name << "\nSymbol: " << Symbol << "\nCode: " << Code <<endl;
	}
	/*
	void convertTo(Currency)
	{
	}
	*/
};
