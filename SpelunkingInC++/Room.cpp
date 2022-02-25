/*
* Enigma Swan Adams
* CS202 HW2
* Additonal program 2: room.cpp

*
*more specific file info:
*Room class defintion 
*
*/

#include "room.h" 
#include <iostream>
using std::cout;
using std::endl;

//constructor
Room::Room(string longDescript, string shortDescript,
	Room* nextRPtr, Room* nextLPtr, Room* backPtr, bool visited) : _longDescript(longDescript), _shortDescript(shortDescript),
	_nextRPtr(nextRPtr), _nextLPtr(nextLPtr), _backPtr(backPtr), _visited(visited) {}

// copy contructor
Room::Room(const Room& orig): _longDescript(orig._longDescript), _shortDescript(orig._shortDescript),
_nextRPtr(orig._nextRPtr), _nextLPtr(orig._nextLPtr), _backPtr(orig._backPtr), _visited(orig._visited) {}

//member functions
//printing descriptions
void Room::printLong() { cout << _longDescript; } 
void Room::printShort() { cout << _shortDescript; }
void Room::properPrint() { 
	if (_visited) { cout << _shortDescript; } // print short description if they've been there before
	else { cout << _longDescript; } // print long descirption if they've never been there
}
void Room::printOptions(bool longerOne) {
	//let them know there options 
		// right
	if (_nextRPtr != NULL) {
		if (longerOne) {
			cout << "You look closely at the room on your right" << endl;
			(*_nextRPtr).printLong();
		}
		else {
			cout << "To your right: ";
			(*_nextRPtr).printShort();
		}
		cout << endl;
	}
	
		//left
	if (_nextLPtr != NULL) {
		if (longerOne) {
			cout << "You look closely at the room on your left" << endl;
			(*_nextLPtr).printLong();
		}
		else {
			cout << "To your left: ";
			(*_nextLPtr).printShort();
		}
		cout << endl;
	}

	if (_backPtr != NULL) {
		if (longerOne) {
			cout << "You look closely at the room behind you" << endl;
			(*_backPtr).printLong();
		}
		else {
			cout << "behind you: ";
			(*_backPtr).printShort();
		}
		cout << endl;
	}
}