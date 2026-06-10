#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Compare>
void Merge(vector<T> &arr, int left, int mid, int right, Compare cmp)
{
    vector<T> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<T> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0;
    int j = 0;
    int k = left;

    while (i < L.size() && j < R.size())
    {
        if (cmp(L[i], R[j]))
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

template <typename T, typename Compare>
void MergeSort(vector<T> &arr, int left, int right, Compare cmp)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    MergeSort(arr, left, mid, cmp);
    MergeSort(arr, mid + 1, right, cmp);
    Merge(arr, left, mid, right, cmp);
}

// OPerator Overloading For Pair Printing
ostream &operator<<(ostream &os, const pair<int, string> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

void printPair(vector<pair<int, string>> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "(" << arr[i].first << "," << arr[i].second << ")";

        if (i < arr.size() - 1)
            cout << ",";
    }
    cout << "]" << endl
         << endl;
}

template <typename T>
void print(vector<T> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ",";
    }
    cout << "]\n\n";
}

int main()
{

    auto descending = [](int L, int R)
    {
        return L > R;
    };

    auto LengthAscending = [](string L, string R)
    {
        if (L.size() == R.size())
            return L < R;

        return L.size() < R.size();
    };

    auto IntAscending = [](pair<int, string> L, pair<int, string> R)
    {
        if (L.first == R.first)
        {
            return L.second < R.second;
        }
        return L.first < R.first;
    };

    vector<int> Random = {13, 2, 5, 7, 9, 10, 6, 8, 12, 11, 14, 1, 15, 3, 4};
    vector<string> arr = {"apple", "hi", "banana", "cat", "elephant", "dog", "a"};
    vector<pair<int, string>> PairArr = {{3, "zebra"}, {1, "apple"}, {3, "ant"}, {2, "mango"}, {1, "banana"}, {2, "apple"}, {3, "bee"}};

    cout << "Before Sorting(Descending): " << endl;
    print(Random);
    MergeSort(Random, 0, Random.size() - 1, descending);
    cout << "After Sorting(Descending): " << endl;
    print(Random);

    cout << "Before Sorting(String): " << endl;
    print(arr);
    MergeSort(arr, 0, arr.size() - 1, LengthAscending);
    cout << "After Sorting(String): " << endl;
    print(arr);

    cout << "Before Sorting(Pair): " << endl;
    print(PairArr);
    MergeSort(PairArr, 0, PairArr.size() - 1, IntAscending);
    cout << "After Sorting(Pair): " << endl;
    printPair(PairArr);
    return 0;
}