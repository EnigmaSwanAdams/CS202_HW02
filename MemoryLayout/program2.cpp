/*
* Enigma Swan Adams
* CS202 HW2
* Porgram 2: Memory Layout
*
*more specific file info:
*file containing main,
*
* 
*/


#include <iostream>;
#include <vector>;
using std::vector;
using std::cout;
using std::endl;
using std::string;

void printPointer(int i);

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
	if (ptrZ1 > ptrZ2) { cout << "This time the adresses alocated on the heap went down" << endl; }
	if (ptrZ1 < ptrZ2) { cout << "This time the adresses alocated on the heap went up" << endl; }

	// interesting test / expieriment
	int* Xptr = &x1;
	int* Yptr = &y1;

	printPointer(x1);
	printPointer(y1);
	if (Xptr == Yptr) { cout << "EQUAL?"; } // this doesn't get triggered
	// yet the print shows the saem hex number
	// something to do with the differnt types of memory maybe being given there own relative adresses
	// amd thats whats being printed
	return 0;
}

void printPointer(int i) {
	int* iptr = &i;
	// the unary * operator dereferences the pointer
	cout << "i = " << *iptr << "\n";
	cout << "& i = " << iptr << "\n";
}