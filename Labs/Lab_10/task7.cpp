#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

template <typename T, typename Compare>
void Insertion_Sort(vector<T> &arr, Compare cmp)
{
    for (int i = 1; i < arr.size(); i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp(arr[j], key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
template <typename T>
void printout(vector<T> &print)
{
    for (int i = 0; i < print.size(); i++)
    {
        cout << print[i] << " ";
    }
    cout << endl;
}

void printout(vector<pair<int, string>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].first << "," << v[i].second << ") ";
    }
    cout << endl;
}

int main()
{

    vector<int> test = {89, 5, 4, 6, 2, 1};

    // For Ascending Order
    auto cmp1 = [](int a, int b)
    {
        return a > b;
    };

    // String Comparison
    auto cmp2 = [](string a, string b)
    {
        return a < b;
    };

    auto cmp3 = [](pair<int, string> a, pair<int, string> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }

        return a.first > b.first;
    };

    cout << "---------Integer Sorting---------" << endl;
    cout << "Before sort" << endl;
    printout(test);

    cout << endl;
    Insertion_Sort(test, cmp1);

    cout << "After sort" << endl;
    printout(test);

    cout << "\n--------String Sorting-------" << endl;
    vector<string> s = {"Date", "Apple", "Banana", "Cherry"};

    cout << "Before sort" << endl;
    printout(s);

    cout << endl;
    Insertion_Sort(s, cmp2);

    cout << "After sort" << endl;
    printout(s);

    cout << "\n--------Both Alphabetically Sorting-------" << endl;
    vector<pair<int, string>> v = {
        {3, "dog"},
        {1, "cat"},
        {3, "apple"}};

    cout << "Before sort" << endl;
    printout(v);

    cout << endl;
    Insertion_Sort(v, cmp3);

    cout << "After sort" << endl;
    printout(v);

    return 0;
}