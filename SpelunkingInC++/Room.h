/*
* Enigma Swan Adams
* CS202 HW2
* Additional program 2: room.h
*
*more specific file info:
*room class decalaration 
*
*/



#ifndef ROOM_H_
#define ROOM_H_

#include <string>
using std::string;
// class declaration goes here
class Room
{
public:
	//constructor
	Room(string longDescript, string shortDescript, 
		Room* nextRPtr, Room* nextLPtr, Room* backPtr, bool visited);
	// copy constructor
	Room(const Room& orig);

	//member functions
	// printing descriptions
	void printLong(); // prints name, days since watered and pot size
	void printShort();
	void properPrint();

	// operator overloads
	//bool operator==(const Room& b);



	//private:
	// members 
	string _longDescript = "NO LONG DESCRIPTION FOUND";
	string _shortDescript = "NO SHORT DESCRIPTION FOUND";
	Room* _nextRPtr = NULL;
	Room* _nextLPtr = NULL;
	Room* _backPtr = NULL;
	bool _visited = 0;

};

#endif /* ROOM_H_ */