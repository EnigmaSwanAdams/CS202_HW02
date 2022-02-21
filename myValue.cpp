/*
* Enigma Swan Adams
* CS202 HW2
* Porgram 1: Linked List
*
*more specific file info:
*file containing class Value defintion 
*
* 
*/



#include "myValue.h"


// Copy constructor
myValue::myValue(const myValue& orig) : _daysSW(orig._daysSW), //  copy
_potSize(orig._potSize), _name(orig._name), _potDescript(orig._potDescript), _plantDescript(orig._plantDescript),
_location(orig._location), _dateA(orig._dateA){}

// Quick constructor 
myValue::myValue(int daysSW, float potSize, string name, string potDescript,
	string plantDescript, string location, vector<int> dateA) : _daysSW(daysSW), _potSize(potSize),
	_name(name), _potDescript(potDescript), _plantDescript(plantDescript), _location(location),
	_dateA(dateA) {}
// Quick constructor partial ( feel like ther is a better way to handle this by taking a variable number of
// parameters somehow, but I can't recal 
myValue::myValue(int daysSW, float potSize, string name) : _daysSW(daysSW), _potSize(potSize),
_name(name) {}


//member functions
//printing plant infor functions
void myValue::printValueBasic(){  // pot size, dats since watered, and name 
	cout << _name << " is in a " << _potSize << " inch pot and its been " << _daysSW <<
		" days since you watered them" << endl;}
void myValue::printValueFindInnfo() {// what it looks like and where it is
	cout << "location desciption: " << _location << endl;
	cout << "Plant description: " << _plantDescript << endl;
	cout << "Pot description: " << _potDescript << endl;}
void myValue::printDate() { // prints the date the plant was aquired
	cout << "This plant was aquired in " << _dateA.at(0) << "/" << _dateA.at(1) << "/" << _dateA.at(3) << endl;
}

//unfinished 
//void changeVar();

// operator overloads



