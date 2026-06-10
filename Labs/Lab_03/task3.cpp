#include <iostream>
#include <string>
using namespace std;

class Account
{

    int account_no;
    int account_bal;
    int security_code;

public:
    void initialize(int an, int ab, int s)
    {
        account_no = an;
        account_bal = ab;
        security_code = s;
    }

    void display()
    {
        cout << "Account number: " << account_no << endl;
        cout << "Account balance: " << account_bal << endl;
        cout << "Security Code: " << security_code << endl;
    }
};

int main()
{

    Account a1;
    a1.initialize(451026, 25000, 32431);
    a1.display();
    return 0;
}