#include <iostream>
#include <string>
using namespace std;

class Student
{

    int *Scores;

public:
    void input()
    {
        Scores = new int[5];
        cout << "Enter marks for (Math, Physics, Chemistry, English, Computer Science): " << endl;

        for (int i = 0; i < 5; i++)
        {

            cout << "Enter " << i + 1 << ": ";
            cin >> Scores[i];
        }
    }

    int calculteTotalScore()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += Scores[i];
        }
        return sum;
    }

    ~Student()
    {
        delete[] Scores;
    }
};

int main()
{
    int count = 0;
    Student students[3];

    cout << "Enter Marks for every student " << endl;
    for (int i = 0; i < 3; i++)
    {
        students[i].input();
        cout << endl;
    }

    int ali = students[0].calculteTotalScore();

    for (int i = 1; i < 3; i++)
    {

        if (ali < students[i].calculteTotalScore())
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No one has higher marks than Ali" << endl;
    }
    else
    {
        cout << count << " students has higher marks!" << endl;
    }

    return 0;
}