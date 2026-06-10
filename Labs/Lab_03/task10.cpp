#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LLStack
{

public:
    Node *head;

    LLStack()
    {
        head = NULL;
    }

    void push(int d)
    {
        Node *n_node = new Node;
        n_node->data = d;
        n_node->next = NULL;

        if (head == NULL)
        {
            head = n_node;
            return;
        }

        n_node->next = head;
        head = n_node;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "There is no element to remove!" << endl;
            return;
        }

        else
        {
            cout << "We are going to remove this data: " << head->data << endl;
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
    }

    LLStack(const LLStack &s)
    {
        Node *current = s.head;
        Node *previous = NULL;
        head = NULL;
        while (current != NULL)
        {
            Node *n_node = new Node;
            n_node->data = current->data;
            n_node->next = NULL;

            if (head == NULL)
            {
                head = n_node;
            }
            else
            {
                previous->next = n_node;
            }
            previous = n_node;
            current = current->next;
        }
    }

    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    LLStack t1;
    t1.push(1);
    t1.push(2);
    t1.push(3);
    t1.push(4);
    t1.push(5);

    t1.traverse();
    cout << endl;

    LLStack s{t1};

    cout << "Copied Stack: " << endl;
    s.traverse();
    
    cout<<endl<<endl;
    t1.push(7);
    cout<<"After Updation: "<<endl;
    t1.traverse();
    cout << endl;

    cout<<"Copied One: "<<endl;
    s.traverse();


    return 0;
}