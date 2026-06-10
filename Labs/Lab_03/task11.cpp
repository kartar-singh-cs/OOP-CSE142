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
void recursive(node *head)
{
    if (head == NULL)
    {
        return;
    }

    recursive(head->next);
    cout << head->data << " ";
}
int main()
{

    node *head = new node{10, NULL};
    node *second = new node{20, NULL};
    node *third = new node{30, NULL};

    head->next = second;
    second->next = third;

    traverse(head);
    cout << endl;
    recursive(head);

    return 0;
}