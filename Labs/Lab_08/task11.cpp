#include <iostream>
#include <string>
using namespace std;

template <class T>
int element_frequency(T *arr, int size, T search)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            count++;
        }
    }

    if (count == 0)
    {
        cout << "Don't find it." << endl;
    }

    return count;
}

int main()
{
    int size = 4;

    int arr[4] = {1, 2, 3, 2};
    int search = 2;

    string arr1[4] = {"Jujhar", "kartar", "sagar", "kartar"};
    string search1 = "kartar";

    cout << "Frequency in int is: "
         << element_frequency(arr, size, search) << endl;

    cout << "Frequency in string is: "
         << element_frequency(arr1, size, search1) << endl;

    return 0;
}