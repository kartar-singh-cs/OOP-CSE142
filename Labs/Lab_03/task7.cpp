#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
    vector<char> s;

public:
    bool determine(string a)
    {
        int top = -1;
        for (int i = 0; i < a.length(); i++)
        {

            if (a[i] == '[' || a[i] == '(' || a[i] == '{')
            {
                s.push_back(a[i]);
                top++;
            }
            else
            {
                if (s.size() == 0)
                {
                    return false;
                }

                if (a[i] == ']' || a[i] == ')' || a[i] == '}')
                {
                    if (s[top] == '(' && a[i] == ')' ||
                        s[top] == '{' && a[i] == '{' ||
                        s[top] == '[' && a[i] == ']')
                    {
                        s.pop_back();
                        top--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return s.size() == 0;
    }
};

int main()
{

    Stack s1;
    string a;
    cout << "Enter brackets ( [], () ): ";
    cin >> a;

    if (s1.determine(a))
    {
        cout << "It is balanced!" << endl;
    }
    else
    {
        cout << "Oops is hard!" << endl;
    }

    return 0;
}