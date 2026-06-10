#include <iostream>
#include <string>
using namespace std;

class Person
{

protected:
    string name;
    string CNIC;

public:
    Person(string n, string c)
    {
        name = n;
        CNIC = c;
    }
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
    }
};

class Student : public Person
{

private:
    string rollNo;
    double GPA;

public:
    Student(string n, string c, string r, double g) : Person(n, c)
    {
        rollNo = r;
        GPA = g;
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << GPA << endl;
    }
};

class Lecturer : public Person
{

private:
    string employeeID;
    string departement;

public:
    Lecturer(string n, string c, string e, string d) : Person(n, c)
    {
        employeeID = e;
        departement = d;
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Departement: " << departement << endl;
    }
};

int main()
{

    Student s1("Kartar Singh", "45101-7980930-9", "32431", 3.39);
    Lecturer L1("Sagar Kataria", "45101-6268845-7", "32422", "Computer Science");

    cout << "+++ Student Info +++" << endl;
    s1.displayInfo();
    cout << endl;

    cout << "=== Lecturer Info ===" << endl;
    L1.displayInfo();

    return 0;
}