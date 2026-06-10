#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{

    vector<double> data = {4, 8, 15, 16, 23, 42, 7, 3, 19, 11};

    double sum = accumulate(data.begin(), data.end(), 0.0);

    double mean = sum / data.size();

    double minimum = accumulate(data.begin(), data.end(), data[0], [](double current, double next)
                                {

        if(next < current){
        return (next);
        }
    return current; });

    double maximum = accumulate(data.begin(), data.end(), data[0], [](double current, double next)
                                {
            if(next > current){
                return next;
            }
        return current; });

    double sumOfSquares = accumulate(data.begin(), data.end(), 0.0, [](double current, double next)
                                     { return current + next * next; });

    double variance = accumulate(data.begin(), data.end(), 0.0, [mean](double sum, double x)
                                 { return sum + (x - mean) * (x - mean); }) /
                      data.size();

    double add = reduce(data.begin(), data.end(), 0.0);
    double m = reduce(data.begin(), data.end(), 0.0)/data.size();

    cout << "Sum (accumulator): " << sum << endl;
    cout << "Sum (reduce): " << add << endl;
    cout << "Mean (accumulator): " << mean << endl;
    cout << "Mean (reduce): " << m << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Sum of Squares: " << sumOfSquares << endl;
    cout << "Variance: " << variance << endl;

    return 0;
}