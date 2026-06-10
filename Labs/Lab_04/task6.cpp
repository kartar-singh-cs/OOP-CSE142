#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Stack
{

private:
    int capacity;
    int *arr;
    int i = 0;

public:
    Stack(int capacity = 10)
    {
        this->capacity = capacity;
        arr = new int[capacity];
    }
    void push(int value)
    {
        if (capacity == i)
        {
            capacity = capacity * 2;

            int *newArr = new int[capacity];

            for (int j = 0; j < i; j++)
            {
                newArr[j] = arr[j];
            }

            delete[] arr;
            arr = newArr;
        }
        arr[i] = value;
        i++;
    }

    int pop()
    {

        if (i == 0)
        {
            cout << "Please,First insert element." << endl;
            return 0;
        }
        i--;
        int temp = arr[i];
        arr[i] = 0;
        return temp;
    }

    int peek()
    {
        if (i == 0)
        {
            cout << "Beta ,First insert element." << endl;
            return 0;
        }

        return arr[i - 1];
    }

    bool isEmpty()
    {
        if (i == 0)
        {
            return true;
        }

        return false;
    }

    int getSize()
    {
        return (i);
    }

    string toString()
    {
        string result;
        result = "[";
        for (int j = 0; j < i; j++)
        {

            result += to_string(arr[j]);
            if (j < i - 1)
                result += ", ";
        }
        result += "]";
        return result;
    }

    void reverseMiddleHalf()
    {

        int middle = (i - 1) / 2;
        int starting = (i - 1) / 4;

        for (int j = starting; j > 0; j--)
        {
            swap(arr[middle - j], arr[middle + j]);
        }
    }

    bool operator<(const Stack &other)
    {
        if (this->i > other.i)
        {
            return true;
        }
        if (this->i < other.i)
        {
            return false;
        }

        else if (this->i == other.i)
        {
            int fsum = 0;
            int Ssum = 0;
            for (int j = 0; j < i; j++)
            {
                fsum += this->arr[j];
                Ssum += other.arr[j];
            }
            if (fsum > Ssum)
            {
                return true;
            }
            else if (fsum < Ssum)
            {
                return false;
            }
        }

        if (i == 0)
        {
            return false;
        }

        return arr[i - 1] < other.arr[other.i - 1];
    }

    Stack(const Stack &other)
    {
        capacity = other.capacity;
        i = other.i;
        arr = new int[capacity];
        for (int j = 0; j < i; j++)
        {
            arr[j] = other.arr[j];
        }
    }


    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            delete[] arr;
            capacity = other.capacity;
            i = other.i;
            arr = new int[capacity];
            for (int j = 0; j < i; j++)
            {
                arr[j] = other.arr[j];
            }
        }
        return *this;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    cout << s.toString();
    cout << endl;
    cout << "This is Peek of Array: ";
    cout << s.peek();
    cout << endl;
    cout << "This is size of array: ";
    cout << s.getSize();
    cout << endl;
    s.reverseMiddleHalf();
    cout << endl;
    cout << s.toString() << endl;

    Stack A(3);
    Stack B(2);
    Stack C(3);
    Stack D(2);
    Stack E(3);

    A.push(10);
    A.push(20);
    A.push(30);

    cout << A.toString();
    cout << endl;
    B.push(5);
    B.push(15);

    cout << B.toString() << endl;
    C.push(5);
    C.push(10);
    C.push(20);
    cout << C.toString() << endl;

    D.push(10);
    D.push(25);
    cout << D.toString() << endl;

    E.push(10);
    E.push(20);
    E.push(30);
    cout << E.toString() << endl;

    vector<Stack> stacks = {A, B, C, D, E};

    sort(stacks.begin(), stacks.end());

    for (int j = 0; j < stacks.size(); j++)
    {
        cout << stacks[j].toString() << endl;
    }

    return 0;
}