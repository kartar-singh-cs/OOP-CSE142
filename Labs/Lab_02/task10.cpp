#include <iostream>
#include <string>
using namespace std;

class FootballTeam
{

private:
    string name;
    int goals;
    int points;

    friend FootballTeam operator+(const FootballTeam &t1, const FootballTeam &t2);

public:
    FootballTeam()
    {
        name = "Unknown";
        goals = 0;
        points = 0;
    }

    FootballTeam(string n, int g, int p)
    {

        name = n;
        goals = g;
        points = p;
    }

    void addgoals(int goals)
    {
        this->goals += goals;
    }

    void addpoints(int points)
    {
        this->points += points;
    }

    void setname(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void display(){
        cout<<"Team Name: "<<name<<endl<<"Goals: "<<goals<<endl<<"Points: "<<points<<endl<<endl;
    }

    ~FootballTeam()
    {
        cout << "Team \" " << name << "\" removed from the tournament." << endl;
    }

    void compare(FootballTeam t1, FootballTeam t2)
    {
        if (t1.goals > t2.goals)
        {
            cout << t1.name << " performed better than " << t2.name << endl;
        }

        else if (t1.goals < t2.goals)
        {
            cout << t2.name <<" performed better than "<<t1.name<<endl;
        }

        else{
            cout<<"Both teams are equal"<<endl;
        }
    }
};

FootballTeam operator+(const FootballTeam &t1, const FootballTeam &t2)
{

    FootballTeam t3;
    t3.name = t1.name + " & " + t2.name;
    t3.goals = t1.goals + t2.goals;
    t3.points = t1.points + t2.points;
    return t3;
}

int main()
{
     FootballTeam team1("Dragons", 2, 3);
    FootballTeam team2("Tigers", 1, 1);

    team1.addgoals(1);
    team1.addpoints(3);

    team2.addgoals(2);
    team2.addpoints(3);

    team1.display();
    team2.display();

    
    team1.compare(team1, team2);

    
    FootballTeam combined = team1 + team2;
    cout << "\nCombined Team Stats:" << endl;
    combined.display();


    return 0;
}