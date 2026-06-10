#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T, typename PriorityFunc = less<T>>
class PriorityQueue {
public:
    void insert(const T& element) {
        pq.push(element);
    }

    T getHighestPriority() {
        return pq.top();
    }

private:
    priority_queue<T, vector<T>, PriorityFunc> pq;
};

int main()
{
    // Default: max priority (largest number comes first)
    PriorityQueue<int> maxPQ;
    maxPQ.insert(10);
    maxPQ.insert(50);
    maxPQ.insert(30);

    cout << "Highest Priority (default max): " << maxPQ.getHighestPriority() << endl;

    // Custom: min priority (smallest number comes first)
    PriorityQueue<int, greater<int>> minPQ;
    minPQ.insert(10);
    minPQ.insert(50);
    minPQ.insert(30);

    cout << "Highest Priority (custom min): " << minPQ.getHighestPriority() << endl;

    return 0;
}