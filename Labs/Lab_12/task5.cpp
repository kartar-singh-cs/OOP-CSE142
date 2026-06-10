#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int count1 = 0;
int count2 = 0;

int partition(vector<int> &arr, int low, int high)
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
        count1++;
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

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

// Random one
int partitionRandom(vector<int> &arr, int low, int high)
{
    int randomIndex = low + rand() % (high + 1 - low);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        count2++;
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRandom(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = partitionRandom(arr, low, high);
    quickSortRandom(arr, low, pivot - 1);
    quickSortRandom(arr, pivot + 1, high);
}

void print(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    cout << endl;
}

int main()
{
    srand(time(0));
    vector<int> arr1 = {1, 1, 3, 3, 3, 4, 5, 5, 7, 9, 23, 23, 45, 56, 89, 90};
    vector<int> arr2 = {7, 2, 14, 1, 9, 5, 11, 3, 15, 6, 10, 4, 13, 8, 12};
    cout << "Before Sorting: " << endl;
    print(arr1);
    cout << "Total Counts: " << count1 << endl;

    cout << endl;
    cout << "After Sorting (Last Element Pivot): " << endl;
    quickSort(arr1, 0, arr1.size() - 1);
    print(arr1);
    cout << "Total Counts(Sorted): " << count1 << endl;

    cout << endl;
    cout << "After Sorting (Random Element Pivot): " << endl;
    quickSortRandom(arr2, 0, arr2.size() - 1);
    print(arr2);
    cout << "Total Counts(Random): " << count2 << endl;

    return 0;
}