#include <iostream>
#include <string>
#include <vector>
using namespace std;

// [6.7.5.7]
int maxVal(vector<int> &arr, int i, int maxValue)
{
    if (i == arr.size())
    {
        return maxValue;
    }

    if (arr[i] > maxValue)
    {

        return maxVal(arr, i + 1, arr[i]);
    }

    return maxVal(arr, i + 1, maxValue);
}

// Sorted
bool sorting(vector<int> arr, int i)
{
    if (i == arr.size())
    {
        return true;
    }

    if (arr[i - 1] > arr[i])
    {
        return false;
    }

    return sorting(arr, i + 1);
}

// Printing revrse
void printReverse(const vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return;
    }

    printReverse(arr, i + 1);
    cout << arr[i] << " ";
}

int count = 0;
int countEven(const vector<int> &arr, int i = 0)
{

    if (i == arr.size())
    {
        return count;
    }

    if (arr[i] % 2 == 0)
    {
        count++;
    }

    return countEven(arr, i + 1);
}

int main()
{
    vector<int> arr = {3, 7, 1, 9, 4, 6, 2};

    cout << "\n++++++++++ Tasks +++++++++++++" << endl
         << endl;
    cout << "Max Value: " << endl;
    cout << maxVal(arr, 0, arr[0]);

    cout << endl
         << endl;

    cout << "Checking Sorting: " << endl;
    if (sorting(arr, 1))
    {
        cout << "it is sorted" << endl;
    }

    else
    {
        cout << "Array is not Sorted" << endl;
    }
    cout << endl;

    cout << "Revrse List: " << endl;
    printReverse(arr, 0);

    cout << endl;
    cout << endl;
    cout << "Total Even in array: " << endl;

    cout << countEven(arr, 0);

    return 0;
}