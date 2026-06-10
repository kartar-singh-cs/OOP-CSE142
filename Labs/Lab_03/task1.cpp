#include <iostream>
#include <string>
using namespace std;

class CrystalPair
{

    int size = 2;
    int *crystal;

public:
    CrystalPair()
    {
        size = 2;
        crystal = new int[size];
        for (int i = 0; i < size; i++)
        {
            crystal[i] = 0;
        }
    }
    CrystalPair(int *arr, int s)
    {

        size = s;
        crystal = new int[size];
        for (int i = 0; i < s; i++)
        {
            crystal[i] = arr[i];
        }
    }

    int sum()
    {
        int s = 0;
        for (int i = 0; i < size; i++)
        {
            s += crystal[i];
        }
        return s;
    }

    CrystalPair(CrystalPair &other)
    {
        size = other.size;
        crystal = new int[size];

        for (int i = 0; i < size; i++)
        {
            crystal[i] = other.crystal[i];
        }
    }
    void setCrystal(int index, int value)
    {
        if (index == 0 || index == 1)
        {
            crystal[index] = value;
        }
        else
        {
            cout << "Please set index correctly!" << endl;
        }
    }

    void display()
    {
        cout << "Crystal powers: ";

        for (int i = 0; i < size; i++)
        {
            cout << crystal[i] << " ";
        }
        cout << endl
             << "Total power: " << sum() << endl;
    }

    ~CrystalPair()
    {
        delete[] crystal;
    }
};

int main()
{

    int size = 2;
    int arr[size] = {25, 45};
    CrystalPair c1(arr, size);
    CrystalPair c2 = c1;
    cout << "Original Crystals: " << endl;
    c1.display();
    cout << endl
         << "Copied Crystals: " << endl;
    c2.display();
    cout << endl;
    c2.setCrystal(1, 30);
    cout << "After Updating: " << endl;
    cout << "Original one: " << endl;
    c1.display();
    cout << endl
         << "Copied One: " << endl;
    c2.display();

    return 0;
}