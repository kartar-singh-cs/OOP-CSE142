#include <iostream>
#include <string>
using namespace std;

class Device
{

    const int serial;
    static int count;

public:
    Device(int s) : serial(s)
    {
        count++;
    }

    void display()
    {
        cout << "Serial number: " << serial << endl;
    }

    static void totaldevices()
    {
        cout << "Total number of devices created: " << count << endl;
    }
};

int Device::count = 0;
int main()
{
    Device d1(246), d2(678);
    d1.display();
    d2.display();
    Device::totaldevices();
  

    return 0;
}