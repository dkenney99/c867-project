#pragma once
#include "Student.h"
#include <stdio.h>

class Roster
{
public:
    // indexes for keeping track of the value in the array
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    int ind;
    const static int studentDataTable = 5;
    int classSize;

public:
    /* Parses through the values and pulls the data from the roster */
    void parse(string row);
    /* Passes the data with the below methods and adds them */
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);
    /* Print all the data in the array, print by degree program, or print the invalid emails */
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    /* Will add up all the days in the course and divide by 3 for the average */
    void printAverageDaysInCourse(string studentID);
    /* Input the student ID and delete it from the array */
    void removeStudentByID(string studentID);
    ~Roster();

private:
    //more indexes for keeping track
    int index = -1;
    int i = 0;
};