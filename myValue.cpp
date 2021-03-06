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
#include <algorithm>
// defualt contructor
myValue::myValue() {}

// Copy constructor
myValue::myValue(const myValue& orig) : _daysSW(orig._daysSW), //  copy
_potSize(orig._potSize), _name(orig._name), _potDescript(orig._potDescript), _plantDescript(orig._plantDescript),
_location(orig._location), _dateA(orig._dateA){}

// Quick constructors
myValue::myValue(int daysSW, float potSize, string name, string potDescript,
	string plantDescript, string location, vector<int> dateA) : _daysSW(daysSW), _potSize(potSize),
	_name(name), _potDescript(potDescript), _plantDescript(plantDescript), _location(location),
	_dateA(dateA) {}
// Quick constructor partial ( feel like ther is a better way to handle this by taking a variable number of
// parameters somehow, but I can't recal 
myValue::myValue(int daysSW, float potSize, string name) : _daysSW(daysSW), _potSize(potSize),
_name(name) {}
// quick contructor name only
myValue:: myValue(string name): _name(name){}


//member functions
//printing plant info functions
void myValue::printValueBasic() {  // pot size, dats since watered, and name 
	cout << _name << " is in a " << _potSize << " inch pot and its been " << _daysSW <<
		" days since you watered them";
}
void myValue::printValueFindInfo() {// what it looks like and where it is
	cout << "location desciption: " << _location << endl;
	cout << "Plant description: " << _plantDescript << endl;
	cout << "Pot description: " << _potDescript << endl;}
void myValue::printDate() { // prints the date the plant was aquired
	cout << "This plant was aquired in " << _dateA.at(0) << "/" << _dateA.at(1) << "/" << _dateA.at(3);
}


// operator overloads 
bool myValue::operator==(const myValue& b) { // doesn't check the descriptions match since the same plant might be 
	// described differently by different people
	return ((_name == b._name) && (_daysSW == b._daysSW) && (_potSize == b._potSize) && (_dateA == b._dateA));
}

