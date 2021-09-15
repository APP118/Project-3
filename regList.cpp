#include "regList.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int END = 0;
const int NOT_FOUND = -1;
const int MAX_CLASSES = 10;
const int MAX_STUDENTS = 50;

//----------------------------------------------------------------------
//                          constructor/get
//----------------------------------------------------------------------

regList::regList() { numRegs = 0; }

int regList::getNumRegistrations() { return numRegs; }

//----------------------------------------------------------------------
//                            read
//----------------------------------------------------------------------

void regList::read() {
    ifstream f;
    f.open("regsin.txt");
    if (f.fail()) {
        cout << "File failed to load" << endl;
        return;
    }
    int newStuId, newCourseId;
    string newTerm;
    f >> newStuId >> newCourseId >> newTerm;
    while(newStuId != END && newCourseId != END && newTerm != "END") {
        registrations[numRegs].set(newStuId, newCourseId, newTerm);
        numRegs++;
        f >> newStuId >> newCourseId >> newTerm;
    }
    f.close();
}

//----------------------------------------------------------------------
//                              write
//----------------------------------------------------------------------

void regList::write(){
    ofstream f;
    f.open("regsout.txt");
    if (f.fail()) {
        cout << "File failed to open" << endl;
        return;
    }
    for (int i = 0; i < numRegs; i++) {
        f << registrations[i].getStuId() << " " << registrations[i].getCourseId() << " " << registrations[i].getTerm() << endl;
    }
    f << "0 0 END" << endl;
    cout << "Registrations written to file." << endl;
}

//----------------------------------------------------------------------
//                           addRegistration
//----------------------------------------------------------------------

bool regList::addRegistration(int inStuId, int inCourseId, string inTerm) {
    if (numRegs >= MAX_REGS)
        return false;
    registrations[numRegs].set(inStuId, inCourseId, inTerm);
    numRegs++;
    return true;
}

//----------------------------------------------------------------------
//                              search
//----------------------------------------------------------------------

int regList::search(int inStuId, int inCourseId, string inTerm) {
    for (int i = 0; i < numRegs; i++) {
        if (registrations[i].getStuId() == inStuId && registrations[i].getCourseId() == inCourseId && registrations[i].getTerm() == inTerm) {
            return i;
        }
    }
    return NOT_FOUND;
}

//----------------------------------------------------------------------
//                             dropRegistration
//----------------------------------------------------------------------

bool regList::dropRegistration(int inStuId, int inCourseId, string inTerm) {
    int found = search(inStuId, inCourseId, inTerm);
    if (found == NOT_FOUND)
        return false;
    registration a, b;
    for (int i = found; i < numRegs-1; i++) {
        a = registrations[i+1];
        registrations[i].set(a.getStuId(), a.getCourseId(), a.getTerm());
    }
    registrations[numRegs].set(b.getStuId(), b.getCourseId(), b.getTerm());
    numRegs--;
    return true;
}

//----------------------------------------------------------------------
//                            getSchedule
//----------------------------------------------------------------------

int regList::getSchedule(int inStuId, string inTerm, int courseIds[]) {
    int stuCourses = 0;
    for (int i = 0; i < numRegs; i++) {
        if (stuCourses < MAX_CLASSES) {
            if (inStuId == registrations[i].getStuId() && inTerm == registrations[i].getTerm()) {
                courseIds[stuCourses] = registrations[i].getCourseId();
                stuCourses++;
            }
        }
    }
    return stuCourses;
}

//----------------------------------------------------------------------
//                            getRoster
//----------------------------------------------------------------------

int regList::getRoster(int inCourseId, string inTerm, int stuIds[])
{
    int numInCourse = 0;
    for (int i = 0; i < numRegs; i++) {
        if (numInCourse < MAX_STUDENTS) {
            if (inCourseId == registrations[i].getCourseId() && inTerm == registrations[i].getTerm()) {
                stuIds[numInCourse] = registrations[i].getStuId();
                numInCourse++;
            }
        }
    }
    return numInCourse;
}

//----------------------------------------------------------------------
//                            sortkey
//----------------------------------------------------------------------

string regList::sortKey(registration r) {
    return to_string(r.getStuId()) + r.getTerm() + to_string(r.getCourseId());
}

//----------------------------------------------------------------------
//                            sort
//----------------------------------------------------------------------

void regList::sort(registration regs[]) {
    for (int i = 0; i < numRegs - 1; i++) {
        for (int j = i + 1; j < numRegs; j++) {
            if (sortKey(registrations[i]) < sortKey(registrations[j])) {
                registration a = registrations[i];
                registrations[i] = registrations[j];
                registrations[j] = a;
            }
        }
    }
}

//----------------------------------------------------------------------
//                              print
//----------------------------------------------------------------------

void regList::print() {
    cout << "regList::print() -------------" << endl;
    for (int i = 0; i < numRegs; i++) {
        registrations[i].print();
    }
    cout << "regList::print: #regs: " << numRegs << endl;
}
