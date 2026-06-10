#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class Multiplier
{

private:
    double factor;
    double callCount;

public:
    Multiplier(double f)
    {
        factor = f;
        callCount = 0;
    }

    double operator()(double x)
    {
        ++callCount;
        return x * factor;
    }

    int getCount()
    {
        return callCount;
    }
};

void dispatch(double val, vector<function<double(double)>> &handlers)
{
    for (int i = 0; i < handlers.size(); i++)
    {
        double result = handlers[i](val);
        cout << "Result: " << result << endl;
    }
}

int main()
{
    Multiplier m1(2);
    Multiplier m2(3);
    Multiplier m3(5);

    vector<function<double(double)>> handler;
    handler.push_back(ref(m1));
    handler.push_back(ref(m2));
    handler.push_back(ref(m3));

    dispatch(6.0, handler);

    return 0;
}