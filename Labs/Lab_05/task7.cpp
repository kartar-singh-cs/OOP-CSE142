#include <iostream>
#include <string>
using namespace std;

int Multiply(int a, int b)
{
    return a * b;
}

int Multiply(int a, int b, int c)
{
    return a * b * c;
}

double Multiply(double a, double b)
{
    return a * b;
}

double Multiply(double a, double b, double c)
{
    return a * b * c;
}

int main()
{

    cout<<"Two integers Multiplication: "<<Multiply(4,5)<<endl;
    cout<<"Three integers Multiplication: "<<Multiply(4,5,6)<<endl;
    cout<<"Two Decimal Multiplication: "<<Multiply(4.3,5.4)<<endl;
    cout<<"Three integers Multiplication: "<<Multiply(4.3,5.4,6.5)<<endl;
    return 0;
}