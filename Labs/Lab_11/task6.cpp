#include <iostream>
#include <string>
using namespace std;

int countChar(const string &s, char c, int i = 0)
{

    if (i == s.length())
    {
        return 0;
    }

    if (s[i] == c)
    {

        return 1 + countChar(s, c, i + 1);
    }

    return countChar(s, c, i + 1);
}

string removeChar(const string &s, char c, int i = 0)
{

    if (i == s.length())
    {
        return "";
    }

    if (s[i] != c)
    {
        return s[i] + removeChar(s, c, i + 1);
    }

    return removeChar(s, c, i + 1);
}

string toBinary(int n)
{
    if (n == 0)
    {
        return "0";
    }

    if (n == 1)
    {
        return "1";
    }

    return toBinary(n / 2) + to_string(n % 2);
}

int main()
{
    string s = "banana";
    cout << "Number of times Character appear: " << countChar(s, 'a') << endl;
    cout << "This is removed String: " << removeChar("hello world", 'l') << endl;
    cout << "This is to Binary: " << toBinary(10);
}