#include <iostream>
#include <string>
using namespace std;

class Football
{

protected:
    double s;

public:
    Football(double s)
    {
        this->s = s;
    }

    virtual void Area()
    {
        cout << "Area of Football Ground(Square) is: " << s * s << endl;
    }
};

class Cricket : public Football
{

private:
    double length = 2 * s;
    double width = s;

public:
    Cricket(int n) : Football(n)
    {
    }

    void Area() override
    {

        cout << "Area of Cricket Ground(Rectangle) is: " << length * width << endl;
    };
};

class Robotic : public Football
{

    double radius = s;

public:
    Robotic(int n) : Football(n)
    {
    }
    void Area()
    {
        cout << "Area of Robotic ground(Circle) is: " << (3.14 * radius * radius) << endl;
    }
};

int main()
{

    double n;
    cout << "Enter the length of Football: ";
    cin >> n;

    Football f1(n);
    Cricket c1(n);
    Robotic r1(n);

    f1.Area();
    c1.Area();
    r1.Area();

    return 0;
}
