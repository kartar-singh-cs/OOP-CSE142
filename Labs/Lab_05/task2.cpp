#include <iostream>
#include <string>
using namespace std;

class Shape
{

    int length;
    int width;

public:
    Shape(int l = 0, int w = 0)
    {
        length = l;
        width = w;
    }

    int Area()
    {
        return length * width;
    }

    Shape operator+(Shape &other)
    {

        int helper = this->Area() + other.Area();
        return Shape(helper, 1);
    }
};

int main()
{

    Shape s1(4, 5);
    Shape s2(5, 6);
    Shape s3 = s1 + s2;

    cout << "Shape 1 Area: " << s1.Area() << endl;
    cout << "Shape 2 Area: " << s2.Area() << endl;
    cout << "Added Area of (Shape 1 + Shape 2): "<<s3.Area();

    return 0;
}