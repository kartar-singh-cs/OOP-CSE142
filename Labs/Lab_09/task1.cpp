#include <iostream>
using namespace std;

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0.0)
    {
        return 1;
    }
    return a / b;
}

int main()
{
    int a = 15;
    int b = 4;
    typedef double (*OP)(double, double);
    OP op[4] = {add, subtract, multiply, divide};

    for (int i = 0; i < 4; i++)
    {
        cout << op[i](a, b) << " ";
    }

    return 0;
}