#include <iostream>
using namespace std;


class PoweredSystem {
public:
    PoweredSystem() {
        cout << "PoweredSystem constructor"<<endl;
    }

    void powerInfo() {
        cout << "This is a powered system."<<endl;
    }
};


class Vehicle : virtual public PoweredSystem {
public:
    Vehicle() {
        cout << "Vehicle constructor called"<<endl;
    }
};


class Engine : virtual public PoweredSystem {
public:
    Engine() {
        cout << "Engine constructor called"<<endl;
    }
};


class Car : public Vehicle, public Engine {
public:
    Car() {
        cout << "Car constructor called"<<endl;
    }
};

int main() {
    Car c;

  
    c.powerInfo();

    return 0;
}