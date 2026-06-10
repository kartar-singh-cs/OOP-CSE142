#include <iostream>
#include <string>
using namespace std;

class Vehicle
{

protected:
    double rentperday;
    string vehicleType;

public:
    Vehicle(double r, string type)
    {
        rentperday = r;
        vehicleType = type;
    }

    virtual double rent(int days) = 0;

    virtual void displayInfo()
    {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Rental Price per day: " << rentperday << endl;
    }

    void rent(int days, string method)
    {

        double total = rent(days);

        cout << "Total rent: " << total << endl;

        if (method == "Cash")
        {
            cout << "Paid by Cash." << endl;
        }
        else if (method == "Online" || method == "online")
        {
            cout << "Paid By online." << endl;
        }

        else if (method == "Credit Card")
        {
            cout << "Paid by Credit Card." << endl;
        }
        else
        {
            cout << "Invalid payment method." << endl;
        }
    }

    void rent(int days, double amount)
    {
        double total = rent(days);

        cout << "Total Rental Cost: " << total << endl;

        if (total <= amount)
        {
            cout << "Payment Successful." << endl;
            cout << "Change Returned." << endl;
        }

        else
        {
            cout << "Alert!\nPlease pay remaining amount: " << total - amount << endl;
        }
    }

    bool operator+(Vehicle &other)
    {
        double car1 = this->rent(1);
        double car2 = other.rent(1);
        if (car1 < car2)
        {
            cout << this->vehicleType << " is cheaper." << endl;
            return true;
        }
        else
        {
            cout << other.vehicleType << " is cheaper." << endl;
            return false;
        }
    }
};

class Car : public Vehicle
{
    bool Aircondition;
    int seats;

public:
    Car(double r, bool ac, int s) : Vehicle(r, "Car")
    {

        Aircondition = ac;
        seats = s;
    }

    double rent(int days) override
    {
        double total = rentperday * days;
        if (days > 7)
        {
            total = total * 0.9;
        }

        return total;
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Aircondition: " << (Aircondition ? "Yes" : "NO") << endl;
        cout << "Number of Seats in Car: " << seats << endl;
    }
};

class Bike : public Vehicle
{

    bool helmetIncluded;
    string fuelType;

public:
    Bike(double r, bool i, string f) : Vehicle(r, "Bike")
    {
        helmetIncluded = i;
        fuelType = f;
    }

    double rent(int days) override
    {
        double total = days * rentperday;
        if (days > 3)
        {
            total = 0.95 * total;
        }

        return total;
    }

    void displayInfo() override
    {

        Vehicle::displayInfo();
        cout << "Helmet Included: " << (helmetIncluded ? "Yes" : "No") << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Truck : public Vehicle
{

    string cargo;
    int nofWheels;

public:
    Truck(double r, string c, int n) : Vehicle(r, "Truck")
    {
        cargo = c;
        nofWheels = n;
    }

    double rent(int days) override
    {
        double total = days * rentperday;
        if (days > 5)
        {
            total = 1.2 * total;
        }

        return total;
    }

    void displayInfo() override
    {
        cout << "------- Truck Parking --------" << endl;
        Vehicle ::displayInfo();
        cout << "Cargo type: " << cargo << endl;
        cout << "Number of wheels: " << nofWheels << endl;
    }
};

int main()
{
    Car c1(5000, true, 5);
    Bike b1(4000, false, "Petrol");
    Truck t1(10000, "Heavy", 8);

    cout << "======= Car Information ======" << endl;
    c1.displayInfo();
    c1.Vehicle::rent(8, "Cash");

    cout << endl;
    cout << "++++++ Bike Information ++++++" << endl;
    b1.displayInfo();
    b1.Vehicle::rent(4, 3000);

    cout << endl;
    cout << "Lets Compare which is Cheaper." << endl;
    c1 + b1;

    return 0;
}