#include <iostream>
#include <vector>
using namespace std;

// Manual Tracing
//  Initial array: [8, 3, 7, 1, 5, 2, 4]
//  Pivot = 4 (last element)
//  j = 0 -> 8 > 4 -> no swap
//  Array: [8, 3, 7, 1, 5, 2, 4]

// j = 1 -> 3 < 4 -> swap(8,3)
// Array: [3, 8, 7, 1, 5, 2, 4]

// j = 2 -> 7 > 4 -> no swap
// Array: [3, 8, 7, 1, 5, 2, 4]

// j = 3 -> 1 < 4 -> swap(8,1)
// Array: [3, 1, 7, 8, 5, 2, 4]

// j = 4 -> 5 > 4 -> no swap
// Array: [3, 1, 7, 8, 5, 2, 4]

// j = 5 -> 2 < 4 -> swap(7,2)
// Array: [3, 1, 2, 8, 5, 7, 4]

int Partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = Partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main()
{
    vector<int> arr = {8, 3, 7, 1, 5, 2, 4};
    quickSort(arr, 0, arr.size() - 1);
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}