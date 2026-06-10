#include <iostream>
#include <string>
using namespace std;

class Account
{

private:
    int acc_balance;
    int acc_num;
    int code;
    void report()
    {
        cout << "Account number: " << acc_num << endl;
        cout << "Account balance: " << acc_balance << endl;
        cout << "Security code: " << code << endl;
    }

    friend class Verifier;

public:
    Account(int a, int n, int c)
    {
        acc_balance = a;
        acc_num = n;
        code = c;
    }
};

class Verifier
{

public:
    void accessReport(Account &a)
    {
        a.report();
    }
};

int main()
{
    Account a1(34231, 3200, 1234);

    Verifier v1;
    v1.accessReport(a1);

    return 0;
}