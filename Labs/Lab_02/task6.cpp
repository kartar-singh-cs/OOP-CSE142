#include <iostream>
#include <string>
using namespace std;

class OxygenTank
{

public:
    int oxygenLevel = 200;

    void consume(int units)
    {
        oxygenLevel = (oxygenLevel - units);
        return;
    }

    void refill(){

        oxygenLevel = 200;
    }
};

int main()
{
    OxygenTank o1;
    int consume;
    int option;

    while(true){

        cout<<"1. Consumed Oxygen: "<<endl;
        cout<<"2. Exit"<<endl<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter the option: ";
        cin>>option;

        
        switch (option){

            case 1:
            cout<<"Enter the amount you had consumed: ";
            cin>>consume;
            o1.consume(consume);
            cout<<"\nLevel of Oxygen is: "<< o1.oxygenLevel<<endl<<endl;
            if(o1.oxygenLevel < 100){
                o1.refill();
            }
            break;

            case 2:
            break;
        }
        if(option == 2){
            cout<<"The level of oxygen you are left with: "<<o1.oxygenLevel<<endl;
            break;
        }
    }

    return 0;
}