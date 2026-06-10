#include <iostream>
using namespace std;

template <class T1>
class Node
{
    T1 data;
    Node<T1> *next;

public:
    Node() : next(nullptr) {}

    Node(T1 value) : data(value), next(nullptr) {}

    Node<T1> *head = nullptr; // head as class member

    void insert(T1 value)
    {
        Node<T1> *new_node = new Node<T1>(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node<T1> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void remove()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T1> *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void traverse()
    {
        Node<T1> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Node<int> n1;
    n1.insert(5);
    n1.insert(6);
    n1.insert(7);

    cout << "Linked List: ";
    n1.traverse(); // 5 6 7

    n1.remove();

    cout << "After remove: ";
    n1.traverse(); // 5 6

    return 0;
}