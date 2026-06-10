#include <iostream>
#include <string>
using namespace std;


class Employee
{
protected:
    int employeeID;
    double baseSalary;

public:
   
    Employee(int id, double salary)
    {
        employeeID = id;
        baseSalary = salary;
    }

   
    virtual void display()
    {
        double bonus = 0.05 * baseSalary;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus (5%): " << bonus << endl;
        cout << "------------------------" << endl;
    }
};


class Manager : public Employee
{
private:
    string department;

public:
   
    Manager(int id, double salary, string dept) : Employee(id, salary)
    {
        department = dept;
    }

   
    void display() override
    {
        double bonus = 0.10 * baseSalary;
        cout << "Manager ID: " << employeeID << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Department: " << department << endl;
        cout << "Bonus (10%): " << bonus << endl;
        cout << "------------------------" << endl;
    }
};


class RegionalDirector : public Manager
{
private:
    string region;

public:
    
    RegionalDirector(int id, double salary, string dept, string reg) : Manager(id, salary, dept)
    {
        region = reg;
    }


    void display() override
    {
        double bonus = 0.15 * baseSalary;
        cout << "Regional Director ID: " << employeeID << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Region: " << region << endl;
        cout << "Bonus (15%): " << bonus << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    Employee e1(101, 50000);
    Manager m1(102, 70000, "Sales");
    RegionalDirector r1(103, 100000, "Marketing", "South Region");

    e1.display();
    m1.display();
    r1.display();

    return 0;
}