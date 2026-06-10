#include <iostream>
#include <string>
using namespace std;

static int counter = 0;

class Player;

class Node
{
public:
    Player *data;
    Node *next;
};

class Player
{

private:
    int ID;
    string name;
    int level;
    string type;
    int arrivalOrder;

public:
    Player()
    {
        ID = 0;
        name = "";
        level = 0;
        type = "";
        arrivalOrder = 0;
    }

    Player(string n, int i, int l, string t)
    {
        ID = i;
        name = n;
        level = l;
        type = t;
        arrivalOrder = ++counter;
    }

    int getID()
    {
        return ID;
    }

    string getName()
    {
        return name;
    }

    int getLevel()
    {
        return level;
    }

    string getType()
    {
        return type;
    }

    int getarrivalOrder()
    {
        return arrivalOrder;
    }

    void levelSetter(int l)
    {
        level = l;
    }
};

class NormalQueue
{
private:
    Node *head;
    Node *last;

public:
    NormalQueue()
    {
        head = NULL;
        last = NULL;
    }

    void enqueue(Player *data)
    {

        Node *n_node = new Node;
        n_node->data = data;
        n_node->next = NULL;

        if (head == NULL)
        {
            head = n_node;
            last = n_node;
            return;
        }

        else
        {
            last->next = n_node;
            last = n_node;
        }
    }

    Player *dequeue()
    {
        Player *val;
        if (head == NULL)
        {
            cout << "No Player" << endl;
            return NULL;
        }

        else if (head == last)
        {
            val = head->data;
            delete head;
            head = NULL;
            last = NULL;
            return val;
        }

        else
        {
            val = head->data;
            Node *helper = head;
            head = head->next;
            delete helper;
            return val;
        }
    }
    void remove(int id)
    {

        if (head == NULL)
        {
            return;
        }

        if (head->data->getID() == id)
        {
            Node *temp = head;
            head = head->next;
            cout << "Removed: " << temp->data->getName() << endl;
            if (head == NULL)
            {
                last = NULL;
            }
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != NULL)
        {
            if (current->next->data->getID() == id)
            {
                 cout << "Removed: " << current->next->data->getName() << endl;
                Node *helper = current->next;
                current->next = current->next->next;

                if (helper == last)
                {
                    last = current;
                }

                delete helper;
                return;
            }

            current = current->next;
        }
    }
};

class priorityQueue
{
    Node *head;
    Node *tail;

public:
    priorityQueue()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }

        return false;
    }

    // Insertion NODE
    void insert(Player *p)
    {
        Node *n_node = new Node;
        n_node->data = p;
        n_node->next = NULL;

        // Empty list
        if (head == NULL)
        {
            head = n_node;
            tail = head;
            return;
        }

        else if (p->getLevel() > head->data->getLevel())
        {
            n_node->next = head;
            head = n_node;
        }

        else if (p->getLevel() == head->data->getLevel())
        {
            if (p->getarrivalOrder() < head->data->getarrivalOrder())
            {
                n_node->next = head;
                head = n_node;
                return;
            }

            else
            {
                Node *helper = head->next;
                head->next = n_node;
                n_node->next = helper;
                return;
            }
        }

        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {

                if (temp->next->data->getLevel() < p->getLevel())
                {
                    Node *helper = temp->next;
                    temp->next = n_node;
                    n_node->next = helper;
                    return;
                }

                else if (temp->next != NULL && temp->next->data->getLevel() == p->getLevel())
                {
                    if (temp->next->data->getarrivalOrder() > p->getarrivalOrder())
                    {
                        Node *helper = temp->next;
                        temp->next = n_node;
                        n_node->next = helper;
                        return;
                    }
                    else
                    {
                        n_node->next = temp->next;
                        temp->next = n_node;

                        return;
                    }
                }

                else
                {
                    temp = temp->next;
                }
            }
            temp->next = n_node;
            tail = n_node;
        }
    }

    Player *extract()
    {
        if (head == NULL)
        {
            cout << "No Player." << endl;
            return NULL;
        }

        Node *helper = head;
        Player *p = head->data;

        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete helper;
        return p;
    }

    void remove(int id)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No Player." << endl;
            return;
        }

        if (head->data->getID() == id)
        {
            temp = head;
            head = head->next;

            if (head == NULL)
            {
                tail = NULL;
            }
            delete temp;
            return;
        }

        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->data->getID() == id)
                {
                    Node *helper = temp->next;
                    temp->next = temp->next->next;
                    if (helper == tail)
                    {
                        tail = temp;
                    }
                    delete helper;
                    return;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }

    // LEVEL Booster Function
    void boost(int id, int x)
    {
        if (head == NULL)
        {
            cout << "No Player." << endl;
            return;
        }

        Node *temp = head;
        Player *playerboost = NULL;
        while (temp != NULL)
        {
            if (temp->data->getID() == id)
            {
                playerboost = temp->data;
                break;
            }
            temp = temp->next;
        }
        if (playerboost == NULL)
        {
            cout << "Not found" << endl;
            return;
        }

        remove(id);

        playerboost->levelSetter(playerboost->getLevel() + x);
        insert(playerboost);
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data->getLevel() << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    NormalQueue nq;
    priorityQueue pq;

    Player p1[4] = {Player("Kartar Singh", 32431, 1, "VIP"),
                    Player("Sagar Kataria", 32422, 1, "Normal"),
                    Player("Sahij Sachwani", 32459, 1, "VIP"),
                    Player("Jujhar Lund", 32455, 1, "Normal")};
    for (int i = 0; i < 4; i++)
    {
        if (p1[i].getType() == "Normal")
        {
            nq.enqueue(&p1[i]);
        }
        else if (p1[i].getType() == "VIP")
        {
            pq.insert(&p1[i]);
        }
    }

    cout << "This is the top player in Normal list: ";
    Player *temp = nq.dequeue();
    cout << temp->getName() << endl;

    
    nq.remove(32455);

    cout << "This is the top player in Normal list: ";
    temp = nq.dequeue();
    // cout<<temp->getName()<<endl;

    cout<<endl;
    Player *yar = pq.extract();
    cout << "++++++++ VIP PLAYERS ++++++++" << endl;
    cout << "This is TOP VIP player: " << yar->getName() << endl;
    cout << "it has level of: " << yar->getLevel() << endl;

    cout << endl;
    cout << "After removing " << yar->getName() << endl;
    yar = pq.extract();
    cout << "The new top VIP Player is: " << yar->getName() << endl;
    cout << "Without Boosted his level is: " << yar->getLevel() << endl;
    pq.boost(32431, 5);
    cout << "After boosting level: " << endl;
    pq.display();

    return 0;
}