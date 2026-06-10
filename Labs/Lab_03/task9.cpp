#include <iostream>
#include <string>
using namespace std;

class node
{

public:
    int data;
    node *next;
};

void traverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node* reverse(node *head)
{
    node *previous = NULL;
    node *current = head;
    node *Next = NULL;

    while (current != NULL)
    {
        Next = current->next;
        current->next = previous;
        previous = current;
        current = Next;
    }

    return previous;
}

int main()
{

    node *head = new node{10, NULL};
    node *second = new node{20, NULL};
    node *third = new node{30, NULL};

    head->next = second;
    second->next = third;

    cout<<"Original List: "<<endl;
    traverse(head);
    cout<<endl;
    head = reverse(head);
    cout<<"Reversed List: "<<endl;
    traverse(head);

    return 0;
}