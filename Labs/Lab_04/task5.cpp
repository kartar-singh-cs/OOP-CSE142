#include <iostream>
#include <string>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
};

class CircularDriveThru
{

    Node *front;
    Node *rear;
    int counter = 0;
    int spots = 0;

public:
    CircularDriveThru()
    {
    }
    CircularDriveThru(int k)
    {
        front = NULL;
        rear = NULL;
        spots = k;
    }

    bool parkCar(int number)
    {
        if (counter < spots)
        {
            Node *n_node = new Node;
            n_node->data = number;
            n_node->next = NULL;

            if (front == NULL)
            {
                front = n_node;
                rear = front;
                rear->next = front;
                counter++;
                return true;
            }

            else
            {
                rear->next = n_node;
                rear = n_node;
                rear->next = front;
                counter++;
                return true;
            }
        }
        else
        {
            cout << "Sorry there is no space." << endl;
            return false;
        }
    }

    int carLeaves()
    {
        Node *temp = front;
        int helper = temp->data;
        if (front == NULL)
        {
            cout << "There is no element to delete." << endl;
            return 0;
        }

        else if (front == rear)
        {
            delete front;
            rear = NULL;
            front = NULL;
            counter--;
            return helper;
        }

        else
        {
            front = front->next;
            rear->next = front;
            delete temp;

            counter--;
            return helper;
        }
    }

    int frontCar()
    {
        if (front == NULL)
        {
            cout << "There is no any car." << endl;
            return -1;
        }
        int temp = front->data;

        return temp;
    }

    int rearCar()
    {
        if (front == NULL)
        {
            cout << "There is no any car." << endl;
            return -1;
        }
        int temp = rear->data;

        return temp;
    }

    bool isEmpty()
    {
        if (counter == 0)
        {
            cout << "The parking is empty." << endl;
            return true;
        }
        else
        {
            cout << "The parking is not empty." << endl;
            return false;
        }
    }

    bool isFull()
    {
        if (counter == spots)
        {
            cout << "Parking is Full." << endl;
            return true;
        }
        else
        {
            cout << "It is not full." << endl;
            return false;
        }
    }

    void traverse()
    {
        if (front == NULL)
        {
            cout << "There is nothing to print." << endl;
            return;
        }
        Node *temp = front;
        for (int i = 0; i < counter; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    CircularDriveThru c1(5);
    c1.parkCar(101);
    c1.parkCar(102);
    c1.parkCar(103);
    c1.parkCar(104);
    c1.parkCar(105);
    c1.parkCar(106);
    c1.traverse();
    cout << endl;
    cout << "Car Leaves: " << c1.carLeaves() << endl;
    c1.traverse();
    cout << endl;
    c1.parkCar(101);
    cout << "Added one more car: ";
    c1.traverse();
    cout<<endl;
    cout<<"The Car on front: "<<c1.frontCar()<<endl;
    cout<<"The Car on last: "<<c1.rearCar()<<endl;


    return 0;
}