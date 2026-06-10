#include <iostream>
using namespace std;

struct Card
{

    int value;
    char suit;
};

void Selction_sort(Card c1[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (c1[minIdx].value > c1[j].value)
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            swap(c1[minIdx], c1[i]);
        }
    }
}

void printout(Card c1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "(" << c1[i].value << "," << c1[i].suit << ") ";
    }
    cout << endl;
}

int main()
{

    Card c1[4] = {{5, 'H'}, {3, 'D'}, {5, 'D'}, {1, 'C'}};
    cout << "---------- Before Sorting ----------" << endl;
    printout(c1, 4);
    cout << endl;

    Card a[4] = {{5, 'H'}, {3, 'D'}, {5, 'D'}, {1, 'C'}};

    cout << "---------After Sorting---------" << endl;
    Selction_sort(c1, 4);
    printout(c1, 4);

    return 0;
}