#include <iostream>
using namespace std;

int main()
{
    int min_value = 10;
    int max_value = 50;

    auto inRange = [min_value, max_value](int value)
    {
        if (min_value <= value && value <= max_value)
        {
            return true;
        }
        return false;
    };

    int count = 0;
    auto countInRange = [&count, inRange](int value)
    {
        if (inRange(value))
        {
            count++;
        }
        return count;
    };

    auto scaleAndCheck = [inRange](auto x, auto factor)
    {
        if (inRange(x * factor))
        {
            return x * factor;
        }
        return -1;
    };

  cout<<countInRange(10)<<endl;
  cout<<countInRange(20)<<endl;
  cout<<countInRange(30)<<endl;
  cout<<countInRange(40)<<endl;
  cout<<countInRange(50)<<endl;

    return 0;
}