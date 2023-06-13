// StudentRosterTerminalApp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Roster.h"
using namespace std;
using std::endl;

int main()
{
    cout << "Course: Scripting and Programming - Applications - C867\n"
        << "Programming Language: C++\n"
        << "ID: 006160738\n"
        << "Name: Daniel Kenney" << std::endl
        << std::endl;

    // input data A.  Modify the “studentData Table” to include your personal information as the last item.

    const string studentData[] =
    { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Daniel,Kenney,dken115@wgu.edu,24,54,72,41,SOFTWARE" 

    };

    const int studentDataTable = 5; 
    // Create the roster
    Roster roster;                 

    for (int i = 0; i < studentDataTable; i++)
        roster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    roster.printAll();
    cout << std::endl;

    cout << "Displaying all software students:" << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    cout << "Displaying invalid email addess: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl
        << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
