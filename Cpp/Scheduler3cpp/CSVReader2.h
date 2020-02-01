///////////////////////////////////////////////////////////////////////////////////
//Name: Professor Adefemi Sunmonu
//Date: 9/3/2016 - 
//PLEASE DO NOT CHANGE ANYTHING IN THIS FILE, UNLESS YOU KNOW WHAT YOU ARE DOING!!/
///////////////////////////////////////////////////////////////////////////////////
#ifndef CSVREADER_H
#define CSVREADER_H

using namespace std;
#include <iostream>
#include <fstream> //for reading from file
#include <sstream> //used to store lines from file and tokenize a line read
#include <vector>


// trim from left. This is not part of the class, just a utility function
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right. This is not part of the class, just a utility function
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right. This is not part of the class, just a utility function
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

////Split a given string using given delimiter. This is not part of the class, just a utility function
vector<string> split( string s, const char del) 
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (std::getline(tokenStream, token, del))
   {
      if(token != "") tokens.push_back(trim(token));
   }
   return tokens;
};

class CSVReader
{
	public:
		CSVReader(string filepath,char del=',');
		vector<string> getRow(int row) const;//returns a row of the CSV
		string getCellAsString(int row, int col) const;//returns element at row, col
		char getCellAsChar(int row, int col) const;//returns element at row, col as char
		int getCellAsInt(int row, int col) const;//returns element at row, col as int
		vector<int> getCellAsIntVector(int row, int col,char del) const;//returns element at row, col as vector<int>
		double getCellAsDouble(int row, int col) const;//returns element at row, col as double
		int getRowsCount() const{ return Rows.size();}; //returns how many rows were read in
		int getColsCount() const{ return ColsLength;};//returns how many cols in the csv
		void printRow(int row) const;//prints the content of a given row
		
	private:
		vector<string>Rows;//contains the rows of data in the csv
		char del;//delimiter used to separate csv	
		int ColsLength;//number of columns	
};


//implementation of the functions
CSVReader::CSVReader(string filepath,char del)
	{
		ColsLength=0;
		this->del=del;
		//declare the file
	    ifstream csvfile;
	    csvfile.open(filepath);
	    if(csvfile.good())
	    {
	    	string line;
		    while ( getline(csvfile, line) ){
		        if (line.find(del) != std::string::npos) //make sure the delimiter is in the line we are reading
				 {
				   Rows.push_back(trim(line));
		           //set the number of columns if necessary
		           if(ColsLength==0)
		              ColsLength = (split(line,del)).size();
			    }
		      }//end of while
	    }
	    else cout<<"\nCSVReader ERROR--> I had trouble opening the file["<<filepath<<"]\n";
	    
	    csvfile.close();
	};


///get an entire row as vector
vector<string> CSVReader::getRow(int row) const
	{		
		if(row>=0 && row<Rows.size())	
		{
			return split(Rows[row],del);
		}
	//return empty list		
	vector<string> v;			
		return v; 
	};

///get content in location (row, col)
string CSVReader::getCellAsString(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return v[col]; 
	};

///get content in location (row, col) as char
char CSVReader::getCellAsChar(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return v[col][0]; //only interested in the first character 
	};

///get content in location (row, col) as int
int CSVReader::getCellAsInt(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return stoi(v[col]); 
	};
	
///get content in location (row, col) as double
double CSVReader::getCellAsDouble(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return stod(v[col]); 
	};

///get content in location (row, col) as vector<int>
vector<int> CSVReader::getCellAsIntVector(int row, int col,char del) const
	{
	  vector<string> v = getRow(row);
	  //split the col using del
	  vector<string> cols =split(v[col],del);
	  vector<int> res;
	  for(int i=0;i<cols.size();i++)
		 res.push_back(stoi(cols[i]));
		return res;
	};
	
/// print content of a given row
void CSVReader::printRow(int row) const
{
	 vector<string> vrow= getRow(row);
	 cout<<"["<<row<<"] ";
	 for(int j=0;j<ColsLength;j++)
	  {
	  cout<<vrow[j];
	  if(j<ColsLength-1)cout<<",";
	  }
	  cout<<endl;	
};

#endif
