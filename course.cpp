#include "course.h"
#include <iomanip>

//----------------------------------------------------------------------
//                          constructors/gets/sets
//----------------------------------------------------------------------

course::course() { id = 0; hours = 0; department = "none"; num = "none"; hours = 0; title = "none"; }

void course::setId(int input) { if (input > 9999 && input < 100000) id = input; }

void course::setHours(int input) { if (input > 0 && input <= 2) hours = input; }

void course::setDep(string input) { if (input.length() <= 4) department = input; }

void course::setNum(string input) { if (input.length() <= 4) num = input; }

void course::setTitle(string input) { if (input.length() <= 30) title = input; }

int course::getId() { return id; }

int course::getHours() { return hours; }

string course::getDept() { return department; }

string course::getNum() { return num; }

string course::getTitle() { return title; }

//----------------------------------------------------------------------
//                            print
//----------------------------------------------------------------------

void course::print() {
	cout << setw(6) << left << id << setw(5) << department << setw(4) << num << right << setw(4) << hours << left << " " << title << endl;
}

//----------------------------------------------------------------------
//                              set
//----------------------------------------------------------------------

void course::set(int newId, string newDept, string newNum, int newHours, string newTitle) {
	id = newId; department = newDept; num = newNum; hours = newHours; title = newTitle; 
}
