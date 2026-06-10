#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

Node *modify(Node *head, char array[], int size)
{

    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (i == size)
        {
            return 0;
        }

        else if (temp->data == array[i])
        {
            Node *demand = temp;
            temp = temp->next;
            head = temp;
            delete demand;
            i++;
        }

        else if(array[i] == temp->next->data)
        {
            Node *helper = temp->next;
            temp->next = temp->next->next;
            delete helper;
            temp = temp->next;
            i++;
        }

       
    }
     return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    char array[3] = {'A', 'C', 'E'};
    Node *head = new Node{'A', NULL};
    Node *second = new Node{'B', NULL};
    Node *third = new Node{'C', NULL};
    Node *fourth = new Node{'D', NULL};
    Node *fifth = new Node{'E', NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Real Linked List: ";
    traverse(head);
    cout << endl;
    head = modify(head, array, 3);
    cout << "Modified Linked List: ";
    traverse(head);
    return 0;
}