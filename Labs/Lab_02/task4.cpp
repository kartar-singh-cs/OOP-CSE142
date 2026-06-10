#include <iostream>
#include <string>
using namespace std;

class User
{

    int age;
    string name;
    char *profileBio;
    int *sessionID;

public:
    // Parameterized Constructor
    User(int a, string n,const char *p, int s)
    {
        age = a;
        name = n;

        int len = 0;
        while (p[len] != '\0')
        {
            len++;
        }

        profileBio = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            profileBio[i] = p[i];
        }

        profileBio[len] = '\0';

        sessionID = new int;
        *sessionID = s;
    }

    // Copy Constructor
    User(const User &others)
    {
        name = others.name;
        age = others.age;

        int len = 0;

        while (others.profileBio[len] != '\0')
        {

            len++;
        }

        profileBio = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            profileBio[i] = others.profileBio[i];
        }

        profileBio[len] = '\0';

        sessionID = others.sessionID;
    }

    ~User()
    {
        delete[] profileBio;
    }

    void display() const
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Bio: " << profileBio << endl
             << "Session ID: " << *sessionID << endl;
    }

    void setter(int index, char ch)
    {
        profileBio[index] = ch;
    }

    void setSession(int value)
    {
        *sessionID = value;
    }
};

int main()
{
    User u1(22, "Ali", "Computer Science", 32431);
    User u2 = u1;
    cout << "Original User: "<<endl;
    u1.display();
    cout << endl;
    cout << "Copy User: "<<endl;
    u2.display();
    cout << endl;

    u2.setter(0,'W');
    u2.setSession(32422);

    cout<<"After Copying User 1: "<<endl;
    u1.display();
    cout<<endl;

    cout<<"Then User 2: "<<endl;
    u2.display();

    return 0;
}