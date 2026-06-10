#include <iostream>
using namespace std;

class Person
{

protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        cout << "Person constructor" << endl;
        name = n;
        if (a < 0)
        {
            throw runtime_error("Age can't be negative.");
        }
        age = a;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual string getRole()
    {
        return "Person.";
    }
};

class Student : virtual public Person
{
protected:
    int erp;

public:
    Student(string n, int a, int e) : Person(n, a)
    {
        cout << "Student constructor" << endl;
        erp = e;
    }

    void display() override
    {
        Person::display();
        ;
        cout << "Student ID: " << erp << endl;
    }

    string getRole() override
    {
        return "Student";
    }
};

class Employee : virtual public Person
{
protected:
    int EmployeeID;

public:
    Employee(string n, int a, int e) : Person(n, a)
    {
        cout << "Employee constructor" << endl;
        EmployeeID = e;
    }

    void display() override
    {
        Person::display();
        cout << "Employee id: " << EmployeeID << endl;
    }

    string getRole() override
    {
        return "Employee";
    }
};

class TeachingAssistant : public Student, public Employee
{

public:
    TeachingAssistant(string n, int a, int e, int erp) : Person(n, a), Employee(n, a, e), Student(n, a, erp)
    {
        cout << "Teaching Assistant constructor" << endl;
    }

    void display() override
    {
        Person::display();
        cout << "Student ID: " << erp << ", Employee ID: " << EmployeeID << endl;
    }

    string getRole() override
    {
        return "Teaching Assistant";
    }
};

void testDiamondProblem()
{
    try
    {

        cout << "Creating Student object:" << endl;
        Student s1("Kartar singh", 18, 32431);
        s1.display();
        cout << s1.getRole() << endl<<endl;

        cout << "\nEmployee Object" << endl;
        Employee e1("Juhar", 20, 32422);
        e1.display();
        cout << e1.getRole() << endl<<endl;

        cout << "Teaching Assistant object" << endl;
        TeachingAssistant t1("Sagar", 21, 32459, 32422);
        t1.display();
        cout << t1.getRole() << endl<<endl;

        Person *p1 = &t1;
        cout << "Polymorphism test via pointer" << endl;
        p1->display();
        cout << p1->getRole();
        cout << endl<<endl;

        // Exception test
        Person p2("Sahij", -90);
    }

    catch (exception &ex)
    {
        cout << "Exception occured: " << ex.what() << endl;
    }
}

int main()
{

    testDiamondProblem();
    return 0;
}