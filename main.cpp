//-------------------------------------------------------
//                 Project 3 test code
//-------------------------------------------------------

// comment out any #includes needed for testing
#include <iostream>
#include "catalog.h"
#include "student.h"
#include "stuList.h"
#include "regList.h"
#include "crapp.h"

/*
void testCourse() {
	cout << "Testing empty course class...\n";
	course c;
	c.print();

	cout << "Testing populated course class...\n";
	c.set(11112, "CS", "102", 4, "OOP in C++");
	c.print();
	cout << "gets: id=" << c.getId() << " dept=" << c.getDept()
		<< " num=" << c.getNum() << " hrs=" << c.getHours()
		<< " title=" << c.getTitle() << endl;
}

void testCatalog() {

	cout << "\nTesting empty catalog class...\n";
	catalog cat;
	cout << "#courses=" << cat.getNumCourses() << endl;
	cat.print(); // empty

	cout << "\nTesting populate catalog class, including read()...\n";
	cat.read();
	cat.print();
	cout << "#courses=" << cat.getNumCourses() << endl;
	course c = cat.getCourse(-1);
	cout << "Get not found course: \n";
	c.print();
	c = cat.getCourse(11111);
	cout << "Get CS 101 course\n";
	c.print();
}

void testStudent() {
	cout << "Testing empty student class...\n";
	student c;
	c.print();

	cout << "Testing populated student class...\n";
	c.setId(54321);
	c.setFirst("Sammy");
	c.setLast("Hagar");
	c.print();
	cout << "gets: id=" << c.getId()
		<< " first=" << c.getFirst()
		<< " last=" << c.getLast() << endl;
}

void testStuList() {
	cout << "\nTesting empty stuList class...\n";
	stuList s;
	cout << "#stu=" << s.getNumStudents() << endl;
	s.print();

	cout << "\nTesting populated stuList class, including read()...\n";
	s.read();
	s.print();
	cout << "#stu=" << s.getNumStudents() << endl;
	student c = s.getStudent(-1);
	cout << "Get not found course: \n";
	c.print();
	c = s.getStudent(33333);
	cout << "Test Get Shafika\n";
	c.print();
}

void testRegistration() {
	cout << "Testing empty registration class...\n";
	registration reg;
	reg.print();

	cout << "Testing populated registration class...\n";
	reg.set(33333, 11111, "2020FA");
	reg.print();
	cout << reg.getStuId() << " " << reg.getCourseId() << " " << reg.getTerm() << endl;
}

void testRegList() {
	cout << "Testing empty regList class...\n";
	regList list;
	cout << "#regs = " << list.getNumRegistrations() << endl;
	list.print();

	cout << "Testing populated regList class - read()...\n";
	list.read();
	cout << "#regs = " << list.getNumRegistrations() << endl;
	list.print();

	cout << "Add 11111 33333 2021FA...";
	bool OK = list.addRegistration(11111, 33333, "2021FA");
	if (OK) cout << "good\n"; else cout << "test failed\n";

	cout << "Add 22222 44444 2021FA...";
	OK = list.addRegistration(22222, 44444, "2021FA");
	if (OK) cout << "good\n"; else cout << "test failed\n";
	list.print();

	cout << "Drop 0 0 1920FA...";
	OK = list.dropRegistration(0, 0, "1920FA");
	if (!OK) cout << "good\n"; else cout << "failed test\n";

	cout << "Drop 11111 33333 2021FA...";
	OK = list.dropRegistration(11111, 33333, "2021FA");
	if (OK) cout << "good\n"; else cout << "failed test\n";
	list.print();

	cout << "getSchedule(11111,2020FA): ";
	int ilist[50];
	int num = list.getSchedule(11111, "2020FA", ilist);
	cout << "num=" << num << "  course ids= ";
	for (int i = 0; i < num; i++)
		cout << ilist[i] << " ";
	cout << endl;

	cout << "getRoster(11111,2020FA): ";
	num = list.getRoster(11111, "2020FA", ilist);
	cout << "num = " << num << "  student ids= ";
	for (int i = 0; i < num; i++)
		cout << ilist[i] << " ";
	cout << endl;

	list.write(); // should sort records
	cout << "Registration data written...check regsout.txt\n";
}

int main() {
	//testCourse();
	//testCatalog();
	//testStudent();
	//testStuList();
	//testRegistration();
	//testRegList();
	//testRegList();

	// the REAL main:
	 crapp c;
	 c.go();

	return 0;
}
*/

//-------------------------------------------------------
//				CS 215 - Fall 2020 - Project 3  
//-------------------------------------------------------
// Author:  YOUR NAME HERE !!
// Section: YOUR SECTION HERE!!
// I received help from:
// 
//-------------------------------------------------------
#include "crapp.h"

using namespace std;

int main() {
	crapp c;
	c.go();
	return 0;
}
