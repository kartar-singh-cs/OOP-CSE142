#include <iostream>
#include <string>
using namespace std;

class Shape
{

    virtual void Area() = 0;
};

class Circle : public Shape
{
    double radius;

public:
    Circle(int r)
    {
        radius = r;
    }
    void Area() override
    {
        cout << "Area of Circle is: " << radius * radius * 3.14 << endl;
    }
};

class Rectangle : public Shape
{

    int length;
    int width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    void Area() override
    {
        cout << "Area of Rectangle is: " << length * width << endl;
    }
};

class Triangle : public Shape
{
    double base;
    double height;

public:
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    void Area() override
    {
        cout << "Area of Triangle is: " << (height * base) / 2 << endl;
    }
};

int main()
{
    Circle c1(5);
    Rectangle r1(4, 3);
    Triangle t1(4.5, 5);

    c1.Area();
    r1.Area();
    t1.Area();

    return 0;
}