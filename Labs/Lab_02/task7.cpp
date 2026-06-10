#include <iostream>
#include <string>
using namespace std;

class Player
{

    string firstname;
    string secondname;
    double monthlyContract;

public:
    Player(string f, string s, double m)
    {
        firstname = f;
        secondname = s;
        if (m < 0)
        {
            monthlyContract = 0.0;
        }
        else
        {
            monthlyContract = m;
        }
    }

    void display()
    {
        cout << firstname << " " << secondname << " have yearly earning of: " << monthlyContract << endl;
    }

    int increase()
    {
        monthlyContract = monthlyContract * 1.10;
        return 0;
    }
};

int main()
{

    Player p1("Kartar", "Singh", 10000);
    Player p2("Sagar", "Kataria", 5000);
    p1.display();
    p2.display();
    p1.increase();
    p2.increase();
    cout << "-------------After Increasing-------------" << endl;
    p1.display();
    p2.display();

    return 0;
}