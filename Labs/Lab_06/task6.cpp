#include <iostream>
#include <string>
using namespace std;

class HosplitalStaff
{

protected:
    int ID;
    string name;

public:
    HosplitalStaff(string n, int I)
    {
        name = n;
        ID = I;
    }
    string getRole()
    {

        return "Hospital Staff";
    }
};

class Doctor : public HosplitalStaff
{

private:
    string specialisation;

public:
    Doctor(string n, int I, string s) : HosplitalStaff(n, I)
    {
        specialisation = s;
    }
    string getRole()
    {

        return "Doctor";
    }

    void prescribe(string pName)
    {
        cout << "Dr: " << name << " prescribed medication to " << pName << endl;
    }
};

class Nurse : public HosplitalStaff
{

private:
    string ward;

public:
    Nurse(string n, int I, string w) : HosplitalStaff(n, I)
    {
        ward = w;
    }
    string getRole()
    {
        return "Nurse";
    }
    void assist(string doctorName)
    {
        cout << "Nurse " << name << " assisted by " << doctorName << endl;
    }
};

class Administrator : protected HosplitalStaff
{

private:
    string officeLocation;

public:
    Administrator(string n, int I, string o) : HosplitalStaff(n, I)
    {
        officeLocation = o;
    }

    void SchedulaAppointment()
    {
        cout << "Your appointment has Confirmed." << endl;
    }

    // Explanation
    // you cant call getRole from Adminstrator class because you have protected inheritance it so you cant access it in main
    // you can access it in class so that's why beacuse of protected inheritance
};
int main()
{
    Doctor d1("Kartar Singh", 32431, "Philanthropist");
    Nurse n1("Sagar Kataria", 32422, "Warden");

    cout << d1.getRole() << endl;
    d1.prescribe("Sahij");

    cout << endl;

    cout << n1.getRole() << endl;
    n1.assist("Kartar Singh");

    cout << endl;
    Administrator a1("Ahsan Bhai", 32456, "Karachi");
    a1.SchedulaAppointment();
    // a1.getRole();

        return 0;
}