#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long normal_cmp = 0;
long long binary_cmp = 0;
long long shifts = 0;

// Normal insertion sort — scans backward to find the right spot
void NormalInsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            normal_cmp++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
    }
}

// Binary insertion sort — uses binary search to find the insert position faster
void BinaryInsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        // lower_bound does the binary search in O(log n) comparisons
        int pos = lower_bound(arr.begin(), arr.begin() + i, key,
                              [&](int a, int b)
                              {
                                  binary_cmp++;
                                  return a < b;
                              }) -
                  arr.begin();

        // Shifting is still O(n) regardless
        for (int j = i - 1; j >= pos; j--)
        {
            arr[j + 1] = arr[j];
            shifts++;
        }

        arr[pos] = key;
    }
}

int main()
{
    vector<int> arr = {9, 5, 1, 4, 3, 8, 7, 6, 2, 10};
    vector<int> a = arr;
    vector<int> b = arr;

    NormalInsertionSort(a);
    BinaryInsertionSort(b);

    cout << "Normal Insertion Comparisons: " << normal_cmp << endl;
    cout << "Binary Insertion Comparisons: " << binary_cmp << endl;
    cout << "Total Shifts: " << shifts << endl;

    cout << "\nFinal arrays:" << endl;

    cout << "Normal: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;

    cout << "Binary: ";
    for (int x : b)
        cout << x << " ";
    cout << endl;

    return 0;
}