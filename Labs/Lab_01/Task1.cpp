// // // #include <iostream>
// // // #include <string>
// // // using namespace std;

// // // class Employee
// // // {

// // //     string name;
// // //     string lastname;
// // //     double salary;

// // // public:
// // //     Employee(string n, string l, double s)
// // //     {
// // //         name = n;
// // //         lastname = l;
// // //         if (s < 0)
// // //         {
// // //             salary = 0.0;
// // //         }
// // //         else
// // //         {
// // //             salary = s;
// // //         }
// // //     }

// // //     int getYearlySalary()
// // //     {

// // //         return salary * 12;
// // //     }

// // //     void giveRaise()
// // //     {

// // //         salary = salary * 1.10;
// // //     }

// // //     void display()
// // //     {
// // //         cout << name << " " << lastname << endl;
// // //     }
// // // };

// // // int main()
// // // {

// // //     Employee e1("Kartar", "Singh", 25000);
// // //     Employee e2("Ali", "singh", 20000);

// // //     cout << " yearly salary before raise " << endl;
// // //     e1.display();
// // //     cout << "Yearly Salary " << e1.getYearlySalary() << endl;

// // //     e2.display();
// // //     cout << "Yearly Salary " << e2.getYearlySalary() << endl
// // //          << endl;

// // //     e1.giveRaise();
// // //     e2.giveRaise();
// // //     cout << "After Raising Salaries " << endl;
// // //     e1.display();
// // //     cout << "Yearly Salary " << e1.getYearlySalary() << endl;

// // //     e2.display();
// // //     cout << "Yearly Salary " << e2.getYearlySalary() << endl;

// // //     return 0;
// // // }

// // #include <iostream>
// // #include <string>
// // using namespace std;

// // class Glass
// // {
// // public:
// //     int LiquidLevel = 200;

// //     void Drink(int milliliters)
// //     {
// //         LiquidLevel -= milliliters;

// //         if (LiquidLevel < 0)
// //         {
// //             LiquidLevel = 0;
// //         }
// //     }

// //     void Refill()
// //     {
// //         LiquidLevel = 200;
// //         cout << "Glass refilled to 200ml" << endl;
// //     }
// // };

// // int main()
// // {
// //     Glass g1;
// //     int amount;
// //     while (true)
// //     {

// //         cout << "\nCurrent liquid level: " << g1.LiquidLevel << " ml\n";
// //         cout << "Enter amount to add in the glass and -1 to exit: ";
// //         cin >> amount;

// //         if (amount == -1)
// //         {
// //             break;
// //         }
// //         else
// //         {
// //             g1.Drink(amount);
// //         }

// //         if (g1.LiquidLevel < 100)
// //         {
// //             g1.Refill();
// //         }
// //     }

// //     cout << "Program Terminated" << endl;

// //     return 0;
// // }

// #include <iostream>
// #include <string>
// using namespace std;

// class Book
// {

// private:
//     string name;
//     string ISBN;
//     string author;
//     string year;

// public:
//     Book(string n, string i, string a, string y)
//     {

//         name = n;
//         ISBN = i;
//         author = a;
//         year = y;
//     }

//     string getBookInfo()
//     {
//         return "Book Name: " + name + "\nISBN number: " + ISBN + " \nAuthor Name:  " + author + "\nPublished Yaer: " + year;
//     }
// };

// int main()
// {
//     Book books[5] = {
//         Book("C++ Programming", "111-AAA", "Bjarne Stroustrup", "Pearson"),
//         Book("Clean Code", "222-BBB", "Robert C. Martin", "Prentice Hall"),
//         Book("Data Structures", "333-CCC", "Mark Weiss", "McGraw Hill"),
//         Book("OOP Concepts", "444-DDD", "Herbert Schildt", "Oracle Press"),
//         Book("Algorithms", "555-EEE", "CLRS", "MIT Press")

//     };

//     for (int i = 0; i < 5; i++)
//     {
//         cout << "\nBook " << i + 1 << " Information:\n";
//         cout << books[i].getBookInfo() << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

class Polynomial
{

    int a;
    int b;
    int c;
    friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);
    friend bool operator==(const Polynomial &p1, const Polynomial &p2);

public:
    Polynomial()
    {
        a = 1;
        b = 1;
        c = 1;
    }

    Polynomial(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    string format()
    {

        return to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
    }

    int eval(int x)
    {
        return a * x * x + b * x + c;
    }

     int& operator[](int index)
    {
        if (index == 0)
            return a;
        else if (index == 1)
            return b;
        else if (index == 2)
            return c;
        else
        {
            cout << "Invalid index! Program terminated.\n";
            exit(1);
        }
    }

   


};

Polynomial operator+(const Polynomial &p1,const Polynomial &p2)
{
    Polynomial p3;
    p3.a = p1.a + p2.a;
    p3.b = p1.b + p2.b;
    p3.c = p1.c + p2.c;

    return p3;
}

bool operator==(const Polynomial& p1,const Polynomial& p2){
return (p1.a == p2.a && p1.b == p2.b && p1.c == p2.c);
        
    }




int main()
{
    Polynomial p1(4,6,8);
    Polynomial p2(8,16,24);
    




    return 0;
}