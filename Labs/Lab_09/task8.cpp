#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

struct Order
{

    int id;
    string customer;
    double amount;
    bool isPaid;
};

function<Order()> f = [](vector<Order> orders)
{
    vector<Order> filteredOrder;
    copy_if(orders.begin(), orders.end(), back_inserter(filteredOrder), [](const Order &o)
            {
                if (o.amount > 100 && o.isPaid == true)
                {
                    return true;
                }
                return false; });
    return filteredOrder;
};

auto mapDiscount = [](vector<Order> filteredOrder)
{
    vector<double> discounted;
    transform(filteredOrder.begin(), filteredOrder.end(), back_inserter(discounted), [](Order &o)
              { return (o.amount * 0.9); });
    return discounted;
};

auto sum = [](const vector<double> &v)
{
    return reduce(v.begin(), v.end(), 0.0);
};

int main()
{

    vector<Order> orders = {
        {101, "Ali", 2500.50, true},
        {102, "Sara", 1200.00, false},
        {103, "Ahmed", 5400.75, true},
        {104, "Zainab", 80.00, true},
        {105, "Hassan", 3000.00, false},
        {106, "Ayesha", 150.25, true},
        {107, "Usman", 99.99, false},
        {108, "Fatima", 4200.00, true}};

    auto filtered = filter(orders);

    auto discounted = mapDiscount(filtered);

    double totalRevenue = sum(discounted);

    int count = filtered.size();

    cout << "Qualifying Orders: " << count << endl;
    cout << "Total Discounted Revenue: " << totalRevenue << endl;

    return 0;
}