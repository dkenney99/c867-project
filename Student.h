#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;

class Student
{
public:
    // Static Array size
    const static int dayArraySize = 3;
    // Declare all the variables
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[dayArraySize];
    DegreeProgram degreeProgram;

public:
    /* Constructor functions: */
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
    ~Student();

    /* Getters: */
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    /* Setters: */
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    /* Make it look nice and neat for the reader */
    static void printHeader();

    /* print out the student data */
    void print();
};

// 1.  Create the class Student  in the files student.h and student.cpp, 
// which includes each of the following variables