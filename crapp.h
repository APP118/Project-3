#pragma once

//----------------------------------------------------------------------
// class crapp
//----------------------------------------------------------------------
// A class for a lot of the main functions
//----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "stuList.h"
#include "catalog.h"
#include "regList.h"

using namespace std;

class crapp {
public:
	crapp();
	void go();
private:
	string currentTerm;
	stuList studentList;
	catalog catalogObj;
	regList registerList;

	char getOption(string prompt, string validOptions);
	char getMainMenuOption();
	void changeTerm();
	student askForStudent();
	void printRoster();
	void printSchedule(student stuObj);
	void doAdd(student stuObj);
	void doDrop(student stuObj);
	void registerStudent();
};