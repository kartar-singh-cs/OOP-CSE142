#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count1 = 0;
int count2 = 0;

// Merge Sort
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
        count1++;
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

// Quick Sort

int PivotIndex(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
        count2++;
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int partition = PivotIndex(arr, low, high);

    QuickSort(arr, low, partition - 1);
    QuickSort(arr, partition + 1, high);
}

int main()
{
    vector<int> sorted1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> Reversed1 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> Random1 = {13, 2, 5, 7, 9, 10, 6, 8, 12, 11, 14, 1, 15, 3, 4};

    vector<int> sorted2;
    vector<int> Reversed2;
    vector<int> Random2;
    sorted2 = sorted1;
    Reversed2 = Reversed1;
    Random2 = Random1;

    cout << "Merge Sorting(Sorted): ";
    MergeSort(sorted1, 0, sorted1.size() - 1);

    cout << count1 << endl;
    cout << "Quick Sort(Sorted): ";
    QuickSort(sorted2, 0, sorted2.size() - 1);

    cout << count2 << endl
         << endl;

    count1 = 0;
    count2 = 0;

    cout << "Merge Sorting(Reversed): ";
    MergeSort(Reversed1, 0, Reversed1.size() - 1);

    cout << count1 << endl;
    cout << "Quick Sort(Reversed): ";
    QuickSort(Reversed2, 0, Reversed2.size() - 1);

    cout << count2 << endl
         << endl;

    count1 = 0;
    count2 = 0;

    cout << "Merge Sorting(Random): ";
    MergeSort(Random1, 0, Random1.size() - 1);

    cout << count1 << endl;
    cout << "Quick Sort(Random): ";
    QuickSort(Random2, 0, Random2.size() - 1);

    cout << count2 << endl
         << endl;

    return 0;
}