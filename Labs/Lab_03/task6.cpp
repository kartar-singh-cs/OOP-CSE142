#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{

private:
    string name;
    int age;
    int id;
    char gender;
    vector<double> marks;
    vector<string> subjects;
    vector<int> credits;
    double gpa;
    double cgpa;

public:
    void input()
    {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter Gender (M/F): ";
        cin >> gender;
        cout << "Enter last Semester CGPA: ";
        cin >> cgpa;

        cout << "++++++++ Subject Details +++++++++" << endl;
        cout << endl;
        int n;
        cout << "Enter number of subjects: ";
        cin >> n;

        cout << endl;
        marks.resize(n);
        subjects.resize(n);
        credits.resize(n);
        cout << "---------- Marks and Subjects Details----------" << endl
             << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter subject " << i + 1 << ": ";
            cin >> subjects[i];
            cout << "Enter Credit Hours: ";
            cin >> credits[i];
            cout << "Enter " << subjects[i] << " marks: ";
            cin >> marks[i];
            cout << "Your Grade is: ";
            if (marks[i] >= 90)
                cout << "A" << endl;
            else if (marks[i] >= 80)
                cout << "A-" << endl;
            else if (marks[i] >= 70)
                cout << "B+" << endl;
            else if (marks[i] >= 60)
                cout << "B" << endl;
            else if (marks[i] >= 50)
                cout << "B-" << endl;
            else
                cout << "C" << endl;
            cout << endl;
        }
        cout << endl;
    }

    void show()
    {

        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << id << endl;
        cout << "Gender: " << gender << endl;
    }

    double gradepoints(double marks)
    {
        if (marks >= 90)
            return 4.0;
        else if (marks >= 80)
            return 3.7;
        else if (marks >= 70)
            return 3.3;
        else if (marks >= 60)
            return 3.0;
        else if (marks >= 50)
            return 2.67;
        else
            return 2.5;
    }

    void Calculategpa()
    {
        double totalcredits = 0.0;

        double gpapoints = 0.0;
        for (int i = 0; i < marks.size(); i++)
        {
            gpapoints += gradepoints(marks[i]) * (double)credits[i];
            totalcredits += credits[i];
        }
        gpa = gpapoints / totalcredits;
        cgpa = (gpa * totalcredits + cgpa * totalcredits) / (totalcredits * 2.0);
    }

    void displayCGPA()
    {
        cout << "First Semester GPA: " << cgpa << endl;
        cout << "This Semester GPA: " << gpa << endl;
        cout << "Total CGPA: " << cgpa << endl;
    }
};

int main()
{

    Student kartar;
    kartar.input();
    cout << "\n----------- STUDENT DETAILS --------------" << endl;
    kartar.show();
    kartar.Calculategpa();
    cout << endl;
    cout << "========== CGPA ===========" << endl;
    kartar.displayCGPA();
    return 0;
}