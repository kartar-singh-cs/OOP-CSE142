#include <iostream>
#include <vector>
using namespace std;

class Sorting
{

public:
    int comparison = 0;
    int swapping = 0;
    int selection_comparison = 0;
    int swap_comparison = 0;

    // Selection Sort
    void Selection(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < arr.size(); j++)
            {
                selection_comparison++;
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i)
            {
                swap_comparison++;
                swap(arr[minIdx], arr[i]);
            }
        }
    }

    // Insertion
    void Insertion(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && (comparison++, arr[j] > key))
            {
                swapping++;
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    void printout()
    {
        cout << "Selection: " << selection_comparison << " cmp, " << swap_comparison << " swaps" << endl;
        cout << "Insertion: " << comparison << " cmp, " << swapping << " shifts" << endl;
    }
};

int main()
{
    Sorting s1;

    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                          10, 11, 12, 13, 14, 15};

    vector<int> a = sorted;
    vector<int> b = sorted;

    s1.Insertion(a);
    s1.Selection(b);

    cout << "-------Already Sorted--------" << endl;
    s1.printout();

    s1.comparison = 0;
    s1.swapping = 0;
    s1.selection_comparison = 0;
    s1.swap_comparison = 0;

    vector<int> rev = {15, 14, 13, 12, 11, 10, 9, 8, 7,
                       6, 5, 4, 3, 2, 1};

    vector<int> c = rev;
    vector<int> d = rev;

    s1.Insertion(c);
    s1.Selection(d);

    cout << "\n-------Reverse Sorted--------" << endl;
    s1.printout();

    s1.comparison = 0;
    s1.swapping = 0;
    s1.selection_comparison = 0;
    s1.swap_comparison = 0;

    vector<int> random = {1, 6, 4, 7, 8, 9, 2, 3, 5,
                          10, 13, 15, 14, 12, 11};

    vector<int> e = random;
    vector<int> f = random;

    s1.Insertion(e);
    s1.Selection(f);

    cout << "\n-------Random--------" << endl;
    s1.printout();

    return 0;
}