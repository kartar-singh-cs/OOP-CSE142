#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{

public:
    virtual void calculateArea()
    {

        cout << "Calculating area of shape." << endl;
    }
};

class Rectangle : public Shape
{

    double length;
    double width;

public:
    Rectangle(double l = 0, double w = 0)
    {
        length = l;
        width = w;
    }

    void calculateArea() override
    {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Circle : public Shape
{

    double radius;

public:
    Circle(double r = 0)
    {
        radius = r;
    }

    void calculateArea() override
    {
        Shape::calculateArea();
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

class Triangle : public Shape
{
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void calculateArea() override
    {
        double s = (a + b + c) / 2;
        double h = s * (s - a) * (s - b) * (s - c);
        double f = sqrt(h);

        cout << "Area of Triangle is: " << f << endl;
    }
};

int main()
{
    int choice;
    cout << "How many sides do you want to enter: ";
    cin >> choice;

    Shape *ptr = NULL;

    if (choice == 1)
    {
        double r;
        cout << "Enter Radius: ";
        cin >> r;
        ptr = new Circle(r);
        ptr->calculateArea();
        delete ptr;
    }

    else if (choice == 2)
    {
        double l, w;
        cout << "Enter length and width respectively: ";
        cin >> l >> w;
        ptr = new Rectangle(l, w);
        ptr->calculateArea();
        delete ptr;
    }

    else if (choice == 3)
    {
        double a, b, c;
        cout << "Enter three Sides: ";
        cin >> a >> b >> c;
        ptr = new Triangle(a, b, c);
        ptr->calculateArea();
        delete ptr;
    }
    else
    {
        cout << "Please enter Valid Number." << endl;
    
    }

    return 0;
}