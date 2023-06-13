#include "Student.h"
/* Function for no params gives blank/zero default values*/
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < dayArraySize; i++)
        this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

/* Function for the constructor with all the parameters */
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < dayArraySize; i++)
        this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}
/* Destructor does nothing */
Student::~Student() {}

/* Making of the getters and their return functions*/
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

/* Making of the setters and the attributes they set*/
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
    for (int i = 0; i < dayArraySize; i++)
        this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
    cout << "StudentID | First Name | Last Name | Email Address | Age | # of days to complete each course | Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentID() << "\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t";
    cout << this->getEmailAddress() << "\t";
    cout << this->getAge() << "\t";
    cout << this->getDays()[0] << ",";
    cout << this->getDays()[1] << ",";
    cout << this->getDays()[2] << "\t";
    cout << degreeProgramStrings[this->getDegreeProgram()] << "\n";
}

// 2.  Create each of the following functions in the Student class:
// getters, setters, constructors and mutators for the Student object