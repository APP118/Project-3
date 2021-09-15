#pragma once

//----------------------------------------------------------------------
// class regList
//----------------------------------------------------------------------
// A class to describe a registration list along with many functions
//----------------------------------------------------------------------

#include <iostream>
#include "registration.h"

using namespace std;

const int MAX_REGS = 100;

class regList {
public:
	regList();
	int getNumRegistrations();
	void read();
	void write();
	bool addRegistration(int inStuId, int inCourseId, string inTerm);
	int search(int inStuId, int inCourseId, string inTerm);
	bool dropRegistration(int inStuId, int inCourseId, string inTerm);
	int getSchedule(int inStuId, string inTerm, int courseIds[]);
	int getRoster(int inCourseId, string inTerm, int StuIds[]);
	string sortKey(registration r);
	void sort(registration regs[]);
	void print();

private:
	registration registrations[MAX_REGS];
	int numRegs;
};