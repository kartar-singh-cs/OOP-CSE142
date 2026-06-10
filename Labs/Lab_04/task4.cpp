#include <iostream>
using namespace std;

class StockPrice
{
private:
    struct Record
    {
        int timestamp;
        int price;
    };

    Record arr[1000];
    int size;
    int latestTimestamp;

public:
    // Constructor
    StockPrice()
    {
        size = 0;
        latestTimestamp = 0;
    }

    void update(int timestamp, int price)
    {

        for (int i = 0; i < size; i++)
        {
            if (arr[i].timestamp == timestamp)
            {
                arr[i].price = price; // replace price
                if (timestamp > latestTimestamp)
                    latestTimestamp = timestamp;
                return;
            }
        }

        arr[size].timestamp = timestamp;
        arr[size].price = price;
        size++;

        if (timestamp > latestTimestamp)
            latestTimestamp = timestamp;
    }

    int current()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].timestamp == latestTimestamp)
                return arr[i].price;
        }
        return -1;
    }

    int maximum()
    {
        int maxPrice = arr[0].price;
        for (int i = 1; i < size; i++)
        {
            if (arr[i].price > maxPrice)
                maxPrice = arr[i].price;
        }
        return maxPrice;
    }

    int minimum()
    {
        int minPrice = arr[0].price;
        for (int i = 1; i < size; i++)
        {
            if (arr[i].price < minPrice)
                minPrice = arr[i].price;
        }
        return minPrice;
    }
};

int main()
{

    StockPrice stockPrice;

    stockPrice.update(1, 10);
    stockPrice.update(2, 5);

    cout << stockPrice.current() << endl;
    cout << stockPrice.maximum() << endl;

    stockPrice.update(1, 3);
    cout << stockPrice.maximum() << endl;

    stockPrice.update(4, 2);
    cout << stockPrice.minimum() << endl;

    return 0;
}
