#include <iostream>
#include <string>
using namespace std;

class Football
{

    double s;

public:
   
    Football(double n)
    {
        s = n;
    }

    double getArea()
    {
        return s;
    }
    virtual void Area()
    {
        cout << "Area of Football Ground(square) is: " << s * s << endl;
    }
};

class Cricket : public Football
{

private:
    double l;
    double w;

public:
    Cricket(double n) : Football(n)
    {
        l = getArea() * 2;
        w = getArea();
    }
    void Area()
    {
        cout << "Area of Cricket Ground(Rectangle) is: " << l * w << endl;
    }
};

class Robotic : public Football
{
private:
    double r = getArea();

public:
    Robotic(double n) : Football(n)
    {
    }
    void Area()
    {
        cout << "Area of Robotic Ground(Circle) is: " << 3.14 * r * r;
    }
};

int main()
{
    Football f1(3.1);
    f1.Area();
    Cricket c1(3.1);
    c1.Area();
    Robotic r1(3.1);
    r1.Area();

    return 0;
}