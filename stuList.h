#pragma once

//----------------------------------------------------------------------
// class studentList
//----------------------------------------------------------------------
// A simple class to describe a student list.
//----------------------------------------------------------------------

#include "student.h"

const int MAX_STU = 20;

class stuList {
public:
	stuList();
	int getNumStudents();
	student getStudent(int input);
	void read();
	void print();
private:
	int numStudents;
	student students[MAX_STU];
};