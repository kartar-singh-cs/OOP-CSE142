#include <iostream>
#include <stdexcept>
using namespace std;

class DivisionByZeorException
{

public:
    const char *what() const
    {
        return "Error: Division by zero is not allowed.";
    }
};

double division()
{
    double a, b;
    cout << "Enter two numbers for division: ";

    if (!(cin >> a >> b))
    {
        throw runtime_error("Invalid input");
    }

    if (b == 0)
    {
        throw DivisionByZeorException();
    }

    if (b < 0)
    {
        cout << "Warning denominator is negative, converting to positive. ";
        b = -b;
    }

    return a / b;
}

int main()
{
    bool b = true;
    char choice;

    while (b)
    {
        try
        {
            double result = division();
            cout << "Result: " << result << endl;
        }

        catch (DivisionByZeorException e)
        {
            cout << e.what() << endl;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }

        cout << "DO you wnat to try again? (y/n): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
        {
            b = false;
        }
    }
    return 0;
}