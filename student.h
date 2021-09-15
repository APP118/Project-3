#pragma once
//----------------------------------------------------------------------
// class student
//----------------------------------------------------------------------
// A simple class to describe a student.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

class student {
public:
	student();

	//gets
	int getId(); string getFirst(); string getLast();

	//sets
	void setId(int input); void setFirst(string input); void setLast(string input);

	void print();

private:
	int id;
	string first, last;
};