#include <iostream>
#include <string>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    cout << n;
    if (n > 1)
    {
        cout << " x ";
    }
    if (n == 1)
    {
        cout << " = ";
    }

    return n * factorial(n - 1);
}

int main()
{

    cout << "Factorial is: " << endl;
    cout << factorial(5);
    return 0;
}