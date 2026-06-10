#include <iostream>
#include <string>
using namespace std;

int sumDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + sumDigits(n / 10);
}

int main()
{
    cout << "The Sum Of Digits(0): " << sumDigits(0) << endl;
    cout << "The Sum Of Digits(9): " << sumDigits(9) << endl;
    cout << "The Sum Of Digits(123): " << sumDigits(123) << endl;
    cout << "The Sum Of Digits(999): " << sumDigits(999) << endl;

    return 0;
}