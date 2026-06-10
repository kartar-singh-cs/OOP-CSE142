#include <iostream>
#include <string>
using namespace std;

class AgeCalculator;

class Date
{

    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    friend class AgeCalculator;
};

class AgeCalculator
{
public:
    int Age(Date dob, Date ad )
    {

        if (dob.year > ad.year)
        {
            cout << "Please enetr correct age!" << endl;
            return 0;
        }

        {
            return ad.year - dob.year;
        }
    }
};

int main()
{
    Date d1(12, 3, 2007);
    Date d2(12,3,2025);
    AgeCalculator a1;

    cout << "Date of birth: ";
    d1.displayDate();

    int age = a1.Age(d1, d2);
    cout << "Age: " << age << " years " << endl;

    return 0;
}