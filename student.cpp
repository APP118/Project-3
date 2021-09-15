#include "student.h"
#include <iomanip>

//----------------------------------------------------------------------
//                          constructor/get/set
//----------------------------------------------------------------------

student::student() { id = 0; first = "none"; last = "none"; }

int student::getId() { return id; }

string student::getFirst() { return first; }

string student::getLast() { return last; }

void student::setId(int input) {
	if (input > 9999 && input < 100000)
		id = input;
}

void student::setFirst(string input) {
	if (input.size() <= 15)
		first = input;
}

void student::setLast(string input) {
	if (input.size() <= 15)
		last = input;
}

//----------------------------------------------------------------------
//                            print
//----------------------------------------------------------------------

void student::print() { cout << id << " " << left << setw(15) << last << " " << first << endl; }
