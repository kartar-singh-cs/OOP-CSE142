#include <iostream>
#include <string>
using namespace std;

// Shape Class
class Shape
{

protected:
    string color;

public:
    void displayColor()
    {
        cout << "The Color of your Mercedes is: " << color << endl;
    }
};

/// Circle Class
class Circle : public Shape
{

private:
    double radius;

public:
    Circle(double r, string c)
    {
        radius = r;
        color = c;
    }
    void area()
    {
        cout << "The area is: " << radius * radius * 3.14 << endl;
    }
};

int main()
{
    Circle c1(8.0, "Blue");
    c1.area();
    c1.displayColor();

    return 0;
}