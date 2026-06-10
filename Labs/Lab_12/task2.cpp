#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void Merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
        count++;
    }

    while (i < L.size())
    {
        arr[k++] = L[i++];
    }
    while (j < R.size())
    {
        arr[k++] = R[j++];
    }
}

void MergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<int> arr2 = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr3 = {6, 7, 4, 9, 3, 0, 1, 6, 90, 87, 68, 34, 16, 56, 34, 7};

    MergeSort(arr, 0, arr.size() - 1);
    cout << "FUll Sorted List: " << endl;
    cout << count << endl;
    count = 0;

    MergeSort(arr2, 0, arr2.size() - 1);
    cout << "Reverse List: " << endl;
    cout << count << endl;
    count = 0;

    MergeSort(arr3, 0, arr3.size() - 1);
    cout << "Random List: " << endl;
    cout << count << endl;
    count = 0;

    return 0;
}