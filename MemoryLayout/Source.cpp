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
using std::cout;


void printPointer(int i);

int main() {
	// which order does static storage go?
	// which order does the stack go?
	// which order does free store go?

	// the stack grows downwards towards lower adresses
	// In a C-style array elements with higher indicies are allocated at higher adresses
	return 0;
}

void printPointer(int i) {
	int* iptr = &i;
	// the unary * operator dereferences the pointer
	cout << "i = " << *iptr << "\n";
	cout << " & i = " << iptr << "\n";
}