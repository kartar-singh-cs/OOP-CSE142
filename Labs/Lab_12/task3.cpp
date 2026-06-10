#include <iostream>
#include <vector>
using namespace std;

struct Card
{
    int value;
    char suit;
};

// Merge Sort
void Merge(vector<Card> &arr, int left, int mid, int right)
{
    vector<Card> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<Card> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < L.size() && j < R.size())
    {
        if (L[i].value <= R[j].value)
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
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

void MergeSort(vector<Card> &arr, int left, int right)
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

int partition(vector<Card> &arr, int low, int high)
{
    int pivot = arr[high].value;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].value <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Card> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main()
{
    vector<Card> arr1 = {
        {5, 'H'}, {3, 'D'}, {5, 'S'}, {3, 'C'}};

    vector<Card> arr2 = arr1;

    cout << "Original array:\n";
    for (int i = 0; i < arr1.size(); i++)
        cout << "(" << arr1[i].value << "," << arr1[i].suit << ") ";
    cout << endl;

    MergeSort(arr1, 0, arr1.size() - 1);

    cout << "\nAfter Merge Sort (Stable):\n";
    for (int i = 0; i < arr1.size(); i++)
        cout << "(" << arr1[i].value << "," << arr1[i].suit << ") ";
    cout << endl;

    quickSort(arr2, 0, arr2.size() - 1);

    cout << "\nAfter Quick Sort (Not Guaranteed Stable):\n";
    for (int i = 0; i < arr2.size(); i++)
        cout << "(" << arr2[i].value << "," << arr2[i].suit << ") ";
    cout << endl;

    return 0;
}
