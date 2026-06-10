#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
void sort_array(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

template <class T>
void reverse_array(T *arr, int size)
{
    int j = size - 1;
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[j]);
        j--;
    }
}

template <class T>
int binary_search(T *arr, int size, T target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {4, 3, 2, 4};
    int size = 4;

    cout << "Before Sorting: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    sort_array(arr, size);

    cout << "After Sorting: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int target = 4;
    cout << "Target index: " << binary_search(arr, size, target) << endl;

    reverse_array(arr, size);

    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}