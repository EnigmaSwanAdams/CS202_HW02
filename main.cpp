/*
* Enigma Swan Adams
* CS202 HW2
* Porgram 1: Linked List
*
*more specific file info:
*file containing main,
* 
* more specifric info:
*  contains tests for container functionalities of
*  in the context of a linked list
*	- Que
*	- Stack 
*	- Insert and find
*  then prints the list 
*/

#include <list>
using std::list;
#include <queue>
using std::queue;
#include <iostream>
#include<stack>
using std::stack;
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "myValue.h"
using std::cout;
using std::endl;

	// create instances of myValue 
	myValue Qv1 = myValue("QPlant 1");
	myValue Qv2 = myValue("QPlant 2");
	
	myValue Sv1 = myValue("SPlant 1");
	myValue Sv2 = myValue("SPlant 2");
	

	

// Queue tests: FIFO
TEST_CASE("Queue: push", "[Queue:: push]") {
		GIVEN("An empty queue of myValue's, and we push 2 values into the queue") {
			queue<myValue, list<myValue>> Q;
			Q.push(Qv1);
			Q.push(Qv2);
			bool rightFront = (Q.front() == Qv1);
			bool rightBack = (Q.back() == Qv2);
			REQUIRE(rightFront);
			REQUIRE(rightBack);
		}
}
TEST_CASE("Queue: pop", "[Queue::pop]") {
	GIVEN("A Queue with two values and we pop them off one by one") {
		queue<myValue, list<myValue>> Q;
		Q.push(Qv1);
		Q.push(Qv2);
		Q.pop();
		bool right = ((Q.back() == Qv2) && (Q.front() == Qv2));
		REQUIRE(right);
		Q.pop(); 
		REQUIRE(Q.empty());
	}
}

// Stack tests: LIFO
TEST_CASE("Stack: push", "[stack::push]") {
	GIVEN("An empty stack, and we push two members on") {
		stack<myValue, list<myValue>> S;
		S.push(Sv1);
		S.push(Sv2);
		bool rightTop = (S.top() == Sv2);
		REQUIRE(rightTop);
	}
}
TEST_CASE("Stack: pop", "[Stack::pop]") {
	GIVEN("A Stack with teo members that we pop off one by one") {
		stack < myValue, list < myValue>> S;
		S.push(Sv1);
		S.push(Sv2);
		S.pop();
		bool right = (S.top() == Sv1);
		REQUIRE(right);
		S.pop();
		REQUIRE(S.empty());
	}
}

TEST_CASE("Insert and find"){
	GIVEN("An already ordered list of myValues") {
		//keep my list in sorted order
		// I'm just going to initialize it in sorted order 
		//in this case Alphabetically by the ascii character in there name (the numbers)
		// to avoid writing a whole other sort algorithm 
		myValue mV1 = myValue("Plant 1");
		myValue mV2 = myValue("Plant 2");
		myValue mV3 = myValue("Plant 3");
		myValue mV2AndAHalf = myValue("Plant 2.5");
		myValue mV4 = myValue("Plant 4");
		myValue mV5 = myValue("Plant 5");
		myValue plantToFind = mV3;
		list<myValue> L({ mV1, mV2, mV3, mV4, mV5 });
		int sizeBeforInsert = L.size();

		// Search for a value in the list (a specific plant as designated by my == operator)
		auto whereFound = find(L.begin(), L.end(), plantToFind);
		// insert a value with the iterator returned by the search 
		L.insert(whereFound, mV2AndAHalf);
		
		REQUIRE(L.size() == (sizeBeforInsert+1)); // test the size is right
		// not sure what else to test here


		// print out the list 
		for (auto i : L) {
			i.printValueBasic();
			cout << endl;
		}
	}
}
