#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class Stack
{

    vector<T> data;

public:
    Stack() {}

    void push(T value)
    {
        data.push_back(value);
    }

    T pop()
    {

        if (data.empty())
        {
          throw runtime_error("Stack is empty");
            
        }

        T farig = data.back();
        data.pop_back();
        return farig;
    }

    T top()
    {

        if (data.empty())
        {
           throw runtime_error("Stack is empty");
            
        }

        return data.back();
    }
};

int main()
{
    Stack<int>s1;
    s1.push(2);
    s1.push(4);
    s1.push(3);

    cout<<"Top: "<<s1.pop()<<endl;
    cout<<"Popped: "<<s1.pop()<<endl;
    cout<<"Top after pop: "<<s1.top()<<endl;


    return 0;
}