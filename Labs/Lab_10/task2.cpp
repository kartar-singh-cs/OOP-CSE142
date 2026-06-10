#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Sort
{

public:
    void Descending_Selection(vector<int> &v)
    {

        for (int i = 0; i < v.size() - 1; i++)
        {
            int maxIdx = i;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[j] > v[maxIdx])
                {
                    maxIdx = j;
                }
            }
            if (maxIdx != i)
            {
                swap(v[maxIdx], v[i]);
            }
        }
    }
};

int main()
{
    Sort s1;
    vector<int> v = {3, 6, 1, 8, 2, 9, 4};
    s1.Descending_Selection(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}