#include <iostream>
#include <string>
using namespace std;

int count = 0;

int fib(int n)
{
    count++;
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << "Fibonacci Series: " << endl;
    cout << fib(4);
    cout << endl;
    cout << "Total Calls For Fibonacci is: " << count;

    return 0;
}