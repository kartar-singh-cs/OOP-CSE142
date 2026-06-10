#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

// ---------------- SELECTION SORT ----------------
void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ---------------- INSERTION SORT ----------------
void InsertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// ---------------- MERGE SORT ----------------
void Merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < L.size())
        arr[k++] = L[i++];
    while (j < R.size())
        arr[k++] = R[j++];
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;

    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

// ---------------- QUICK SORT ----------------
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

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int p = Partition(arr, low, high);

    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
}

// ---------------- GENERATE RANDOM ARRAY ----------------
vector<int> generateArray(int n)
{
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100000);

    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);

    return arr;
}

// ---------------- TIME FUNCTION ----------------
template <typename Func>
long long measure(Func f, vector<int> arr)
{
    auto start = high_resolution_clock::now();
    f(arr);
    auto end = high_resolution_clock::now();

    return duration_cast<milliseconds>(end - start).count();
}

// ---------------- MAIN ----------------
int main()
{
    vector<int> sizes = {100, 1000, 10000};

    cout << "===== SORTING PERFORMANCE BENCHMARK =====\n\n";

    cout << "n\tSelection\tInsertion\tMerge\t\tQuick\n";
    cout << "-------------------------------------------------------------\n";

    for (int n : sizes)
    {
        vector<int> base = generateArray(n);

        long long sel = measure([&](vector<int> a)
                                { SelectionSort(a); }, base);

        long long ins = measure([&](vector<int> a)
                                { InsertionSort(a); }, base);

        long long mer = measure([&](vector<int> a)
                                { MergeSort(a, 0, a.size() - 1); }, base);

        long long qui = measure([&](vector<int> a)
                                { QuickSort(a, 0, a.size() - 1); }, base);

        cout << n << "\t"
             << sel << " ms\t\t"
             << ins << " ms\t\t"
             << mer << " ms\t\t"
             << qui << " ms\n";
    }

    cout << "\n===== OBSERVATION =====\n";
    cout << "1. Selection & Insertion grow ~ O(n^2)\n";
    cout << "2. Merge & Quick grow ~ O(n log n)\n";
    cout << "3. Difference becomes clearly visible at n ≈ 1000\n";
    cout << "   and very obvious at n = 10000\n";

    return 0;
}