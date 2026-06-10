#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Global comparison counter
long long comparisons = 0;

// ---------------- INSERTION SORT ----------------
void InsertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= low)
        {
            comparisons++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// ---------------- MEDIAN OF THREE ----------------
int medianOfThree(vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    // move median to end as pivot
    swap(arr[mid], arr[high]);
    return arr[high];
}

// ---------------- PARTITION ----------------
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ---------------- HYBRID SORT ----------------
void HybridSort(vector<int> &arr, int low, int high, int k)
{
    if (low >= high)
        return;

    // switch to insertion sort for small arrays
    if (high - low + 1 <= k)
    {
        InsertionSort(arr, low, high);
        return;
    }

    int p = Partition(arr, low, high);

    HybridSort(arr, low, p - 1, k);
    HybridSort(arr, p + 1, high, k);
}

// ---------------- RANDOM ARRAY GENERATOR ----------------
vector<int> generateArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
    return arr;
}

// ---------------- MAIN EXPERIMENT ----------------
int main()
{
    vector<int> sizes = {50, 200, 1000};
    vector<int> ks = {5, 10, 20};

    cout << "===== HYBRID SORT PERFORMANCE (COMPARISONS) =====\n\n";
    cout << "n\tk\tComparisons\n";
    cout << "---------------------------\n";

    for (int n : sizes)
    {
        for (int k : ks)
        {
            vector<int> arr = generateArray(n);
            comparisons = 0;

            HybridSort(arr, 0, n - 1, k);

            cout << n << "\t" << k << "\t" << comparisons << "\n";
        }
    }

    cout << "\n===== OBSERVATION =====\n";
    cout << "Best k is usually around 10 or 20.\n";
    cout << "Small arrays benefit from Insertion Sort due to low overhead and better cache efficiency.\n";

    return 0;
}