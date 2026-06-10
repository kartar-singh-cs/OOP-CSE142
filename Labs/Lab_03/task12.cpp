#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{

public:
    char data;
    Node *next;
};

class Palindrome
{

public:
    Node *front;
    Node *rear;
    Node *head;

    Palindrome()
    {
        front = NULL;
        rear = NULL;
        head = NULL;
    }

    void pushCharacter(char ch)
    {
        Node *n_node = new Node;
        n_node->data = ch;
        n_node->next = head;
        head = n_node;
    }

    void enqueueCharacter(char ch)
    {

        Node *n_node = new Node;
        n_node->data = ch;
        n_node->next = NULL;

        if (front == NULL)
        {
            front = n_node;
            rear = front;
            return;
        }

        rear->next = n_node;
        rear = n_node;
    }

    char popCharacter()
    {
        char ch = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return ch;
    }

    char dequeueCharacter()
    {
        char ch = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        return ch;
    }
};

int main()
{
    Palindrome p1;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        p1.enqueueCharacter(s[i]);
        p1.pushCharacter(s[i]);
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (p1.dequeueCharacter() != p1.popCharacter())
        {
            cout << "It is not Palindorme!" << endl;
            return 0;
        }
    }

    cout << "Congratulations! It is PLaindrome!" << endl;

    return 0;
}