#include <iostream>
#include <string>
using namespace std;

template <class T1>

void swap_values(T1 &first, T1 &second)
{
    T1 temp = first;
    first = second;
    second = temp;
}

int main()
{
    int x = 5;
    int y = 10;
    cout << "Before Swapping: x = " << x << ", y = " << y << endl;
    swap_values(x, y);
    cout << "After Swaping: x = " << x << ", y = " << y << endl;

    string s1 = "Kartar", s2 = "Sagar";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    swap_values(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl
         << endl;

    return 0;
}