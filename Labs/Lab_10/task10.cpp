#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// In this task i shappening that we are doing hybrid sorting because we know that for small number of integers Insertion sort is worth it and efficient
// So we are setting that with the help of k that if remaining sorting is remain is < k then we will move to Insertion sort automtically before that we will do selection sort for bigger data

int count = 0;
void HybridSort(vector<int> &arr, int k, int start, int end)
{
    if ((end - start + 1) <= k) // Comparing size if anytime it got move to insertion sort with remaining elements
    {

        for (int i = start + 1; i <= end; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= start && (count++, arr[j] > key)) // Starting with start because we have to keep record that how many elements have been sorted and how much remain that will be sorted by insertion sort
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    } // till here it is normal insertion sort

    // Doing same selection sort but with recursion because in the question it is saying it is continuously increasing start and sort the previous elements
    int minIdx = start;
    for (int j = start + 1; j <= end; j++)
    {
        if ((count++, arr[minIdx] > arr[j]))
        {
            minIdx = j;
        }
    }

    if (minIdx != start)
    {
        swap(arr[minIdx], arr[start]);
    }

    HybridSort(arr, k, start + 1, end); // recursive loop
}

void print(vector<int> p)
{

    cout << "(";
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << ",";
    }
    cout << ")" << endl;
}

int main()
{
    srand(time(0));
    int n = 100;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    print(arr);

    cout << endl;
    cout << "=================================== After Sorting =========================================" << endl;
    HybridSort(arr, 70, 0, arr.size() - 1);

    print(arr);

    cout << endl;
    cout << "Total Counts: " << endl;
    cout << count << endl;
    return 0;
}