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
    Queue()
    {
        front = NULL;
        last = NULL;
    }

    void placeOrder(string order)
    {
        Node *n_node = new Node;
        n_node->data = order;
        n_node->next = NULL;

        if (front == NULL)
        {
            front = n_node;
            last = front;
            return;
        }

        else if (front == last)
        {
            front->next = n_node;
            last = n_node;
            return;
        }

        last->next = n_node;
        last = n_node;
    }

    void dequeue()
    {

        if (front == NULL)
        {
            cout << "There is no orders." << endl;
            return;
        }

        else if (front == last)
        {
            delete front;
            last = NULL;
            return;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            return;
        }
    }
};

class Stack
{

public:
    Node *head;
    int top;

    Stack()
    {
        head = NULL;
        top = 0;
    }

    void push(string order)
    {
        Node *n_node = new Node;
        n_node->data = order;
        n_node->next = NULL;

        if (head == NULL)
        {
            head = n_node;
            top++;
            return;
        }

        else
        {
            n_node->next = head;
            head = n_node;
            top++;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "No completd orders." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void peek()
    {
        if (head == NULL)
        {
            cout << "No completd orders." << endl;
            return;
        }
        cout << "Top Order: " << head->data << endl;
        return;
    }
};

class Restaurant
{

public:
    string n;
    Queue kitchen;
    Stack completed;

    void input()
    {
        cout << "Enter a Dish: ";
        cin >> n;
        kitchen.placeOrder(n);
    }

    void processOrder()
    {
        if (kitchen.front == NULL)
        {
            cout << "No orders." << endl;
            return;
        }
        string order = kitchen.front->data;
        kitchen.dequeue();

        completed.push(order);
    }

    void getNextDelivery()
    {
        completed.peek();
        completed.pop();
    }
};

int main()
{
    Restaurant rs;
    rs.input();
    rs.input();

    rs.processOrder();
    rs.processOrder();

    rs.getNextDelivery();
    cout << "After Delievering: " << endl;
    rs.getNextDelivery();
    return 0;
}