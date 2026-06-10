#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Patient
{
public:
    string name;
    int severity;
    int arrivalTime;

    Patient(string n = "", int s = 0, int a = 0)
    {
        name = n;
        severity = s;
        arrivalTime = a;
    }
    bool operator<(const Patient &other) const
    {

        if (severity == other.severity)
        {
            return arrivalTime > other.arrivalTime;
        }

        return severity < other.severity;
    }
};

int main()
{

    priority_queue<Patient> p1;

    p1.push(Patient{"Alice", 5, 1});
    p1.push(Patient{"Bob", 8, 2});
    p1.push(Patient{"Charlie", 8, 3});
    p1.push(Patient{"Dana", 3, 4});

    p1.top();
    while (!p1.empty())
    {
        Patient p = p1.top();
        cout << p.name << ", (Severity): " << p.severity << ", Arrival: " << p.arrivalTime << endl;
        p1.pop();
    }

    return 0;
}