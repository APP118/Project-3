#pragma once

//----------------------------------------------------------------------
// class catalog
//----------------------------------------------------------------------
// A simple class to describe a catalog.
//----------------------------------------------------------------------

#include "course.h"

const int MAX = 20;
const int NOT_FOUND = -1;

class catalog {
public:
	catalog();
	void read();
	course getCourse(int input);
	void print();
	int getNumCourses();
private:
	int numCourses;
	course courses[MAX];
};