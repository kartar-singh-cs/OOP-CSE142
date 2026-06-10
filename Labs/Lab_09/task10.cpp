#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename F, typename G>
auto compose(F f, G g)
{
    return [f, g](auto x)
    { return f(g(x)); };
}

template <typename F, typename G, typename... Rest>
auto compose(F f, G g, Rest... rest)
{
    return compose(f, compose(g, rest...));
}

int main()
{
    auto negate_ = [](int x)
    { return x * -1; };
    auto addTen = [](int x)
    { return x + 10; };
    auto square = [](int x)
    { return x * x; };

    auto squareAfterAdd = compose(square, addTen);

    cout << "Two-function compose — square(addTen(x)):" << endl;
    for (int i = 1; i <= 5; ++i)
        cout << "  x=" << i << "  ->  " << squareAfterAdd(i) << endl;

    auto pipeline = compose(square, addTen, negate_);

    cout << "\nThree-function compose — square(addTen(negate(x))):" << endl;
    for (int i = 1; i <= 5; ++i)
        cout << "  x=" << i << "  ->  " << pipeline(i) << endl;

    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> output(input.size());

    transform(input.begin(), input.end(), output.begin(), pipeline);

    cout << "\nPipeline via std::transform:" << endl;
    cout << "  Input :";
    for (int v : input)
        cout << "  " << v;
    cout << "\n  Output:";
    for (int v : output)
        cout << "  " << v;
    cout << endl;

    function<long long(int)> fib;
    fib = [&fib](int n) -> long long
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    };

    cout << "\nFibonacci from n=0 to n=10:" << endl;
    for (int n = 0; n <= 10; ++n)
        cout << "  fib(" << n << ") = " << fib(n) << endl;

    return 0;
}