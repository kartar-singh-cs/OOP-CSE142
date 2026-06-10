#include <iostream>
#include <string>
#include<vector>
using namespace std;

template <class T>
class Queue
{

    vector<T> data;

public:
    void enqueue(T val)
    {
        data.push_back(val);
    }

    T dequeue()
    {

        if (data.empty())
        {
            throw runtime_error("Queue is empty");
        }
        T helper = data.front();
        data.erase(data.begin());
        return helper;
    }

    T top()
    {
        if (data.empty())
        {
            throw runtime_error("Queue is empty");
        }
        return data.front();
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.top() << endl;        // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    cout << "Front now: " << q.top() << endl;    // 30

    return 0;
}