#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend Rational operator-(const Rational &r1, const Rational &r2);
    friend Rational operator*(const Rational &r1, const Rational &r2);
    friend Rational operator/(const Rational &r1, const Rational &r2);
    friend bool operator==(const Rational &r1, const Rational &r2);
    friend bool operator!=(const Rational &r1, const Rational &r2);

public:
  
    Rational(int n = 0, int d = 1) : numerator(n), denominator(d)
    {
        reduce();
    }

    
    Rational(string n)
    {
        int i = n.find("/");
        numerator = stoi(n.substr(0, i));
        denominator = stoi(n.substr(i + 1));
        reduce();
    }

    Rational(double x)
    {
        const int precision = 1000000;
        numerator = round(x * precision);
        denominator = precision;
        reduce();
    }

    int get_num() const
    {
        return numerator;
    }

    int get_den() const
    {
        return denominator;
    }

    void set_num(int n)
    {
        numerator = n;
        reduce();
    }

    void set_den(int d)
    {
        denominator = d;
        reduce();
    }

    string to_string() const
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    int gcd(int a, int b) const
    {
        a = abs(a);
        b = abs(b);
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        if (denominator == 0) return;

        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};


Rational operator+(const Rational &r1, const Rational &r2)
{
    Rational r3;
    r3.numerator = r1.numerator * r2.denominator +
                   r2.numerator * r1.denominator;
    r3.denominator = r1.denominator * r2.denominator;
    r3.reduce();
    return r3;
}

Rational operator-(const Rational &r1, const Rational &r2)
{
    Rational r3;
    r3.numerator = r1.numerator * r2.denominator -
                   r2.numerator * r1.denominator;
    r3.denominator = r1.denominator * r2.denominator;
    r3.reduce();
    return r3;
}

Rational operator*(const Rational &r1, const Rational &r2)
{
    Rational r3;
    r3.numerator = r1.numerator * r2.numerator;
    r3.denominator = r1.denominator * r2.denominator;
    r3.reduce();
    return r3;
}

Rational operator/(const Rational &r1, const Rational &r2)
{
    Rational r3;
    r3.numerator = r1.numerator * r2.denominator;
    r3.denominator = r1.denominator * r2.numerator;
    r3.reduce();
    return r3;
}

bool operator==(const Rational &r1, const Rational &r2)
{
    return r1.numerator * r2.denominator ==
           r1.denominator * r2.numerator;
}

bool operator!=(const Rational &r1, const Rational &r2)
{
    return !(r1 == r2);
}



int main()
{
    Rational r1("3/9");
    Rational r2("15/25");
    Rational r3(0.75);

    cout << "R1: " << r1.to_string() << endl;
    cout << "R2: " << r2.to_string() << endl;
    cout << "R3: " << r3.to_string() << endl;

    cout << "Numerator of R1: " << r1.get_num() << endl;
    cout << "Denominator of R1: " << r1.get_den() << endl;

    r1.set_num(3);
    r1.set_den(5);
    cout << "Updated R1: " << r1.to_string() << endl;

    cout << "Sum: " << (r1 + r2).to_string() << endl;
    cout << "Difference: " << (r1 - r2).to_string() << endl;
    cout << "Product: " << (r1 * r2).to_string() << endl;
    cout << "Quotient: " << (r1 / r2).to_string() << endl;

    if (r1 == r2)
        cout << "R1 and R2 are equal" << endl;
    else
        cout << "R1 and R2 are not equal" << endl;

    if (r1 != r2)
        cout << "R1 and R2 are different" << endl;

    return 0;
}
