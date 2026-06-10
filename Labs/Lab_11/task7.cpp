#include <iostream>
#include <string>
#include <vector>
using namespace std;

// First Case
//  it hase no base case because of no base it will run continuously and never stops so that the problem
int factorial(int n)
{
    if (n == 1) // this base case is missing
    {
        return 1;
    }

    return n * factorial(n - 1);
}

// Mistake was order susbstr is sending new index from 1st index and adding first character of every string so when it backtrack it adds all
// like add first index value and send again from next index by using substr
//  abc
string reverse(const string &s)
{
    if (s.size() == 0)
    {
        return s;
    }

    return reverse(s.substr(1)) + s[0];
}

// Buggy Sum
// You just forget to add arrr[i] so thats why it is not adding it is just backtracking and end so what should it return to do that we should add arr[i]
// so it an add while backtrack and return

int sum(const vector<int> &arr, int i = 0)
{
    if (i == (int)arr.size())
        return 0;

    return arr[i] + sum(arr, i + 1); // forgets to include arr [i]
}

int main()
{
    vector<int> v = {1, 2, 3};
    cout << "======== BUGG TESTS ============" << endl;
    cout << "Factorial calling: " << factorial(3) << endl;
    cout << "Reverse string: " << reverse("abc") << endl;
    cout << "Sum: " << sum(v);

    return 0;
}
