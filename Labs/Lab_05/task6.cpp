#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int ID;

public:
    Person(int i = 0)
    {
        ID = i;
    }

    virtual void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> ID;
    }

    virtual void displayData()
    {

        cout << "Employee ID is: " << ID;
    }
};

class Admin : public Person
{

    string name;
    double income;

public:
    void getData() override
    {

        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    double bonus()
    {

        return 0.05 * income;
    }

    void displayData() override
    {
        Person::displayData();
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << income << endl;
        cout << "Bonus amount they receieved: " << bonus() << endl;
    }
};

class Accounts : public Person
{

    string name;
    double income;

public:
    void getData() override
    {

        Person::getData();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    double bonus()
    {

        return 0.05 * income;
    }

    void displayData() override
    {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << income << endl;
        cout << "Bonus amount they receieved: " << bonus() << endl;
    }
};

int main()
{
    int choice;
    cout << "Enter 1 for Admins, 2 for Accounts: ";
    cin >> choice;

    cout << endl;
    if (choice == 1)
    {
        cout << "------Welcome to Admin Center------" << endl;
        Admin a1;
        a1.getData();
        a1.bonus();
        a1.displayData();
    }

    else if (choice == 2)
    {
        Accounts a2;
        a2.getData();
        a2.bonus();
        a2.displayData();
    }

    return 0;
}