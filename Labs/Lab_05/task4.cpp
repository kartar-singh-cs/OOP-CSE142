#include <iostream>
using namespace std;

class Payment
{

public:
    void processPayment()
    {
        cout << "Processing a generic payment." << endl;
    }
};

class CreditCardPayment : public Payment
{
public:
    void processPayment()
    {
        cout << "Processing payment via Credit Card." << endl;
    }
};

class PayPalPayment : public Payment
{

public:
    void processPayment()
    {
        cout << "Processing payment via Paypal." << endl;
    }
};

class CryptoPayment : public Payment
{

public:
    void processPayment()
    {
        cout << "Processing payment via Cryptocurrency." << endl;
    }
};

int main()
{
    Payment p1;
    p1.processPayment();
    CreditCardPayment c1;
    c1.processPayment();
    PayPalPayment pa1;
    pa1.processPayment();
    CryptoPayment cr1;
    cr1.processPayment();

    return 0;
}