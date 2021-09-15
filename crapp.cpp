#include "crapp.h"

const int MAX_STUS = 50;
const int MAX_CLASSES = 10;

//----------------------------------------------------------------------
//                            constructor
//----------------------------------------------------------------------

crapp::crapp() {
	currentTerm = "2020FA";
	studentList.read();
	catalogObj.read();
	registerList.read();
}

//----------------------------------------------------------------------
//                               go
//----------------------------------------------------------------------

void crapp::go() {
	char ans = getMainMenuOption();
	while (ans != 'X') {
		if (ans == 'R') {
			registerStudent();
		}
		else if (ans == 'C') {
			printRoster();
		}
		else if (ans == 'P') {
			catalogObj.print();
		}
		else if (ans == 'S') {
			studentList.print();
		}
		else if (ans == 'W') {
			registerList.write();
		}
		else if (ans == 'T') {
			changeTerm();
		}
		ans = getMainMenuOption();
	}
}

//----------------------------------------------------------------------
//                            getOption
//----------------------------------------------------------------------

char crapp::getOption(string prompt, string validOptions) {
	string option;
	char opt;
	cout << prompt;
	cin >> option;
	opt = toupper(option[0]); // upper case of first char of entered value

	// while opt is not one of the chars in the validOptions string
	while (validOptions.find(opt) == string::npos) {
		cout << "Invalid option!\n";
		cout << prompt;
		cin >> option;
		opt = toupper(option[0]);
	}
	return opt;
} // getOption()

//------------------------------------------------------------------------
//						getMainMenuOption()
//------------------------------------------------------------------------

char crapp::getMainMenuOption() {
	// print the main menu
	cout << "\n============ CRAPP Main Menu =============\n";
	cout << "          Current Term: " << currentTerm << endl;
	cout << "R. Register Student\n";
	cout << "C. Course Roster\n";
	cout << "P. Print Catalog\n";
	cout << "S. Student List\n";
	cout << "W. Write registations\n";
	cout << "T. Term Change\n";
	cout << "X. Exit\n";
	return getOption("Enter menu option: ", "RCPSWTX");
} // getMainMenuOption()

//------------------------------------------------------------------------
//						        changeTerm()
//------------------------------------------------------------------------

void crapp::changeTerm() {
	cout << "Current term:   " << currentTerm << endl;
	cout << "Enter new term: ";
	cin >> currentTerm;
} // changeTerm()

student crapp::askForStudent() {
	int idInput;
	cout << "Enter student ID (0 to cancel): ";
	cin >> idInput;
	while (idInput != 0) {
		student a;
		a = studentList.getStudent(idInput);
		if (a.getId() == 0) {
			cout << "Student ID " << idInput << " not found" << endl;
		}
		else {
			return a;
		}
		cout << "Enter student ID (0 to cancel): ";
		cin >> idInput;
	}
	student b;
	return b;
}
 
//----------------------------------------------------------------------
//                            printRoster
//----------------------------------------------------------------------

void crapp::printRoster() {
	int input;
	cout << "Enter course ID (0 to cancel): ";
	cin >> input;
	course a;
	a = catalogObj.getCourse(input);
	if (a.getId() == 0) {
		cout << "Invalid course ID" << endl;
	}
	else {
		int studentsInClass[MAX_STUS];
		int num = registerList.getRoster(input, currentTerm, studentsInClass);
		cout << "---------------------------------------------------" << endl
			<< "TERM: " << currentTerm << endl;
		a.print();
		cout << "---------------------------------------------------" << endl
			 << "STUID LAST            FIRST" << endl
			 << "----- --------------- ---------------" << endl;
		for (int i = 0; i < num; i++) {
			student a;
			a = studentList.getStudent(studentsInClass[i]);
			a.print();
		}
		cout << "Number of students: " << num << endl << "---------------------------------------------------" << endl;
	}

}

//----------------------------------------------------------------------
//                            printSchedule
//----------------------------------------------------------------------

void crapp::printSchedule(student stuObj) {
	int schedule[MAX_CLASSES];
	int num = registerList.getSchedule(stuObj.getId(), currentTerm, schedule);
	cout << "---------------------------------------------------" << endl
		<< "TERM: " << currentTerm << "   STUDENT: " << stuObj.getLast() << ", " << stuObj.getLast() << " (" << stuObj.getId() << ")" << endl
		<< "---------------------------------------------------" << endl
		<< "CRSID DEPT NUM  HR TITLE" << endl
		<< "----- ---- ---- -- --------------------------------" << endl;
	int totalHours = 0;
	for (int i = 0; i < num; i++) {
		course a;
		a = catalogObj.getCourse(schedule[i]);
		a.print();
		totalHours = totalHours + a.getHours();
	}
	cout << "Total hours: " << totalHours << endl
		<< "---------------------------------------------------" << endl;
}

//----------------------------------------------------------------------
//                             doAdd
//----------------------------------------------------------------------

void crapp::doAdd(student stuObj) {
	int input;
	cout << "Enter course ID to add: ";
	cin >> input;
	course a = catalogObj.getCourse(input);
	if (a.getId() == 0) {
		cout << "Course ID invalid!" << endl;
		return;
	}
	if (registerList.addRegistration(stuObj.getId(), input, currentTerm)) 
		cout << "Course added." << endl; 
	else 
		cout << "Course add failed!" << endl;
}

//----------------------------------------------------------------------
//                              doDrop
//----------------------------------------------------------------------

void crapp::doDrop(student stuObj) {
	int input;
	cout << "Enter course ID to drop: ";
	cin >> input;
	course a = catalogObj.getCourse(input);
	bool found = registerList.dropRegistration(stuObj.getId(), a.getId(), currentTerm);
	if (found) {
		cout << "Course dropped." << endl;
	}
	else {
		cout << "Student not registered for that course" << endl;
	}
}

//----------------------------------------------------------------------
//                            registerStudent
//----------------------------------------------------------------------

void crapp::registerStudent() {
	string input;
	student a = askForStudent();
	if (a.getId() == 0) return;
	printSchedule(a);
	char ans = getOption("(D)rop, (A)dd, (C)atalog, e(X)it? ", "DACX");
	while (ans != 'X') {
		if (ans == 'D') {
			doDrop(a);
		}
		else if (ans == 'A') {
			doAdd(a);
		}
		else if (ans == 'C') {
			catalogObj.print();
		}
		ans = getOption("(D)rop, (A)dd, (C)atalog, e(X)it? ", "DACX");
	}
}