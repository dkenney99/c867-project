#include <string>
#include "Roster.h"

// parses each row
void Roster::parse(string studentdata)
{
    // find the comma and add to the index, parsing through each of the comma seperated
    // values and then putting them in the directory for student data
    int rhs = studentdata.find(',');
    string sID = studentdata.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string sFName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string sLName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string sEmail = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int sAge = stoi(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d1 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d2 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d3 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);

    DegreeProgram dt = SECURITY;

    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E')
        dt = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O')
        dt = SOFTWARE;
    else if (studentdata.at(lhs) == 'N')
        dt = NETWORK;

    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, dt);
}

// using thwe add method to put all the different params alongside the strings respectively
void Roster::add(string studentID, string fName, string lName, string email, int age, int d1, int d2, int d3, DegreeProgram dt)
{
    // array for days to be in the constructor
    int darr[3] = { d1, d2, d3 };
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, darr, dt); // use full constructor
}

// students will be displayed with output in a seperated pattern
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
        Roster::classRosterArray[i]->print();
}

// finds each email and then checks with the find method against the criteria
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmailAddress());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    if (!any)
        cout << "NONE" << std::endl;
}

// Add up all the days and then divide by 3 for the average day in the course
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] +
                classRosterArray[i]->getDays()[1] +
                classRosterArray[i]->getDays()[2]) /
                3
                << std::endl;
        }
    }
}

// get the degreeprogram type and match it with the OG header
void Roster::printByDegreeProgram(DegreeProgram dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dt)
            classRosterArray[i]->print();
    }
    cout << std::endl;
}

// parse through each of the n items in the roster and if its a match you delete if not you say its not found
void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl
            << std::endl;
        this->printAll();
    }
    else
        cout << studentID << " not found." << std::endl
        << std::endl;
    ;
}

// simple destrcutor for the memory cleanup
Roster::~Roster()
{
    for (i = 0; i < numStudents; ++i)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

// E.  Create a Roster class (roster.cpp)