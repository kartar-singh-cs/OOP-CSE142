#include <iostream>
#include <vector>
using namespace std;

class MemoryPool {
public:
    MemoryPool(size_t blockSize, size_t poolSize)
        : blockSize(blockSize), poolSize(poolSize) {
        pool = new char[blockSize * poolSize];
        for (size_t i = 0; i < poolSize; i++)
            freeList.push_back(pool + i * blockSize);
    }

    ~MemoryPool() {
        delete[] pool;
    }

    void* allocate() {
        if (freeList.empty()) {
            cout << "Pool exhausted!" << endl;
            return nullptr;
        }
        void* ptr = freeList.back();
        freeList.pop_back();
        return ptr;
    }

    void deallocate(void* ptr) {
        freeList.push_back(static_cast<char*>(ptr));
    }

private:
    size_t blockSize;
    size_t poolSize;
    char* pool;
    vector<void*> freeList;
};

int main()
{
    MemoryPool mp(sizeof(int), 5);

    int* a = static_cast<int*>(mp.allocate());
    int* b = static_cast<int*>(mp.allocate());

    *a = 10;
    *b = 20;

    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;

    mp.deallocate(a);
    mp.deallocate(b);

    cout << "Memory returned to pool." << endl;

    return 0;
}
