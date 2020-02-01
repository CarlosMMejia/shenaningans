/*********************DR. Sunmonu **************************
Purpose: String utilities
2/23/2019
************************************************************/
#pragma once
#include <string>

//converts my_string to upper case
string ToUpper(string my_string)
{
  for(unsigned int i = 0; i < my_string.length(); ++i) {
    my_string[i] = toupper(my_string[i]);
  }
  return my_string;
}

//converts my_string to lower case
string ToLower(string my_string)
{
  for(unsigned int i = 0; i < my_string.length(); ++i) {
    my_string[i] = tolower(my_string[i]);
  }
  return my_string;
}

//case  contains(source,key)
    bool contains(string source, string key)
   {
   	   bool found = source.find(key) != source.npos;
        return found;//std::toupper(s1) == std::toupper(s2);
    }
//case insensitive contains(source,key)
    bool icontains(string source, string key)
   {
	 //turn both string to upper case
	 string usource = ToUpper(source);
	 string ukey = ToUpper(key);
   	bool found = usource.find(ukey) != usource.npos;
        return found;//std::toupper(s1) == std::toupper(s2);
    }

//case insensitive equals(source,key)
    bool iequals(string source, string key)
   {
	 //turn both string to upper case
	 string usource = ToUpper(source);
	 string ukey = ToUpper(key);
        return usource == ukey;
    }

