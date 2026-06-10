#include <iostream>
#include <string>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
};

class Queue
{

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node *n_node = new Node;
        n_node->data = value;
        n_node->next = NULL;

        if (front == NULL)
        {
            front = n_node;
            rear = front;
            return;
        }
        else
        {
            rear->next = n_node;
            rear = n_node;
        }
    }

    int dequeue()
    {

        int temp = front->data;
        if (front == NULL)
        {
            cout << "There is no element!" << endl;
            return 0;
        }
        else if (front == rear)
        {

            delete front;
            rear = NULL;
            return temp;
        }
        else
        {

            Node *farig = front;
            front = front->next;
            delete farig;
            return temp;
        }
    }

    void moveNthFront(int n)
    {

        Node *temp = front;
        for (int i = 0; i < n - 2; i++)
        {

            temp = temp->next;
        }
        Node *helper = temp->next;
        temp->next = temp->next->next;
        helper->next = front;
        front = helper;
    }

    void traverse()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(11);
    q1.enqueue(34);
    q1.enqueue(67);
    q1.enqueue(43);
    q1.enqueue(55);

    cout << "Without movement: ";
    q1.traverse();
    cout << endl;
    q1.moveNthFront(3);
    cout << "After Moving: ";
    q1.traverse();

    return 0;
}