#include <iostream>
#include <string>
using namespace std;

// Reason
// it reverse the order because of backtracking
// In void function if you cout before recursive call it just prints the numner normally
// But if you cout after then it print after ending all recursive calls and prints in backtrack
// like as example it makes stack and last element is on top in our case is 1 and after ending recursieve calls it prints top element and and move on to second one just like this

void countdown(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    countdown(n - 1);
}

void countup(int n)
{
    if (n == 0)
    {
        return;
    }

    countup(n - 1);
    cout << n << endl;
}

int main()
{

    countdown(5);
    cout << endl;
    countup(5);
    cout << endl;

    return 0;
}