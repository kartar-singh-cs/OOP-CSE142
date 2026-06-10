#include <iostream>
#include <algorithm>
using namespace std;

class Selection
{

public:
    void sort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i)
            {
                swap(arr[minIdx], arr[i]);
            }
        }
    }
};

int main()
{
    int arr[5] = {29, 10, 14, 37, 13};
    Selection s1;
    s1.sort(arr, 5);

    cout << "Accessding sort: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}