#include <iostream>
#include <vector>
using namespace std;

//[8,5,3,2,6];
/// Briefly Explanation
// In this we do that Insertion sort works like it first take the second element and compare it with the first element we can say that with previous elemnts
//  and after that if that element is bigger than my current one at i if j(previous element) is bigger the we tart while loop in which we do it by
//  making that j elemnt equal to ith element but before that we store that ith elemnt at every loop iteration in the form of key and after while loop terminates
//  we have j = -1 so after that we do like j +1 = key we replace that

class Sort
{

public:
    void printArray(vector<int> letsgo)
    {
        for (int i = 0; i < letsgo.size(); i++)
        {
            cout << letsgo[i] << " ";
        }
        cout << endl;
    }

    void Insertion(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)

        // {4, 7, 1, 90, 34, 67, 12};
        {
            int key = arr[i]; /// Storing ith element in the key
            int j = i - 1;    // Setting j th value to start loop condition

            cout << "Pass " << i << " (Key = " << key << ")\n"; // this condition means we are now gonna start from always one more elemnt
            cout << "Shifted elements: ";

            bool shifted = false;

            while (j >= 0 && arr[j] > key)
            {
                cout << arr[j] << " "; // Shifting elements this shows that element which is gonna shifted
                arr[j + 1] = arr[j];   //  Shifting the elemtnts
                j--;                   // Decreasing j
                shifted = true;
            }

            if (!shifted)
                cout << "None"; // If No any element is shifted then  show None

            arr[j + 1] = key; // In the last it will do place the all elemtns is set and we will place our elemtn that was overwritten and stored in key now will placed on its perfect place

            cout << "\nArray after insertion: ";
            printArray(arr);
            cout << endl;
        }
    }
};

int main()
{
    Sort s1;

    cout << "Before Sorting: " << endl;
    vector<int> ok = {4, 7, 1, 90, 34, 67, 12};

    s1.printArray(ok);
    cout << endl;

    cout << "======= Sorting Function Called ==========" << endl;
    s1.Insertion(ok);
    cout << "-------------------------------------------" << endl;
    cout << "After Sorting: " << endl;
    s1.printArray(ok);

    return 0;
}