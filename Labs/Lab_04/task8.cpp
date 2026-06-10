#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class Airport
{

public:
    string Fnumber;
    string operation;
    string time;
    int severity;
    int i = 0;
    int top = 0;

    Airport()
    {
    }

    // Airport(string f = "", string o = "", int t = 0)
    // {
    //     Fnumber = f;
    //     operation = o;
    //     time = t;
    // }

    Airport(string f = "", string o = "", int s = 0, string t = "")
    {
        Fnumber = f;
        operation = o;
        time = t;
        severity = s;
    }

    bool operator<(const Airport &other) const
    {
        return severity < other.severity;
    }
};

int main()
{
    priority_queue<Airport> q1;
    stack<Airport> s1;

    Airport a1[6] = {
        {"AB123", "Takeoff", 0, "10:00 AM"},
        {"CD456", "Takeoff", 0, "10:05 AM"},
        {"Ef789", "Takeoff", 0, "10:10 AM"},
        {"GH101", "Landing", 9, "10:02"},
        {"IJ202", "Landing", 10, "10:06"},
        {"KL303", "Landing", 8, "10:09"}};

    for (int i = 0; i < 6; i++)
    {

        if (a1[i].operation == "Landing")
        {
            q1.push(a1[i]);
        }

        else if (a1[i].operation == "Takeoff")
        {
            s1.push(a1[i]);
        }
        else
        {
            cout << "Please, insert correct!" << endl;
        }
    }

    cout << "Landing Flights: " << endl;
    while (!q1.empty())
    {
        Airport p1 = q1.top();
        cout << "Flight Number: " << p1.Fnumber << ", Severity: " << p1.severity << ", Arrival Time: " << p1.time << endl;
        q1.pop();
    }
    cout << endl;
    cout << "Take Off Flights: " << endl;
    while (!s1.empty())
    {
        Airport p1 = s1.top();
        cout << "Flight Number: " << p1.Fnumber << ", Arrival Time: " << p1.time << endl;
        s1.pop();
    }
    return 0;
}