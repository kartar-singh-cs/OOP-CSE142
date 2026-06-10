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
    Node *head;
    int top;
    Stack()
    {
        head = NULL;
        top = 0;
    }

    void push(string other)
    {
        Node *n_node = new Node;
        n_node->data = other;
        n_node->next = NULL;
        if (head == NULL)
        {
            head = n_node;
            top++;
            return;
        }

        n_node->next = head;
        top++;
        head = n_node;
        return;
    }

    string pop()
    {

        if (head == NULL)
        {
            cout << "There is no data." << endl;
            return"";
        }
        string action = head->data;
        Node *temp = head;
        head = head->next;
        top--;
        delete temp;
        return action;
    }

    bool isEmpty()
    {

        if (top == 0)
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

        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        top = 0;
        cout << endl;
    }

    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

class TextEditor
{
public:
    Stack undo;
    Stack redo;

    TextEditor()
    {
        undo.head = NULL;
        redo.head = NULL;
    }

    void doAction(string action)
    {

        undo.push(action);
        redo.clear();
    }

    void Doundo()
    {

        if (undo.top == 0)
        {
            cout << "Nothing to Do." << endl;
            return;
        }
        else
        {

            string action = undo.pop();
            redo.push(action);
        }
    }

    void Doredo()
    {
        if (redo.top == 0)
        {
            cout << "There is no data." << endl;
        }

        else
        {
            string action = redo.pop();
            undo.push(action);
        }
    }

    bool canUndo()
    {

        if (undo.top == 0)
        {
            return false;
        }
        return true;
    }

    bool canRedo()
    {

        if (redo.top == 0)
        {
            return false;
        }
        return true;
    }

    void clearAll()
    {
        while (canRedo())
        {
            redo.pop();
        }

        while (canUndo())
        {
            undo.pop();
        }

        cout << "Both are clear now." << endl;
    }

    void traversing()
    {
        cout << "===== Undo Traversing ======" << endl;
        undo.traverse();
        cout << endl;
        cout << "++++++ Redo Traversing ++++++" << endl;
        redo.traverse();
    }
};

int main()
{

    TextEditor t1;
    t1.doAction("Hello World");
    t1.doAction("Earth");
    t1.doAction("World");
    t1.doAction("Tare Zameen Par");
    t1.traversing();
    cout << endl;
    t1.Doundo();
    t1.Doundo();
    t1.traversing();
    cout<<endl;
    cout<<endl;
    if(t1.canRedo()){
        cout<<"It is not clear."<<endl;
    }
    cout<<endl;
    if(t1.canUndo()){
        cout<<"It is not clear."<<endl;
    }
    cout<<endl;
    cout<<"After Clearing: "<<endl;
    t1.clearAll();
    t1.traversing();

    return 0;
}