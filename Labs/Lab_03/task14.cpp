#include <iostream>
#include <string>
using namespace std;

class Node
{

public:
    string data;
    Node *next;
};

class Queue
{

public:
    Node *front;
    Node *last;
    int top;
    Queue()
    {
        front = NULL;
        last = NULL;
        top = 0;
    }

    void enqueue(string job)
    {

        Node *n_node = new Node;
        n_node->data = job;
        n_node->next = NULL;

        if (front == NULL)
        {
            front = n_node;
            last = front;
            top++;
        }

        else
        {

            last->next = n_node;
            last = n_node;
            top++;
        }
    }

    void dequeue()
    {
        if (front == NULL && last == NULL)
        {
            cout << "There is no data!" << endl;
            return;
        }

        else if (front == last)
        {
            delete front;
            last = NULL;
            front == NULL;
            top--;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            top--;
        }
    }

    void peek()
    {
        cout << "This is at the top Job: " << front->data << endl;
        cout << "This is at the last: " << last->data << endl;
    }

    bool isEmpty()
    {
        if (top == 0)
        {
            cout << "There is no data!" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void remove(string jobId)
    {
        Node *temp = front;
        if (front == NULL)
        {
            cout << "Sorry,first add Jobs." << endl;
            return;
        }

        if (front->data == jobId && front != last)
        {
            temp = front;
            front = front->next;
            delete temp;
            top--;

            if (front == NULL)
            {
                last == NULL;
            }
            return;
        }

        while (temp->next != NULL)
        {

            if (temp->next->data == jobId)
            {
                Node *faltu;
                faltu = temp->next;
                temp->next = temp->next->next;

                if (faltu == last)
                {
                    last = temp;
                }
                delete faltu;
                top--;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Queue q1;
    q1.enqueue("Manager");
    q1.enqueue("Maker");
    q1.enqueue("printer");
    q1.dequeue();
    q1.peek();

    return 0;
}