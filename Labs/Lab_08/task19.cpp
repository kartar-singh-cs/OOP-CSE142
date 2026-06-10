#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void show() {
        cout << "Singleton instance is active." << endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() {
        cout << "Singleton created." << endl;
    }
};

int main()
{
    Singleton& s1 = Singleton::getInstance();
    s1.show();

    Singleton& s2 = Singleton::getInstance();
    s2.show();

    if (&s1 == &s2)
        cout << "Same instance." << endl;

    return 0;
}
