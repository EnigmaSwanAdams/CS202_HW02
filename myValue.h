/*
* Enigma Swan Adams
* CS202 HW2
* Porgram 1: Linked List
*
*more specific file info:
*file containing header for Value class 
*has class declarations for member functions
*and variables
* 
*  I'm going to reuse some of my plant class from a previous lab
* and add some more fields (members) to
*/


#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

#ifndef myValue_H_
#define myValue_H_
// class declaration goes here
class myValue
{
public:

	// Copy constructor
	myValue(const myValue& orig);

	// Quick constructor (intitialized you values)
	myValue(int daysSW, float potSize, string name, string potDescript, 
		string plantDescript, string location, vector<int> dateA);
	// partial version 
	// Quick constructor partial
	myValue(int daysSW, float potSize, string name);


	//member functions
	// prints all plant info
	void printValueBasic();
	void printValueFindInnfo(); // what it looks like and where it is
	void printDate(); // prints the date the plant was aquired

	//unfinished 
	//void changeVar();

	// operator overloads

private:
	int _daysSW = -1;
	float _potSize = -1;
	string _name = "NOT NAMED"; // genus a species would be more usefull but I don't know those things off the top
	// of my head so I'll leave it out 
	string _potDescript = "UNDEFINED"; // maybe it would be one of a fiew options managed by a user defined type later 
	// but this is fine for now
	string _plantDescript = "UNDEFINED";
	string _location = "UNDEFINED"; // later it would be cool to have a more automated system for location 
	vector<int> _dateA = { 0, 0, 0 }; // array holding the date the plant was aquired 
	// where the first value is the month, second is the day, and last is the year
	
};

#endif /* myValue_H_ */