#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Sort
{

public:
    int ins_counter = 0; // counts comparisons in insertion sort
    int sel_counter = 0; // counts comparisons in selection sort

    // Reset counters before each new experiment
    void reset()
    {
        ins_counter = 0;
        sel_counter = 0;
    }

    // ---------------- SELECTION SORT ----------------
    void Selection(vector<int> &t1)
    {

        for (int i = 0; i < t1.size() - 1; i++)
        {
            int minIdx = i;

            for (int j = i + 1; j < t1.size(); j++)
            {
                sel_counter++; // counting comparison
                if (t1[minIdx] > t1[j])
                {
                    minIdx = j;
                }
            }

            if (minIdx != i)
            {
                swap(t1[minIdx], t1[i]);
            }
        }
    }

    // ---------------- INSERTION SORT ----------------
    void Insertion(vector<int> &t1)
    {
        for (int i = 1; i < t1.size(); i++)
        {
            int key = t1[i];
            int j = i - 1;

            while (j >= 0 && (ins_counter++, t1[j] > key))
            {
                t1[j + 1] = t1[j];
                j--;
            }

            t1[j + 1] = key;
        }
    }

    // ---------------- DISTURB FUNCTION ----------------
    void disturb(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Perform k random swaps to make array "nearly sorted"
        for (int i = 0; i < k; i++)
        {
            int x = rand() % n;
            int y = rand() % n;

            swap(arr[x], arr[y]);
        }
    }
};

int main()
{

    vector<int> base(1000);
    for (int i = 0; i < 1000; i++)
    {
        base[i] = i;
    }

    vector<int> k = {0, 5, 10, 50, 100, 500};

    Sort s;

    // Step 3: Run experiment for each k
    for (int i = 0; i < k.size(); i++)
    {
        vector<int> arr = base;
        s.disturb(arr, k[i]);

        vector<int> arr1 = arr; // for insertion sort
        vector<int> arr2 = arr; // for selection sort

        // Run insertion sort and record comparisons
        s.reset();
        s.Insertion(arr1);
        int ins = s.ins_counter;

        // Run selection sort and record comparisons
        s.reset();
        s.Selection(arr2);
        int sel = s.sel_counter;

        // Print results in table format
        cout << "K = " << k[i]
             << " | Insertion = " << ins
             << " | Selection = " << sel << endl;
    }

    return 0;
}