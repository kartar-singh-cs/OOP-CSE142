#include <iostream>
#include <functional>
using namespace std;

function<int()> makeCounters(int start, int steps)
{
    int current = start;
    auto lambda = [current, steps]() mutable
    {
        current += steps;
        return current;
    };
    return lambda;
}
int main()
{

    auto byOne = makeCounters(0, 1);
    auto byFive = makeCounters(0, 5);
    auto countdown = makeCounters(20, -3);

    for (int i = 0; i < 15; i++)
    {
        if (i < 5)
        {
            cout << byOne() << " ";
        }

        if (i == 5)
        {
            cout << endl;
        }
        if (i >= 5 && i < 10)
        {
            cout << byFive() << " ";
        }

        if (i == 10)
        {
            cout << endl;
        }
        if (i >= 10 && i < 15)
        {
            cout << countdown() << " ";
        }
    }

    return 0;
}