#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string brand;
    double dailyRate;

public:
    Vehicle(const string &regNo, const string &brand, double dailyRate)
        : registrationNo(regNo), brand(brand), dailyRate(dailyRate) {}

    virtual void displayVehicle() const
    {
        cout << "Registration No : " << registrationNo << endl;
        cout << "Brand           : " << brand << endl;
        cout << "Daily Rate      : $" << dailyRate << "/day" << endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(const string &regNo, const string &brand, double dailyRate, int numDoors)
        : Vehicle(regNo, brand, dailyRate), numDoors(numDoors) {}

    void displayVehicle() const override
    {
        Vehicle::displayVehicle();
        cout << "Number of Doors : " << numDoors << endl;
    }

    double getDailyRate() const { return dailyRate; }
};

class ElectricCar : public Car
{
private:
    double batteryCapacity;

public:
    ElectricCar(const string &regNo, const string &brand, double dailyRate,
                int numDoors, double batteryCapacity)
        : Car(regNo, brand, dailyRate, numDoors), batteryCapacity(batteryCapacity) {}

    void displayVehicle() const override
    {
        Car::displayVehicle();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    double calculateRentalCost(int days) const
    {
        return getDailyRate() * 0.85 * days;
    }
};

// WHY registrationNo can't be accessed directly here:
// Truck uses private inheritance, so every member from Vehicle —
// including protected ones like registrationNo — becomes private
// inside Truck. That means even Truck's own functions can't touch it.
// Fix: call Vehicle::displayVehicle() instead, which runs in Vehicle's
// own scope where registrationNo is accessible.
class Truck : private Vehicle
{
private:
    double payloadCapacity;

public:
    Truck(const string &regNo, const string &brand, double dailyRate, double payloadCapacity)
        : Vehicle(regNo, brand, dailyRate), payloadCapacity(payloadCapacity) {}

    void displayTruck() const
    {
        Vehicle::displayVehicle();
        cout << "Payload Capacity: " << payloadCapacity << " tonnes" << endl;
    }
};

int main()
{
    cout << "========== CAR ==========\n";
    Car myCar("ABC-1234", "Toyota Corolla", 50.00, 4);
    myCar.displayVehicle();

    cout << "\n======= ELECTRIC CAR =======\n";
    ElectricCar myEV("EV-5678", "Tesla Model 3", 80.00, 4, 75.0);
    myEV.displayVehicle();
    cout << "7-Day Rental Cost (15% green discount): $" << myEV.calculateRentalCost(7) << endl;

    cout << "\n========== TRUCK ==========\n";
    Truck myTruck("TRK-9999", "Volvo FH16", 150.00, 20.0);
    myTruck.displayTruck();

    return 0;
}