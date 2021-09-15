#include "catalog.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//----------------------------------------------------------------------
//                            constructor
//----------------------------------------------------------------------

catalog::catalog() {
    numCourses = 0;
}

//----------------------------------------------------------------------
//                               read
//----------------------------------------------------------------------

void catalog::read() {
    ifstream f;
    int nums;
    int ids;
    string dep;
    string numb;
    int hrs;
    string titles;
    f.open("courses.txt");
    f >> nums;
    numCourses = nums;
    if (f.fail())
        cout << "fail" << endl;
    for (int i = 0; i < nums; i++) {
        f >> ids >> dep >> numb >> hrs;
        if (f.peek() == ' ') f.ignore();
        getline(f, titles);
        courses[i].set(ids, dep, numb, hrs, titles);
    }
    f.close();
}

//----------------------------------------------------------------------
//                            getCourse
//----------------------------------------------------------------------

course catalog::getCourse(int input)
{
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].getId() == input) {
            return courses[i];
        }
    }
    course empty;
    return empty;
}

//----------------------------------------------------------------------
//                            print
//----------------------------------------------------------------------

void catalog::print() {
    cout << "================== Course List (" << numCourses << ") ==================" << endl
         << " ID#  Dept Num   Hr Title                         " << endl
         << "----- ---- ----  -- ------------------------------" << endl;
    for (int i = 0; i < numCourses; i++) {
        courses[i].print();
    }

}

//----------------------------------------------------------------------
//                            getNumCourses
//----------------------------------------------------------------------

int catalog::getNumCourses() { return numCourses; }
