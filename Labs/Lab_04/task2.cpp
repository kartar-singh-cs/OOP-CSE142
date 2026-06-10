#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class queue
{
    Node *front;
    Node *rear;

public:
    queue()
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

        if (front == NULL)
        {
            cout << "Sorry ,there is no element to delete." << endl;
            return 0;
        }
        int val = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        return val;
    }

    void moveNthRear(int n)
    {
        Node *temp = front;
        // if (n == 1 && front != NULL)
        // {

        //     rear->next = front;
        //     front = front->next;
        //     return;
        // }

        for (int i = 0; i < n - 2; i++)
        {
            if(temp -> next == NULL)
            return;

            temp = temp->next;
        }

        Node *helper = temp->next;
        temp->next = temp->next->next;
        rear->next = helper;
        rear = helper;
        rear -> next = NULL;
    }

    void traverse()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main()
{

    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout<<"Before Moving: ";
    q1.traverse();
    cout<<endl;
    cout<<"After Moving: ";
    q1.moveNthRear(2);
    q1.traverse();

    return 0;
}