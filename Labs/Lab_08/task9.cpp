#include <iostream>
#include <string>
using namespace std;

template <class T1>
T1 max_value(T1 first, T1 second, T1 third)
{

    if (first >= second && first >= third)
    {
        return first;
    }
    else if (second >= first && second >= third)
    {
        return second;
    }
    else
    {
        return third;
    }
}

int main()
{
    cout << "Maximum in Int type is: " << max_value(5, 6, 7) << endl;

    cout << "Maximum in String is: " << max_value(string("Kartar Singh"), string("Sagar Kataria"), string("Jujhar Lund")) << endl;

    cout << "Maximum in char is: " << max_value('A', 'B', 'C') << endl;

    cout << "Maximum in float or double is: " << max_value(2.4, 3.4, 5.6) << endl;

    return 0;
}