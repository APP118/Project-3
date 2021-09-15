#pragma once

#include <iostream>

//----------------------------------------------------------------------
// class course
//----------------------------------------------------------------------
// A simple class to describe a course.
//----------------------------------------------------------------------

using namespace std;

class course {
public:
	course();
	//sets
	void setId(int input); void setHours(int input);  void setDep(string input); void setNum(string input); void setTitle(string input);
	//gets
	int getId(); int getHours(); string getDept(); string getNum(); string getTitle();
	void print();
	void set(int newId, string newDept, string newNum, int newHours, string newTitle);

private:
	int id, hours;
	string department, num, title;
};