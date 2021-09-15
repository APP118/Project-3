#include "stuList.h"
#include <fstream>

//----------------------------------------------------------------------
//                         constructor/set/get
//----------------------------------------------------------------------

stuList::stuList() { numStudents = 0; }

int stuList::getNumStudents() { return numStudents; }

student stuList::getStudent(int input)
{
    for (int i = 0; i < numStudents; i++) {
        if (input == students[i].getId())
            return students[i];
    }
    student empty;
    return empty;
}

//----------------------------------------------------------------------
//                             read
//----------------------------------------------------------------------

void stuList::read() {
    ifstream f;
    f.open("students.txt");
    if (f.fail()) {
        cout << "File failed to open" << endl;
        return;
    }
    int num;
    f >> num;
    numStudents = num;
    for (int i = 0; i < num; i++) {
        int newId;
        string newLast, newFirst;
        f >> newId >> newLast >> newFirst;
        students[i].setId(newId);
        students[i].setLast(newLast);
        students[i].setFirst(newFirst);
    }
    f.close();
}

//----------------------------------------------------------------------
//                            print
//----------------------------------------------------------------------

void stuList::print() {
    cout << "========= Student List (" << numStudents << ") ==========" << endl
         << " ID#  Last Name       First Name" << endl
         << "----- --------------- ---------------" << endl;
    for (int i = 0; i < numStudents; i++) {
        students[i].print();
    }
}
