#include <iostream>
#include <string>
using namespace std;

double power(int base, int exp)
{

    if (exp == 0)
    {
        return 1;
    }

    if (exp < 0)
    {
        return (1.0 / (base * power(base, -exp)));
    }

    return base * power(base, exp - 1);
}

int main()
{
    cout << "Exonential: " << endl;
    cout << power(2, 0) << endl;
    cout << power(2, 5) << endl;
    cout << power(3, 3) << endl;
    cout << power(10, 4) << endl;

    cout << endl;
    cout << "Exponential with negative power: " << endl;
    cout << power(2, -3);

    return 0;
}