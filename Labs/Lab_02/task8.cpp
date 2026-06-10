#include <iostream>
#include <string>
using namespace std;

class Artifact
{

    string name;
    string registrationID;
    string discoverer;
    string origin;

public:
    Artifact(string n, string r, string d, string o)
    {
        this->name = n;
        this->registrationID = r;
        this->discoverer = d;
        this->origin = o;
    }

    string getname()
    {
        return name;
    }

    string getregistrationID()
    {
        return registrationID;
    }

    string getdiscoverer()
    {
        return discoverer;
    }

    string getorigin()
    {
        return origin;
    }

    string getArtifactInfo()
    {
        return "Artifact Name: " + name +
               "\nRegistration ID: " + registrationID +
               "\nDiscoverer name: " + discoverer +
               "\nOrigin Location: " + origin + "\n";
    }
};

int main()
{
    Artifact a[5] = {
        Artifact("Crystal Skull", "A101", "Dr. Evans", "South America"),
        Artifact("Golden Chalice", "A102", "Sir William", "England"),
        Artifact("Dragon Scroll", "A103", "Master Li", "China"),
        Artifact("Pharaoh Mask", "A104", "Howard Carter", "Egypt"),
        Artifact("Viking Axe", "A105", "Erikson", "Norway")};

    for (int i = 0; i < 5; i++)
    {
        cout << "------ Artifact " << i + 1 << " ------" << endl;
        cout << a[i].getArtifactInfo() << endl;
    }

    return 0;
}