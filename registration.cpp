#include "registration.h"
#include <iomanip>
#include <iostream>

//----------------------------------------------------------------------
//                        constructor/sets/gets
//----------------------------------------------------------------------

registration::registration() { stuId = 0; courseId = 0; term = "none"; }

void registration::set(int newStuId, int newCourseId, string newTerm) { 
    if (newStuId > 9999 && newStuId < 100000)
        stuId = newStuId;
    if (newCourseId > 9999 && newStuId < 100000)
        courseId = newCourseId;
    if (newTerm.size() == 6)
        term = newTerm;
}

int registration::getStuId(){ return stuId; }

int registration::getCourseId(){ return courseId; }

string registration::getTerm() { return term; }

//----------------------------------------------------------------------
//                          print
//----------------------------------------------------------------------

void registration::print() { cout << left << setw(6) << stuId << setw(6) << courseId << term << endl; }
