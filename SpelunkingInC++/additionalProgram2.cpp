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
	//Room current = *currentPtr; // hopefully current is the same as entrance, and not a copy (nevermind)
	//cout << "adress of current: " << &current << " and " << currentPtr;
	//cout << "adress of entrance: " << &entrance << endl;
	char direction;

	while (true) {
		// let them know where they're at
		(*currentPtr).properPrint();
		(*currentPtr)._visited = true; // now we've been here 

		// if we got out
		if (currentPtr == &exit) { cout << "\nYou've made it!" << endl; break; }

		cout << "\n\nwhich direction will you go?" << endl;
		
		//let them know there options 
		if ((*currentPtr)._nextRPtr != NULL) { 
			cout << "To your right: ";
			Room* tempNextPtr = (*currentPtr)._nextRPtr;
			(*tempNextPtr).printShort();

			//give them the option to see the full descript
			cout << "\nWant to read the full description (y or n): ";
			char ans;
			cin >> ans;
			if (toupper(ans) == 'Y') { 
				cout << "You look a litle closer at the room on your right" << endl;
				(*tempNextPtr).printLong(); 
			}
		}
		if ((*currentPtr)._nextLPtr != NULL) {
			cout << "To your left: ";
			Room* tempNextPtr = (*currentPtr)._nextLPtr;
			(*tempNextPtr).printShort();

			//give them the option to see the full descript
			cout << "\nWant to read the full description (y or n): ";
			char ans;
			cin >> ans;
			if (toupper(ans) == 'Y') {
				cout << "You look a litle closer at the room on your right" << endl;
				(*tempNextPtr).printLong();
			}
		}
		if ((*currentPtr)._backPtr != NULL) {
			cout << "Behind you: ";
			Room* tempNextPtr = (*currentPtr)._backPtr;
			(*tempNextPtr).printShort();

			//give them the option to see the full descript
			cout << "\nWant to read the full description (y or n): ";
			char ans;
			cin >> ans;
			if (toupper(ans) == 'Y') {
				cout << "You look a litle closer at the room on your right" << endl;
				(*tempNextPtr).printLong();
			}
		}
		
		cout << "\nEnter R, L or B to move right left or back repectively: ";
		
		cin >> direction;
		direction = toupper(direction);

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

		default:
			cout << "Thats not a recognised command/direction" << endl;
			cout << "Pick a different way\n" << endl;
		}
	}

	
		/*
		if (direction == 'R') {
			if(current._nextRPtr == NULL){ 
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way" << endl;
				break;
			}
			current = *current._nextRPtr;
			current.printLong(); // just do the long one for now
		}
		else if (direction == 'L') {
			if (current._nextLPtr == NULL) {
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way" << endl;
				break;
			}
			current = *current._nextLPtr;
			current.printLong(); // just do the long one for now
		}
		else if (direction == 'B') {
			if (current._backPtr == NULL) {
				// tell them they can't go that way, and go back to the top of the list
				cout << "Dead end" << endl;
				cout << "Pick a different way" << endl;
				break;
			}
			current = *current._backPtr;
			current.printLong(); // just do the long one for now
		}
		else {
			cout << "Thats not a recognised command/direction" << endl;
			cout << "Pick a different way" << endl;
			break;
		}
	}
	*/
	return 0;
}

