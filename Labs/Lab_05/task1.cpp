#include <iostream>
#include <string>
using namespace std;

class Test
{

private:
    double count;

public:
    Test(double c = 0.0)
    {
        count = c;
    }

    void operator--()
    {
        count = count * 4;
    }

    void operator--(int)
    {
        count = count / 4;
    }
    void display()
    {
        cout << "The value of your object is: " << count << endl;
    }
};

int main()
{
    Test t1(10);

    --t1;
    t1.display();
    t1--;
    t1.display();

    return 0;
}