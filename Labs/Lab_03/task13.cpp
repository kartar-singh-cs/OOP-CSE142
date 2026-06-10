#include <iostream>
#include <string>
using namespace std;

class Node
{

public:
    string data;
    Node *next;
};
class Stack
{

public:
    int top;
    Node *head;

    Stack()
    {
        head = NULL;
        top = -1;
    }

    void push(string url)
    {
        Node *n_node = new Node;
        n_node->data = url;
        n_node->next = NULL;
        if (head == NULL)
        {

            head = n_node;
            head->data = url;
            head->next = NULL;
            top++;
        }
        else
        {

            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n_node;
            n_node->next = NULL;
            top++;
        }
    }

    void pop()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "There is no data!" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        top--;
    }

    void peek()
    {

        if (head == NULL)
        {
            cout << "Sorry there is no data to see!" << endl;
            return;
        }

        Node *temp = head;
        // Traverse to the last node (top of stack)
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "This is the page you're standing on: ";
        cout << temp->data << endl; // Print only the top element
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void clear()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Congratulations! there is no data to remove!" << endl;
            return;
        }

        while (head != NULL)
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
                top--;
            }
            else
            {

                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
                top--;
            }
        }
        cout << "All browsing data is cleared!" << endl;
    }
};

int main()
{

    Stack s1;
    s1.push("news.com");
    s1.push("mail.com");
    s1.push("social.com");
    s1.peek();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.peek();
    s1.clear();
    s1.peek();
    return 0;
}