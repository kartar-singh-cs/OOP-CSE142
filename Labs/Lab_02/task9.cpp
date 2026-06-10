#include <iostream>
#include <string>
using namespace std;

class BankAccount
{

    string name;
    string accountNumber;
    int balance;

public:
    BankAccount(string name, string accountNumber, int balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    string getacc()
    {
        return accountNumber;
    }

    string getname()
    {
        return name;
    }

    void deposit(int balance)
    {
        this->balance = this->balance + balance;
    }

    void Withdraw(int amount)
    {
        if (amount <= balance)
        {
            this->balance -= amount;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display()
    {
        cout << "Name: " << name << endl
             << "Account number: " << accountNumber << endl
             << "Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount acc("Kartar Singh", "45101-7980930-9", 45000);
    acc.display();

    cout << "\nDepositing 5000...\n";
    acc.deposit(5000);
    acc.display();

    cout << "\nWithdrawing 10000...\n";
    acc.Withdraw(10000);
    acc.display();

    return 0;
}