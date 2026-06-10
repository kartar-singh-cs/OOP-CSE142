#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IntegerSet
{

    vector<bool> value;

public:
    IntegerSet()
    {
        value = vector<bool>(101, false);
    }

    IntegerSet(const vector<int> &arr)
    {
        value = vector<bool>(101, false); // initialize empty
        for (int num : arr)
        {
            if (num >= 0 && num <= 100)
                value[num] = true;
        }
    }

    IntegerSet UnionSet(const IntegerSet &other)
    {

        IntegerSet result;
        for (int i = 0; i <= 100; i++)
        {
            if (value[i] || other.value[i])
            {
                result.value[i] = true;
            }
            else
            {
                result.value[i] = false;
            }
        }

        return result;
    }

    IntegerSet Intersection(const IntegerSet &other)
    {
        IntegerSet result;
        for (int i = 0; i <= 100; i++)
        {
            if (value[i] && other.value[i])
            {
                result.value[i] = true;
            }
            else
            {
                result.value[i] = false;
            }
        }
        return result;
    }

    void insertElement(int k)
    {
        if (k >= 0 && k <= 100)
        {
            value[k] = true;
        }
    }

    void deleteElement(int k)
    {
        if (k >= 0 && k <= 100)
        {
            value[k] = false;
        }
    }

    string tostring() const
    {
        string result = "";
        for (int i = 0; i <= 100; i++)
        {
            if (value[i])
                result += to_string(i) + " ";
        }
        if (result.empty())
            return ""; // empty set
        else
            return result;
    }

    bool isEqualto(const IntegerSet &other) const
    {
        for (int i = 0; i <= 100; i++)
        {
            if (value[i] != other.value[i])
                return false;
        }
        return true;
    }
};

int main()
{
    IntegerSet I1;
    IntegerSet I2;

    I1.insertElement(1);
    I1.insertElement(3);
    I1.insertElement(5);

    I2.insertElement(1);
    I2.insertElement(4);
    I2.insertElement(5);

    cout << "Set 1 Integers: ";
    cout << "{" << I1.tostring() << "}";
    cout << endl
         << endl;

    cout << "Set 2 Integers: ";
    cout << "{" << I2.tostring() << "}";
    cout << endl
         << endl;

    IntegerSet setUnion = I1.UnionSet(I2);
    cout << "Union: ";
    cout << "{" << setUnion.tostring() << "}";

    cout << endl;

    IntegerSet setIntersection = I1.Intersection(I2);
    cout << "Intersection: ";
    cout << "{" << setIntersection.tostring() << "}";

    cout << endl
         << endl;

    cout << "Checking Equality: ";
    if (I1.isEqualto(I2))
        cout << "Both sets are equal!" << endl;
    else
        cout << "Sets are not equal!" << endl;

    return 0;
}