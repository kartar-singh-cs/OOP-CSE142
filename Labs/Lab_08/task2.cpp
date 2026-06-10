#include <iostream>
#include <string>
using namespace std;

class Account
{

    public:
    virtual void CalculateInterest() = 0;
};

class SavingAccount : public Account
{

    int balance;
    double rate;
    int time;

public:
    SavingAccount(int b, double r, int t)
    {
        balance = b;
        rate = r;
        time = t;
    }

    void CalculateInterest() override
    {
        double Interest = balance * (rate / 100) * time / 12;
        cout << "Savings Account Interest: $" << Interest << endl;
    }
};

class Checkings : public Account
{
    int balance;
    double rate;
    int time;
    int fee;

public:
    Checkings(int b, double r, int t, int f)
    {
        balance = b;
        rate = r;
        time = t;
        fee = f;
    }

    void CalculateInterest() override
    {
        double Interest = (balance - fee) * (rate / 100) * time / 12;
        cout << "Checking Account Interest : $" << Interest << endl;
    }
};

int main()
{
    SavingAccount s1(5000, 3, 6);
    Checkings c1(3000, 1.5, 6, 10);

    s1.CalculateInterest();
    c1.CalculateInterest();

    return 0;
}