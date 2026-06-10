#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    void setBalance(double b)
    {
        balance = b;
    }

    double getBalance()
    {
        return balance;
    }
};

class SavingsAccount : protected BankAccount
{

public:
    SavingsAccount(double d)
    {
        setBalance(d);
    }
    void addInterest(double rate)
    {
        double d = 0.0;
        d = getBalance() * rate + getBalance();
        setBalance(d);
    }
    void display()
    {
        cout << "Your current balance is: " << getBalance() << endl;
    }
};

int main()
{
    SavingsAccount s1(5000);
    s1.display();
    s1.addInterest(0.08);
    // cout << "Balance is: " << s1.getBalance();

    // Explanation
    // get Balance is not directly accessible here in main because of protected inheritance we cant directly access it

    return 0;
}