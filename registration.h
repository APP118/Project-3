#pragma once

//----------------------------------------------------------------------
// class registration
//----------------------------------------------------------------------
// A simple class to describe a registration.
//----------------------------------------------------------------------

#include <iostream>

using namespace std;

class registration {
public:
	registration();
	void set(int newStuId, int newCourseId, string newTerm);
	int getStuId(); int getCourseId(); string getTerm();
	void print();
private:
	int stuId, courseId;
	string term;
};