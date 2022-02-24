/*
* Enigma Swan Adams
* CS202 HW2
* Additonal program 2: room.cpp

*
*more specific file info:
*room class defintion 
*
*/

#include "room.h" 
#include <iostream>
using std::cout;
// constructor


//constructor
Room::Room(string longDescript, string shortDescript,
	Room* nextRPtr, Room* nextLPtr, Room* backPtr) : _longDescript(longDescript), _shortDescript(shortDescript),
	_nextRPtr(nextRPtr), _nextLPtr(nextLPtr), _backPtr(backPtr) {}

//member functions
//printing descriptions
void Room::printLong() { cout << _longDescript; } // prints name, days since watered and pot size
void Room::printShort() { cout << _shortDescript; }