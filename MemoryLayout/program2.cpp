/*
* Enigma Swan Adams
* CS202 HW2
* Porgram 2: Memory Layout
*
*more specific file info:
*file containing main,
*
* tests whethor adresses go up or down 
* for various places in memory
*/


#include <iostream>;
#include <vector>;
using std::vector;
using std::cout;
using std::endl;
using std::string;


int main() {
	// which order does static storage go?
	static int x1 = 1;
	static int x2 = 2;
	if (&x1 > &x2) {cout << "As more spaces are alocated in static storage the adress numbers go down" << endl;}
	if (&x1 < &x2) {cout << "As more spaces are alocated in static storage the adress numbers go up" << endl; }

	// which order does the stack go?
	int y1 = 1;
	int y2 = 2;
	if (&y1 > &y2) { cout << "As more spaces are alocated on the stack the adress numbers go down" << endl; }
	if (&y1 < &y2) { cout << "As more spaces are alocated on the stack the the adress numbers go up" << endl; }

	// which order does free store go?
	// the other two are consistent, but sometimes the this are alocated at lower adresses
	// and sometimes at hihger adresses on the heap
	auto ptrZ1 = new int;
	auto ptrZ2 = new int;
	if (ptrZ1 > ptrZ2) { cout << "This time the addresses alocated on the heap went down" << endl; }
	if (ptrZ1 < ptrZ2) { cout << "This time the addresses alocated on the heap went up" << endl; }

	// interesting test / experiment
	cout << "printing the adresses of all the previously declared variables..." << endl;
	vector<int*> vec{ &x1, &y1, ptrZ1, &x2, &y2, ptrZ2 };
	for(auto i: vec){
		///printPointer(*i); // test
	}
	// via this test I have discovered the this printPointer function given in
	// the homework handout doesn't work since
	// it is passed an integer by value, so the pointer it prints will alaways be the one 
	// pointing to that functions copy of the integer
	 
	// here I actually print the pointer values
	cout << "\nStatic storage address example: " << vec.at(0);
	cout << "\nStack storage address example: " << vec.at(1);
	cout << "\nFree Store address example: " << vec.at(2);
	return 0;
}
