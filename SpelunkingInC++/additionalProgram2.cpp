/*
* Enigma Swan Adams
* CS202 HW2
* Additional Program 2:
* file containing main,
*
* go cave exploring in the nondescript cave
* 
*/
#include <iostream>
#include "Room.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;



int main() {
	// create rooms 
	Room exit = Room("exit long descript", "exit short descript", NULL, NULL, NULL, 0);
	Room entrance = Room("entrance long descript", "entrance short descript", NULL, NULL, NULL, 0);
	Room a = Room("a long description", "a short description", NULL, NULL, NULL, 0);
	Room b = Room("b long description", "b short description", NULL, NULL, NULL, 0);
	Room c = Room("c long description", "c short description", NULL, NULL, NULL, 0);
	Room d = Room("d long description", "d short description", NULL, NULL, NULL, 0);
	Room e = Room("e long description", "e short description", NULL, NULL, NULL, 0);

	// create connections 
	// (note the back pointer doesn't always point to the room you were in previously)
		//entrance connects to rooms a and b
	entrance._nextLPtr = &a;
	entrance._nextRPtr = &b;
		// room a connects to the entrance, room d and room c
	a._backPtr = &entrance;
	a._nextLPtr = &d;
	a._nextRPtr = &c;
		// room b connects to the entrance, and rooms c and e
	b._backPtr = &entrance;
	b._nextLPtr = &c;
	b._nextRPtr = &e;
		// room c won't let you turn back you can only move to room d or room e
	c._nextLPtr = &d;
	c._nextRPtr = &e;
		// from room d you can go to the exit, room c or room a
	d._backPtr = &a;
	d._nextLPtr = &exit;
	d._nextRPtr = &c;
		// from room e you can go to room a, c, or b
	e._backPtr = &b;
	e._nextLPtr = &c;
	e._nextRPtr = &a;

	// print intial premise
	cout << "You wake up in the middle of a cave complex\n";
	Room* currentPtr = &entrance; // currentPtr points to entrance
	char direction;
	char show;
	

	// traverse the cave
	while (true) {
		// let them know where they're at
		(*currentPtr).properPrint();
		(*currentPtr)._visited = true; // now we've been here 

		// if we got out
		if (currentPtr == &exit) { cout << "\nYou've made it!" << endl; break; }

		cout << "\nYou look around" << endl;
		cout << "Enter S if you'd like to see the full descripions of the rooms around you\n"
			"or anything else to see the short descirptions: ";

		// let them know there options
		cin >> show;
		bool wantsLongerDescript = 0;
		if (toupper(show) == 'S') { wantsLongerDescript = true; }
		(*currentPtr).printOptions(wantsLongerDescript);

		// get the direction
		cout << "\n\nwhich direction will you go?" << endl; 
		cout << "\nEnter R, L or B to move right left or back repectively: ";
		cin >> direction;
		direction = toupper(direction);

		// go the direction
		switch (direction) {
		case 'R':
			if ((*currentPtr)._nextRPtr == NULL) {
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way\n" << endl;
				break;
			}
			cout << "You enter the next room..." << endl;
			currentPtr = (*currentPtr)._nextRPtr;
			break;

		case 'L':
			if ((*currentPtr)._nextLPtr == NULL) {
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way\n" << endl;
				break;
			}
			cout << "You enter the next room..." << endl;
			currentPtr = (*currentPtr)._nextLPtr;
			break;

		case 'B':
			if ((*currentPtr)._backPtr == NULL) {
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way\n" << endl;
				break;
			}
			cout << "You enter the next room..." << endl;
			currentPtr = (*currentPtr)._backPtr;
			break;

		case 'S':

		default:
			cout << "Thats not a recognised command/direction" << endl;
			cout << "Pick a different way\n" << endl;
		}
	}

	return 0;
}

